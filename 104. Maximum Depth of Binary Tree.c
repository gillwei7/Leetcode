/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 #if 1
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    // 暴力解法: 直接把所有的數字總和相加
    int* resultSize = (int*) malloc(sizeof(int) * 2);
    for(int l = 0;l < numsSize - 1; l++) {
        for(int r = l+1;r < numsSize;r++) {
            if(target == nums[l] + nums[r]) {
                resultSize[0] = l;
                resultSize[1] = r;
                *returnSize = 2;
                return resultSize;
            }
        }
    }
    *returnSize = 2;
    return resultSize;
}
// 使用 Hash Map
// 但在 C 標準裡面不能簡單地 call function, 要自己建立 Hash function
#else
// Define a hash table entry
typedef struct {
    int key;   // The number
    int value; // The index of the number in the array
} HashEntry;

// Function to initialize the hash table
void initHashTable(HashEntry* hashTable, int size) {
    for (int i = 0; i < size; i++) {
        hashTable[i].key = INT_MIN; // Special value to indicate an empty slot
        hashTable[i].value = -1;    // No index associated initially
    }
}

// Hash function to map a key to an index
int hash(int key, int size) {
    return (key % size + size) % size; // Ensure non-negative indices
}

// Insert into the hash table
void insert(HashEntry* hashTable, int size, int key, int value) {
    int idx = hash(key, size);
    while (hashTable[idx].value != -1) { // Linear probing to handle collisions
        idx = (idx + 1) % size;
    }
    hashTable[idx].key = key;
    hashTable[idx].value = value;
}

// Search in the hash table
int search(HashEntry* hashTable, int size, int key) {
    int idx = hash(key, size);
    while (hashTable[idx].value != -1) {
        if (hashTable[idx].key == key) {
            return hashTable[idx].value;
        }
        idx = (idx + 1) % size;
    }
    return -1; // Key not found
}

// Two Sum function
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    // Allocate hash table
    int hashTableSize = numsSize * 2; // Larger size to reduce collisions
    HashEntry* hashTable = (HashEntry*)malloc(hashTableSize * sizeof(HashEntry));
    initHashTable(hashTable, hashTableSize);

    // Result array
    int* result = (int*)malloc(2 * sizeof(int));

    // Iterate through the array
    for (int i = 0; i < numsSize; i++) {
        int complement = target - nums[i];
        int complementIndex = search(hashTable, hashTableSize, complement);
        if (complementIndex != -1) {
            // Found the solution
            result[0] = complementIndex;
            result[1] = i;
            *returnSize = 2;
            free(hashTable); // Free hash table memory
            return result;
        }
        // Insert the current number and its index into the hash table
        insert(hashTable, hashTableSize, nums[i], i);
    }

    // Clean up and return NULL if no solution found (won't happen as per constraints)
    free(hashTable);
    *returnSize = 0;
    return NULL;
}
#endif

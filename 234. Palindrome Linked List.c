/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool isPalindrome(struct ListNode* head) {
    // 首先, 一樣需要檢查如果 head 為 NULL, 或 head 只有一個值
    if (!head || !head->next) return true;

    // 為了要找出 list 最後面和中間, 使用快慢指標
    struct ListNode* slow = head;
    struct ListNode* fast = head;
    while(fast && fast->next) {
        fast = fast->next->next;
        slow = slow->next;
    }

    // 因為要比較
    // 從 slow pointer 之後的後半部分 list 做反轉
    struct ListNode* prev = NULL;
    struct ListNode* temp;
    struct ListNode* cur = slow;
    while(cur) {
        temp = cur->next;
        cur->next = prev;
        prev = cur;
        cur = temp;
    }

    // 反轉後得到兩個 singly link list, 比較兩個 list 
    // 使用左右指標往中間做比較, 因為此時 cur 為 NULL, prev 剛好是最後一個指標
    struct ListNode* left = head;
    struct ListNode* right = prev;
    while(right) {
        if(left->val != right->val) 
            return false;
        left = left->next;
        right = right->next;
    }

    return true;
}

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t result = 0;
        for (int i = 0; i < 32; i++) {
            int bit = (n >> i) & 1;  // Extract the ith bit
            result |= (bit << (31 - i)); // Place it in the reversed position
        }
        return result;
    }
};
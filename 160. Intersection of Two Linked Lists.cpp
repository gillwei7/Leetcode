/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) return nullptr;

        // Step 1: Find lengths of both lists
        int lenA = 0, lenB = 0;
        ListNode* currA = headA;
        ListNode* currB = headB;

        while (currA) {
            lenA++;
            currA = currA->next;
        }

        while (currB) {
            lenB++;
            currB = currB->next;
        }

        // Step 2: Move head of longer list ahead by the difference in lengths
        currA = headA;
        currB = headB;

        if (lenA > lenB) {
            int diff = lenA - lenB;
            while (diff--) currA = currA->next;
        } else {
            int diff = lenB - lenA;
            while (diff--) currB = currB->next;
        }

        // Step 3: Traverse both lists together until nodes are the same
        while (currA && currB) {
            if (currA == currB) return currA;
            currA = currA->next;
            currB = currB->next;
        }

        return nullptr; // No intersection
    }
};

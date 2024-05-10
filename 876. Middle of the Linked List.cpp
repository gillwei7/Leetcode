/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* end = head;
        int list_count = 0;
        while(end != nullptr) {
            end = end->next;
            list_count++;
        }
        for(int i=0;i<list_count/2;i++) {
            head = head->next;
        }
        return head;
    }
};
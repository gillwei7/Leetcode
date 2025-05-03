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
        ListNode *detectCycle(ListNode *head) {
            if(!head){
                return nullptr;
            }
            ListNode *slow = head;
            ListNode *fast = head;
            while( slow  && fast ) {  
                if(fast->next != NULL){
                    fast = fast->next->next;
                }
                else {
                    return nullptr;
                }
                slow = slow->next;
                if(slow != NULL && fast != NULL && slow == fast)
                    break;
            }
            slow = head;
            while(fast != slow){
                if(fast != NULL && fast->next != NULL){
                    fast = fast->next;
                    slow = slow->next;
                }else{
                    return NULL;
                }
            }
            return fast;
        }
    };
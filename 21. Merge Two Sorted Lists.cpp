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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // 要先創造一個有值的 dummy, 做為head 紀錄保存下來
        // 然後p 本身會跟著list1的p1或 list2的p2
        // 如果沒有用 new ListNode(-1); 而是用 nullptr 的話, 因為不能直接操作 nullptr->next, 
       //  就要每次加新的 Node 進來 list 都要檢查, 變很麻煩
        ListNode *dummy = new ListNode(-1);
        ListNode *p = dummy;
        ListNode *p1 = list1;
        ListNode *p2 = list2;
        while(p1 != nullptr && p2 != nullptr)
        {
            // 比較p1和p2大小, 把比較小的節點接到p指標
            // 這裡不能用p->val = p2->val; 因為當p = p->next之後, p就會變成nullptr, compiler不會過
            // 所以要把p1或p2給 p-> next 
            if(p1->val > p2->val)
            {
                p->next = p2;
                p2 = p2->next;
            }
            else
            {
                p->next = p1;
                p1 = p1->next;
            }
            // p指標本身不斷前進
            p = p->next;
        }
        if( p1 != nullptr )
        {
            p->next = p1;
        }
        if( p2 != nullptr )
        {
            p->next = p2;
        }
        return dummy->next;

    }
};
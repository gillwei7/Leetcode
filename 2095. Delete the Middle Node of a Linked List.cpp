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
    ListNode* deleteMiddle(ListNode* head) {
        // 經典快慢指標題, 快指標一次走兩步, 慢指標一次走一步
        // 快指標走到底時, 剛好慢指標在一半
        // 這邊一定要用一個 dummy Node, 他的 next 指向 head
        // 不然 n = 1 時 slow fast 都等於自己, 也沒有 slow->next 可以刪
        ListNode* prev = new ListNode(0);
        prev->next = head;
        ListNode* slow = prev;
        ListNode* fast = head;
        // 這邊要檢查 fast->next != NULL, 不然操作 fast-> next 的時候會變成在操作 NULL
        // 程式本身會出問題
        // 不然就是要改成 fast->next = fast,
        // if(fast->next != NULL) {fast->next = fast;}
        while(fast != NULL && fast->next != NULL){
            fast = fast->next->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;
        return prev->next;
    }
};
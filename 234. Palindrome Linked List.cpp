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
    bool isPalindrome(ListNode* head) {

        // // 暴力法: 將 list 裡面的放進 arrary, 然後從最左邊和最右邊開始比較
        // vector<int> listArrary;
        // while(head) {
        //     listArrary.push_back(head->val);
        //     head = head->next;
        // }
        // int l = 0, r = listArrary.size()-1;
        // while(l <= r) {
        //     if(listArrary[l] != listArrary[r]) {
        //         return false;
        //     }
        //     l++;
        //     r--;
        // }
        // return true;

        // memory space 只能用O(1), 表示不把 list 裡面的東西儲存起來
        // 用快慢指標, 讓快指標指到最底
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        
        // 反轉 linked list 的後半段 
        // slow 修改成 current 比較好理解, 從 current 開始反轉
        // 再來每一次要讓 current->next, 所以需要把原本的 current->next 存起來
        // 讓 previous 取代 current->next
        // 把 previous 往前一個(current 給 previous)
        // 把 current 也往前一個(儲存起來的 current-> next 現在可以給 current)
        // 這邊如果還是不理解的話, 記得畫圖, 按照順序多走幾遍

        ListNode* current = slow;
        ListNode* temp; // 用來儲存原本的 slow->next
        ListNode* previous = nullptr; // 原本 slow 在的地方變成尾巴, 最後要是 nullptr
        
        while(current) {
            temp = current->next; // 先把原本的 current->next 存起來, 最後要變成 current
            current->next = previous; // 讓原本的 previous 取代原本的 current->next
            previous = current;       // 把 previous 往前一個 
            current = temp;       // 把 current 往前一個
        }
        ListNode* left = head;
        ListNode* right = previous;
        while(right) {
            if(left->val != right->val) {
                return false;
            }
            left = left->next;
            right = right->next;
        }
        return true;

    }
};

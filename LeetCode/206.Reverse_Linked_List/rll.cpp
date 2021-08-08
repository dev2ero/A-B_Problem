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
    ListNode* reverseList(ListNode* head) {
        
        ListNode *prev = nullptr, *curt = head, *temp;
        while(curt != nullptr) {
            temp = curt->next;
            curt->next = prev;
            prev = curt;
            curt = temp;
        }
        
        return prev;
    }
};

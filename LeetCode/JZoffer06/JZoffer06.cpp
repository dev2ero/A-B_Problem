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
    vector<int> reversePrint(ListNode* head) {
        vector<int> temp;
        while(head != nullptr) {
            temp.push_back(head->val);
            head = head->next;
        }

        vector<int> result;
        while(!temp.empty()){
            int i = temp.back();
            temp.pop_back();
            result.push_back(i);
        }

        return result;
    }
};

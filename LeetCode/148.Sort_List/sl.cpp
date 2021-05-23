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
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next)    return head;
        ListNode *fast = head, *slow = head;
        ListNode *middle = findMiddle(head);
        return mergeSort(sortList(head), sortList(middle));
    }

    ListNode* findMiddle(ListNode *head) {
        ListNode *cut, *fast = head, *slow = head;
        while(fast && fast->next) {
            cut = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        cut->next = nullptr;
        return slow;
    }

    ListNode* mergeSort(ListNode *head, ListNode *mid) {
        ListNode *sorted = new ListNode(INT_MAX);
        ListNode *pos = sorted;
        while(head && mid) {
            if(head->val < mid->val)
            {
                pos -> next = head;
                head = head -> next;
            }
            else
            {
                pos -> next = mid;
                mid = mid -> next;
            }
            pos = pos -> next;
        }
        pos->next = head == nullptr ? mid : head;
        return sorted->next;
    }
};

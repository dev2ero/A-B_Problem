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
        ListNode *pA = headA, *pB = headB;
        
        if(pA == NULL || pB == NULL)    return NULL;

        while(1) {
            if(pA == pB)    return pA;
            if(pA->next == NULL && pB->next == NULL) {
                return NULL;
            } else if(pA->next == NULL) {
                pA = headB;
                pB = pB->next;
            } else if(pB->next == NULL) {
                pA = pA->next;
                pB = headA;
            } else {
                pA = pA->next;
                pB = pB->next;
            }
        }
    }
};

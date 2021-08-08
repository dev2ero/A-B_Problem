#include<iostream>
#include<assert.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* result = new ListNode(0);

        ListNode* p = result;
        int carray = 0;
        while( l1->next != NULL || l2->next != NULL ) {
            p->val = (l1->val+l2->val+carray)%10;
            carray = (l1->val+l2->val+carray)/10;
            
            if(l1->next != NULL)    l1 = l1->next;
            else    l1->val = 0;
            if(l2->next != NULL)    l2 = l2->next;
            else    l2->val = 0;

            p->next = new ListNode(0);
            p = p->next;
        }        

        p->val = (l1->val+l2->val+carray)%10;
        carray = (l1->val+l2->val+carray)/10;
        if( carray == 1)    p->next = new ListNode(1);

        return result;
    }
};

int main() {
     
}

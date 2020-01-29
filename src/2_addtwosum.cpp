#include "headers.h"

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head = NULL, *tail = NULL;
        int up = 0;
        ListNode *a = l1,*b = l2;

        while (a != NULL || b != NULL || up != 0) {
            // speed
            if ((a == NULL || b == NULL) && up == 0) {
                if (a != NULL) {
                    tail->next = a;
                    break;
                } else if ( b != NULL) {
                    tail->next = b;
                    break;
                }
            }
            int aVal = a != NULL ? a->val : 0;
            int bVal = b != NULL ? b->val : 0;
            int total = aVal +bVal + up;
            ListNode* tmp = new ListNode(total % 10);
            if (head == NULL) {
                head = tail = tmp;
            } else {
                tail->next = tmp;
                tail = tmp;
            }
            up = total / 10;
            a = a != NULL ? a->next : NULL;
            b = b != NULL ? b->next : NULL;
        }

        return head;
    }
};

ListNode* make(int* nums, int count) 
{
    ListNode* head = NULL, *tail = NULL;
    for (int i =0; i < count; i++) {
        
        ListNode* tmp = new ListNode(nums[i]);
        if (head == NULL) {
            head = tail = tmp;
        } else {
            tail->next = tmp;
            tail = tmp;
        }
    }
    return head;
}

int main(int argc, char **argv)
{
    int a[] = {2,4,3};
    int b[] = {5,6,4};
    ListNode* aList = make(a, 3);
    ListNode* bList = make(b, 3);
    Solution solution;
    ListNode* resList = solution.addTwoNumbers(aList, bList);
    ListNode* tmp = resList;
    while (tmp != NULL)
    {
        cout << tmp->val;
    }
    
}



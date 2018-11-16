#include <iostream>
/**
 * Definition for singly-linked list.
 **/
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
    ~ListNode() { delete next; }
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *thisDigit = nullptr;
        if(l1 || l2)
        {
            const int addend1 = l1 ? l1->val : 0;
            const int addend2 = l2 ? l2->val : 0;
            int sum = addend1 + addend2;
            int carry = sum >= 10 ? 1 : 0;

            // If the sum is two digits long
            if(carry)
            {
                sum -= 10;

                // add the carry to the next digit
                if(l1->next)
                {
                    l1->next->val++;
                }
                // add another digit if we were at the end
                else
                {
                    l1->next = new ListNode(1);
                }
            }

            thisDigit = new ListNode(sum);
            thisDigit->next = addTwoNumbers(l1 ? l1->next : nullptr, l2 ? l2->next : nullptr);
        }
        return thisDigit;
    }
};

int main(int argc, char *argv[])
{
    ListNode *l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(6);

    ListNode *l2 = new ListNode(5);
    l2->next = new ListNode(3);
    l2->next->next = new ListNode(4);

    // (2 -> 4 -> 6) + (5 -> 3 -> 4) = (7 -> 7 -> 0 -> 1)

    Solution s;
    ListNode *result = s.addTwoNumbers(l1, l2);

    delete l1;
    delete l2;

    return 0;
}

// Problem Link - https://leetcode.com/problems/add-two-numbers/

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        if (l1 == NULL)
            return l2;
        if (l2 == NULL)
            return l1;

        int carry = 0, sum = 0;
        ListNode *head = l1, *prev;

        while (l1 && l2)
        {
            if (l1 && l2)
            {
                sum = (l1->val + l2->val + carry);
                carry = sum / 10;

                l1->val = sum % 10;

                prev = l1;
                l1 = l1->next;
                l2 = l2->next;
            }
        }

        while (l1)
        {
            sum = l1->val + carry;
            l1->val = sum % 10;
            carry = sum / 10;
            prev = l1;
            l1 = l1->next;
        }

        prev->next = l2;

        while (l2)
        {
            sum = l2->val + carry;
            l2->val = sum % 10;
            carry = sum / 10;
            prev = l2;
            l2 = l2->next;
        }

        while (carry)
        {
            prev->next = new ListNode(carry);
            prev = prev->next;
            carry /= 10;
        }

        return head;
    }
};

// Time Complexity - O(n)
// Space Complexity - O(1)
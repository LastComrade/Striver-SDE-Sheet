// Problem Link - https://leetcode.com/problems/merge-two-sorted-lists

class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        if (list1 == NULL)
            return list2;
        if (list2 == NULL)
            return list1;

        ListNode *curr1 = list1, *curr2 = list2, *prev = NULL, *temp;

        while (curr1 && curr2)
        {
            if (curr1->val > curr2->val)
            {
                if (prev)
                    prev->next = curr2;
                prev = curr2;
                curr2 = curr2->next;
            }
            else if (curr1->val < curr2->val)
            {
                if (prev)
                    prev->next = curr1;
                prev = curr1;
                curr1 = curr1->next;
            }
            else
            {
                if (prev)
                    prev->next = curr1;

                prev = curr2;
                temp = curr1->next;
                curr1->next = curr2;
                curr1 = temp;
                curr2 = curr2->next;
            }
        }

        if (curr1)
            prev->next = curr1;
        if (curr2)
            prev->next = curr2;

        return list1->val <= list2->val ? list1 : list2;
    }
};

// Time Complexity - O(n)
// Space Complexity - O(1)
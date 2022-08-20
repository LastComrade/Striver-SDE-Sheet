// Problem Link - https://leetcode.com/problems/intersection-of-two-linked-lists

class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        int len1 = 0;
        int len2 = 0;
        ListNode *temp = headA;

        while (temp)
        {
            len1++;
            temp = temp->next;
        }

        temp = headB;
        while (temp)
        {
            len2++;
            temp = temp->next;
        }

        if (len1 > len2)
        {
            int diff = len1 - len2;
            while (diff--)
            {
                headA = headA->next;
            }
        }
        else if (len2 > len1)
        {
            int diff = len2 - len1;

            while (diff--)
            {
                headB = headB->next;
            }
        }

        while (headA != headB)
        {
            headA = headA->next;
            headB = headB->next;
        }

        return headA;
    }
};

// Time Complexity - O(m + n)
// Space Complexity - O(1)
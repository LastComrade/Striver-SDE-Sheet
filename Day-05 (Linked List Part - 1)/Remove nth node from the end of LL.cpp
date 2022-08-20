// Problem Link - https://leetcode.com/problems/remove-nth-node-from-end-of-list/

class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        if (head == NULL)
            return NULL;

        ListNode *newHead = new ListNode(-1), *fast = newHead, *slow = newHead;
        slow->next = head;
        fast->next = head;

        for (int i = 0; i < n; i++)
            fast = fast->next;

        while (fast->next)
        {
            slow = slow->next;
            fast = fast->next;
        }

        ListNode *temp = slow->next;

        slow->next = slow->next->next;
        delete temp;

        return newHead->next;
        ;
    }
};

// Time Complexity - O(n)
// Space Complexity - O(1)
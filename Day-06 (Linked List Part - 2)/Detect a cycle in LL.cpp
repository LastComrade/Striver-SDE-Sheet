// Problem Link - https://leetcode.com/problems/linked-list-cycle/

class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        if (head == NULL)
            return 0;
        ListNode *slow = head, *fast = head;

        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast)
                return 1;
        }

        return 0;
    }
};

// Time Complexity - O(n)
// Space Complexity - O(1)
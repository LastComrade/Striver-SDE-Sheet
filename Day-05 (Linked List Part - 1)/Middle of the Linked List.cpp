// Problem Link - https://leetcode.com/problems/middle-of-the-linked-list/

class Solution
{
public:
    ListNode *middleNode(ListNode *head)
    {
        ListNode *slow, *fast;
        slow = head;
        fast = head;

        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }
};

// Time Complexity - O(n)
// Space Complexity - O(1)
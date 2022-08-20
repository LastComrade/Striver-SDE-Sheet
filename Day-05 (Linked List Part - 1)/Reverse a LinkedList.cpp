// Problem Link - https://leetcode.com/problems/reverse-linked-list/

// Iterative Solution
class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        ListNode *nextNode, *prevNode = NULL;

        while (head)
        {
            nextNode = head->next;
            head->next = prevNode;
            prevNode = head;
            head = nextNode;
        }

        return prevNode;
    }
};

// Time Complexity - O(n)
// Space Complexity - O(1)

// Recursive Solution
class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
            return head;

        ListNode *node = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;

        return node;
    }
};

// Time Complexity - O(n)
// Space Complexity - O(n) - Recursion Stack ()
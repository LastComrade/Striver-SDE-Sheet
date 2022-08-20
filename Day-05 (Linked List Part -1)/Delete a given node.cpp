// Problem Link - https://leetcode.com/problems/delete-node-in-a-linked-list/

class Solution
{
public:
    void deleteNode(ListNode *node)
    {
        ListNode *nextNode = node->next;

        // Changing the address stored into the
        *node = *nextNode;

        delete nextNode;
    }
};

// Time Complexity - O(1)
// Space Complexity - O(1)
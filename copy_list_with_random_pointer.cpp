/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    // Time: O(n)
    // Space: O(n)
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (head == NULL) {
            return NULL;
        }
        unordered_map<RandomListNode*, RandomListNode*> mapping;
        for (RandomListNode *node = head; node != NULL; node = node->next) {
            RandomListNode *n = new RandomListNode(node->label);
            mapping[node] = n;
        }
        for (RandomListNode *node = head; node != NULL; node = node->next) {
            RandomListNode *n = mapping[node];
            n->next = mapping[node->next];
            n->random = mapping[node->random];
        }
        return mapping[head];
    }
};

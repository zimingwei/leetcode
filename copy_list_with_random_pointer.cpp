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
    // Space: O(1)
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (head == NULL) {
            return NULL;
        }
        
        for (RandomListNode *curr = head; curr != NULL; ) {
            RandomListNode *node = new RandomListNode(curr->label);
            node->next = curr->next;
            curr->next = node;
            curr = node->next;
        }
        for (RandomListNode *curr = head; curr != NULL; 
                curr = curr->next->next) {
            if (curr->random != NULL) {
                curr->next->random = curr->random->next;
            }
        }
        RandomListNode helper(0);
        for (RandomListNode *curr = head, *newCurr = &helper;
                curr != NULL; ) {
            newCurr->next = curr->next;
            newCurr = newCurr->next;
            curr->next = curr->next->next;
            curr = curr->next;
        }
        return helper.next;
    }
};

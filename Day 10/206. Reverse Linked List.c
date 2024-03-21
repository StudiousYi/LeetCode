/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* prev = NULL;
    struct ListNode* cur = head;
    
    if(head == NULL || head->next == NULL) {
        return head;
    }
    while(cur != NULL) {
        struct ListNode* next = cur->next;
        cur->next = prev;

        prev = cur;
        cur = next;
    }

    return prev;
}
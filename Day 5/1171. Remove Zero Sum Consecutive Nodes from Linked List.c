/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

//incomplete solution
struct ListNode* removeZeroSumSublists(struct ListNode* head) {

    while(head != NULL && head->val == 0) { //get rid of 0 if they exist at the start of linked list
        head = head->next;
    }

    struct ListNode* pre = NULL;
    struct ListNode* cur = head;

    while(cur != NULL) {                //iterate the linked list once
        struct ListNode* innerCur = cur;
        int innerSum = 0;
        while(innerCur != NULL) {       //for each node, it will iterate from itself to the last node once as well
            innerSum += innerCur->val;
            if(innerSum == 0) {         //when consecutive node has sum of 0
                if(pre != NULL) {
                    pre->next = innerCur->next;                    
                }
                else {
                    head = innerCur->next;
                }
                break;
            }
            innerCur = innerCur->next;
        }
        pre = cur;
        cur = cur->next;
    }

    while(head != NULL && head->val == 0) { //get rid of 0 if they exist at the start of linked list after operation
        head = head->next;
    }
    return head;
}
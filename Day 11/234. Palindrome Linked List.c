/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool isPalindrome(struct ListNode* head) {
    int nodeCount = 0;
    struct ListNode* countPtr = head;
    struct ListNode* firstHalf;
    struct ListNode* secondHalf;
    struct ListNode* prev = NULL;
    struct ListNode* cur = head;
    struct ListNode* next;

    while(countPtr != NULL) {
        nodeCount++;
        countPtr = countPtr->next;
    }
    //printf("no. of node is %d\n",nodeCount);

    if(nodeCount == 1) {
        return true;
    }

    if(nodeCount % 2 == 0) {
        //printf("even\n");
        next = cur->next;
        for(int i = 0; i < nodeCount/2 - 1; i++) {
            cur->next = prev;
            prev = cur;
            cur = next;
            next = cur->next;
        }
        cur->next = prev;
        firstHalf = cur;
        secondHalf = next;
    }
    else {
        //printf("odd\n");
        next = cur->next;
        for(int i = 0; i < nodeCount/2 - 1; i++) {
            cur->next = prev;
            prev = cur;
            cur = next;
            next = cur->next;
        }
        cur->next = prev;
        firstHalf = cur;
        secondHalf = next->next;
    }
    while(firstHalf != NULL && secondHalf != NULL) {
        //printf("%d and %d\n",firstHalf->val, secondHalf->val);
        if(firstHalf->val != secondHalf->val){
            return false;
        }
        firstHalf = firstHalf->next;
        secondHalf = secondHalf->next;
    }
    return true;
}
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void reorderList(struct ListNode* head) {
    struct ListNode* nodeCount = head;
    struct ListNode* firstHalf;
    struct ListNode* firstHalfLastNode = head;
    struct ListNode* secondHalf;
    struct ListNode* prev;
    struct ListNode* secondHalfnext;
    struct ListNode* firstHalfNext;
    int nodeNum = 0;

    //count number of nodes
    while(nodeCount != NULL) {
        nodeNum++;
        nodeCount = nodeCount->next;
    }
    //printf("Number of node is %d\n",nodeNum);
    if(nodeNum < 3) {
        return;
    }

    //split 1st half and 2nd half
    if(nodeNum % 2 == 0) {  //even number of nodes
        //printf("Even\n");
        for(int i = 0; i < nodeNum/2 - 1; i++) {
            firstHalfLastNode = firstHalfLastNode->next;
        }
        secondHalf = firstHalfLastNode->next;
        firstHalfLastNode->next = NULL;

    }
    else {                  //odd number of nodes
        //printf("Odd\n");
        for(int i = 0; i < nodeNum/2; i++) {
            firstHalfLastNode = firstHalfLastNode->next;
        }
        secondHalf = firstHalfLastNode->next;
        firstHalfLastNode->next = NULL;
    }

    //reverse 2nd half
    prev = NULL;
    secondHalfnext = secondHalf->next;
    while(secondHalf != NULL) {
        secondHalf->next = prev;
        prev = secondHalf;
        secondHalf = secondHalfnext;
        if(secondHalf != NULL) {
            secondHalfnext = secondHalf->next;
        }
    }
    secondHalf = prev;
    firstHalf = head;

    // //print 1st half LL
    // while(firstHalf != NULL) {
    //     printf("%d ",firstHalf->val);
    //     firstHalf = firstHalf->next;
    // }
    // printf("\n");
    // //print 2nd half LL
    // while(secondHalf != NULL) {
    //     printf("%d ",secondHalf->val);
    //     secondHalf = secondHalf->next;
    // }
    // printf("\n");

    //reorder the 2 half LL
    firstHalfNext = firstHalf->next;
    secondHalfnext = secondHalf->next;
    while(firstHalf != NULL && secondHalf != NULL) {
        // firstHalfNext = firstHalf->next;
        // secondHalfnext = secondHalf->next;
        firstHalf->next = secondHalf;
        secondHalf->next = firstHalfNext;
        firstHalf = firstHalfNext;
        secondHalf = secondHalfnext;
        if(firstHalf != NULL) {
            firstHalfNext = firstHalf->next;
        }
        if(secondHalf != NULL) {
            secondHalfnext = secondHalf->next;
        }
    }
    return;
}
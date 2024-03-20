/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* mergeInBetween(struct ListNode* list1, int a, int b, struct ListNode* list2){
    int jump = b - a + 1;
    struct ListNode* main = list1;
    struct ListNode* side = list2;
    for(int i = 0; i < a-1; i++) {
        main = main->next;
    }
    struct ListNode* remover = main->next;
    main->next = list2;
    while(side->next != NULL) {
        side = side->next;
    }
    for(int j = 0; j < jump; j++) {
        remover = remover->next;
    }
    side->next = remover;
    return list1;
}
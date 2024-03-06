//Definition for singly-linked list.
// struct ListNode {
//     int val;
//     struct ListNode *next;
// };

bool hasCycle(struct ListNode *head) {
    // case 1: 0 or 1 node
    if(head == NULL || head->next == NULL){
        return false;
    }
    struct ListNode* movingPtr = head->next;
    head->val = 10001;
    // case 2: last node on LL points back to head/one of the node, return true
    while(movingPtr != NULL){
        if(movingPtr->val == head->val){    //same val, means a cycle is formed
            return true;
        }
        movingPtr->val = 10001;
        movingPtr = movingPtr->next;
    }
    // case 3: last node on LL points to nothing, return false
    return false;
}
//alternate solution
// bool hasCycle(struct ListNode *head) {
//     if(head == NULL) return false;          //0 node
//     if(head->next == NULL) return false;    //1 node
    
//     struct ListNode* fastPtr = head;
//     struct ListNode* slowPtr = head;

//     while(fastPtr != NULL && fastPtr->next != NULL){
//         fastPtr = fastPtr->next->next;
//         slowPtr = slowPtr->next;
//         if(fastPtr == slowPtr) return true;
//     }
//     return false;
//}
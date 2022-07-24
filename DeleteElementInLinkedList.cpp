
/*
 * Complete the 'deleteNode' function below.
 *
 * The function is expected to return an INTEGER_SINGLY_LINKED_LIST.
 * The function accepts following parameters:
 *  1. INTEGER_SINGLY_LINKED_LIST llist
 *  2. INTEGER position
 */

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */

SinglyLinkedListNode* deleteNode(SinglyLinkedListNode* llist, int position) {
    SinglyLinkedListNode* head = llist;
    SinglyLinkedListNode* prev = nullptr;
    SinglyLinkedListNode* cur = head;
    SinglyLinkedListNode* next = cur->next;
    int idx = 0;
    while(idx++ < position)
    {
        prev = cur;
        cur = next;
        next = cur->next;
    }
    delete cur;
    if(prev)
    {
        prev->next = next;
    }
    else {
        head = next;
    }
    return head;
}
/*
 * Complete the 'insertNodeAtPosition' function below.
 *
 * The function is expected to return an INTEGER_SINGLY_LINKED_LIST.
 * The function accepts following parameters:
 *  1. INTEGER_SINGLY_LINKED_LIST llist
 *  2. INTEGER data
 *  3. INTEGER position
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

SinglyLinkedListNode* insertNodeAtPosition(SinglyLinkedListNode* llist, int data, int position) {
    SinglyLinkedListNode* head = llist;
    SinglyLinkedListNode* prev = nullptr;
    SinglyLinkedListNode* next = head;
    int idx = 0;
    while(idx < position)
    {
        prev = next;
        next = next->next;
        idx++;
    }
    SinglyLinkedListNode* new_node = new SinglyLinkedListNode(data);
    new_node->next = next;
    if(prev)
    {
        prev->next = new_node;
    }
    else
    {
        head = new_node;
    }
    return head;
}

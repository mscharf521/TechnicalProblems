
// Complete the has_cycle function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
bool has_cycle(SinglyLinkedListNode* head) {
    std::unordered_map<SinglyLinkedListNode*, bool> visited = {};
    SinglyLinkedListNode* cur = head;
    while(cur)
    {
        if(visited.find(cur) != visited.end())
        {
            return 1;
        }
        visited.insert({cur, true});
        cur = cur->next;
    }
    return 0;
}
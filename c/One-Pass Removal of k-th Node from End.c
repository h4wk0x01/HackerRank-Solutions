SinglyLinkedListNode* removeKthNodeFromEnd(SinglyLinkedListNode* head, int k) {

    /*
    
    head = [5, 6, 7, 8]
    k = 3 (number 5)
    
                     H
           dummy ->  5 -> 6 -> 7 -> 8
            p1 ->
    p2 ->
               
               
            k = 0 (number 2)
                     H
           dummy ->  1 -> 2
                         p1 ->
                    p2 ->
                    
        k=2
        dummy -> 1 -> 2 -> 3 -> 4
                     p2 -> 
    */

    if (k < 0 || head == NULL) return head;

    SinglyLinkedListNode* dummy = malloc(sizeof(SinglyLinkedListNode));
    dummy->data = 0;
    dummy->next = head;

    SinglyLinkedListNode* p1 = malloc(sizeof(SinglyLinkedListNode));
    p1->next = head;
    
    SinglyLinkedListNode* p2 =  malloc(sizeof(SinglyLinkedListNode));
    p2->next = dummy;

    
    for (int i = 0; i < k; i++) {
        if (p1 == NULL) {
            //free(dummy);
            return head;
        }
        p1 = p1->next;
    }

    
    while (p1->next != NULL) {
        p1 = p1->next;
        p2 = p2->next;
       // printf("p2->data: %d\n", p2->data);
    }
    
    if(head == p2->next){ 
        head = p2->next->next; 
    } else {
        p2->next = p2->next->next;
        //p2->next = NULL;
    }

   // free(toRemove);
    
    return head;
}

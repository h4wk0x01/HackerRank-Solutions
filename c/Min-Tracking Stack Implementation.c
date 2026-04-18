typedef struct Stack{
    int value;
    int minValue;
    struct Stack* next;
}Stack;

Stack* push ( Stack* head, int new_num ){
    
    Stack* newNode = malloc( 1 * sizeof(Stack) );
    
    if(head == NULL){
        newNode->minValue = new_num;
    } else if ( new_num < head->minValue ){
        newNode->minValue = new_num;
    } else {
        newNode->minValue = head->minValue;
    }
    
    newNode->next = head;
    newNode->value = new_num;
    head = newNode;
    
    return head;
}

int getMin (Stack* head){
    return head->minValue;
}

Stack* pop ( Stack* head ){
    Stack* aux = head;
    head = head->next;
    free(aux);
    
    return head;
}

int top ( Stack* head ){
    return head->value;
}
 
int getPushNum (char* str){
    int val = 0;
    sscanf(str, "push %d", &val);
    return val;
}
 
int* processCouponStackOperations(int operations_count, char** operations, int* result_count) {
    
    Stack* head = NULL;
    
    int idx = 0;
    int* resp = malloc( 1 * sizeof(int) );
    
    for( int i = 0; i < operations_count; i++ ){
        if( strncmp(operations[i], "push", 4) == 0 ){ // verify it later
            int num = getPushNum(operations[i]);
            head = push(head, num);
        }
        
        if( strcmp(operations[i], "pop") == 0 ){
            head = pop(head);
        }
        
        if( strcmp(operations[i], "top") == 0 ){
            int topVal = top(head);
            idx++;
            resp = realloc(resp, idx * sizeof(int));
            resp[idx-1] = topVal;
        }
        
        if( strcmp(operations[i], "getMin") == 0 ){
            int min = getMin(head);
            idx++;
            resp = realloc(resp, idx * sizeof(int));
            resp[idx-1] = min;
        }
        
        
    }
    *result_count = idx;
    return resp;
}

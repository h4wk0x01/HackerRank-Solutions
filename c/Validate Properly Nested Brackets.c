typedef struct Stack {
    char value;
    struct Stack* next;
}Stack;

/*

  HEAD == NULL
                     
  newNode.value = '(', newNode.next = NULL <-  HEAD   
  
  ([{}])
*/  
    
bool areBracketsProperlyMatched(char* code_snippet) {
    
    Stack *head = malloc( 1 * sizeof(Stack) );
    
    for(int i = 0; code_snippet[i] != '\0'; i++){
        //printf("Char: %c\n", code_snippet[i]);
        if(code_snippet[i] == '(' || code_snippet[i]  == '[' || code_snippet[i]  == '{'){
           //printf("here\n");
            // append()
            Stack *newNode = malloc( 1 * sizeof(Stack) );
            newNode->value = code_snippet[i];
            newNode->next = head->next;
            head->next = newNode;
        } else if (code_snippet[i] == ')' || code_snippet[i]  == ']' || code_snippet[i]  == '}') {
            
            //printf("here\n");
            if(head->next == NULL){return 0;}        
                
            if(code_snippet[i] == ')' && head->next->value != '('){
                return false;
            } else if(code_snippet[i] == ']' && head->next->value != '['){
                return false;
            } else if(code_snippet[i] == '}' && head->next->value != '{'){
                return false;
            }
            // pop()
            //printf("Pop: %d\n", head->next->value);
            head->next = head->next->next;
        }
        
    }
    if(head->next != NULL){/*printf("Error here: %d\n", 3);*/ return 0;}  // problem is here...
    return 1;
}

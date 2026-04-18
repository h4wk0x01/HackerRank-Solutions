bool isNonTrivialRotation(char* s1, char* s2) {
    
    if(strcmp(s1,s2) == 0){return 0;}
    
    if(strlen(s1) == 1){return 0;}
    
    char* doubledS1 = malloc(2 * strlen(s1) + 1);
    
    strcpy(doubledS1, s1);
    strcat(doubledS1, s1);
    
    if(strstr(doubledS1, s2) != NULL){return true;}
    
    return false;
}

bool isPalindromeRecursive(char* str, int i, int j){
    if (i >= j) {return true;}
    if (str[i] != str[j]){return false;}
    return isPalindromeRecursive(str, i + 1, j - 1);
}

bool isAlphabeticPalindrome(char* code) {
   int i = 0;
   int str_size = 0;
   char* dynamic_str = malloc(1 * sizeof(char));
   while (code[i] != '\0') {
        if (isalpha(code[i])){
            str_size++;
            dynamic_str = realloc(dynamic_str, str_size * sizeof(char));
            dynamic_str[str_size-1] = tolower(code[i]);
        }
        i++;
    }
   
    int result = isPalindromeRecursive(dynamic_str, 0, str_size-1);
    free(dynamic_str);
    return result;
}

int isAnagram(char* s, char* t) {
    
    int result = 1;
    
    int s_length = strlen(s);
    int t_length = strlen(t);
    
    if ( s_length != t_length ) { return 0; } // If different sizes, not anagrams, right ?
    
    char c[256] = {0};
    
    for (int i = 0; i < s_length; i++) {
        c[(int)s[i]]++;
    }
    
    for (int i = 0; i < t_length; i++) {
        c[(int)t[i]]--;
    }
    
    for( int i = 0; i < 256; i++ ) {
        if( c[i] != 0 ){
            result = 0;
            break;
        }
    }
    
    return result;
}

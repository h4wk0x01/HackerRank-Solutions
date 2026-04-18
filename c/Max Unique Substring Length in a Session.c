int maxDistinctSubstringLengthInSessions(char* sessionString) {
    
    char state[256] = {0}; // no chars visited yet
    
    int right = 0;
    int left = 0;
    int n = strlen(sessionString);
    int maxLength = 0;
    
     if( n == 1 && sessionString[0] == '*' ){ return 0; }
    
    while( right < n ){
        
        if( sessionString[right] == '*' ){
            right = right + 1;
            left = right;
            for( int i = 0; i < 256; i++ ) state[i] = 0;
            continue;
        }
        
        while( state[(int)sessionString[right]] == 1 ){ // while char[left] is repeated, move left
            state[(int)sessionString[left]] = 0;
            left++;
        }
        
        state[(int)sessionString[right]] = 1; // visited
        
        int currSize = right - left + 1;
        
        if(  currSize > maxLength ) maxLength = currSize;
        
        right++;
        
    }
    
    return maxLength;
    
}

long getAutoSaveInterval(int n) {
    
    long fibonacci[3] = {1,2,3}; // i just need the 2 last numbers to get the next one
    
    if (n < 3) { return fibonacci[n]; }
    
    long new_element = 0;

    for( int i = 2; i < n; i++) { // i starts at 2 (precomputed [1,2,3])
    
        new_element = fibonacci[1] + fibonacci[2];
        
        // SLIDE LEFT
        fibonacci[0] = fibonacci[1]; // No problem, we don't need the first element
        fibonacci[1] = fibonacci[2];
        fibonacci[2] = new_element;
        
    }
    
    return fibonacci[2];
}


int countAffordablePairs(int prices_count, int* prices, int budget) {
    
    // Sliding Window
    
    if(prices_count < 2){ return 0; }
    
    int counter = 0;
    int right = prices_count-1;
    int left = 0;
    while ( left != right ){
        //printf("Left: %d + Right: %d <= %d ?\n", left, right, budget);
        if( (prices[left] + prices[right]) <=  budget ) {
            counter += (right - left);
            left++;
        } else {
           right--;
        }
    
    }
    return counter;
}

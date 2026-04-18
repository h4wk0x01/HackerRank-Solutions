void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int findSmallestMissingPositive(int orderNumbers_count, int* orderNumbers) {
    
    if( orderNumbers_count == 0 ) { return 1;}
    
    int answer = 0;
    
    for(int i = 0; i < orderNumbers_count; i++){
        while( ( orderNumbers[i] > 0 ) && ( orderNumbers[i] < orderNumbers_count ) && ( orderNumbers[i] != i+1 ) && (orderNumbers[i] != orderNumbers[orderNumbers[i]-1]) ) {
            swap(&orderNumbers[i], &orderNumbers[orderNumbers[i]-1]);
        }
    }
    
    int j = 0;
    while(answer == 0 && j < orderNumbers_count) {
        if (orderNumbers[j] != j+1) {
            answer = j+1;
        }
        j++;
    }
    
    if(answer == 0) {return orderNumbers_count+1;}
    
    return answer;
}

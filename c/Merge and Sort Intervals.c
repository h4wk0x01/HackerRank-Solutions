
int compareIntervals(const void* a, const void* b) {
    int* intervalA = *(int**)a;
    int* intervalB = *(int**)b;
    if (intervalA[0] < intervalB[0]) return -1;
    if (intervalA[0] > intervalB[0]) return 1;
    return 0;
}
 
int** mergeHighDefinitionIntervals(int intervals_rows, int intervals_columns, int** intervals, int* result_rows, int* result_columns) {
    
    *result_rows = 0;
    if ( intervals_rows <= 0 ) { return NULL; }
    
    qsort(intervals, intervals_rows, sizeof(int*), compareIntervals);
    
    int** mergedList = malloc( intervals_rows * sizeof(int*) );
    int listIdx = 1;
    
    mergedList[0] = malloc( 2 * sizeof(int) );
    mergedList[0][0] = intervals[0][0];
    mergedList[0][1] = intervals[0][1];
    
    for( int i = 1; i < intervals_rows; i++ ){
        
        if( intervals[i][0] <= mergedList[listIdx-1][1] ){ // 2 <= 3
            // merge [1, 3], [2, 6]
            mergedList[listIdx-1][0] = (mergedList[listIdx-1][0] <= intervals[i][0]) ? mergedList[listIdx-1][0] : intervals[i][0];
            mergedList[listIdx-1][1] = (mergedList[listIdx-1][1] >= intervals[i][1]) ? mergedList[listIdx-1][1] : intervals[i][1];
        } else {
            // add next element
            listIdx++; // = 2
            mergedList[listIdx-1] = malloc( 2 * sizeof(int) );
            mergedList[listIdx-1][0] = intervals[i][0];
            mergedList[listIdx-1][1] = intervals[i][1];
        }
        
    }
    
    *result_columns = 2;
    *result_rows = listIdx;
    
    return mergedList;
}

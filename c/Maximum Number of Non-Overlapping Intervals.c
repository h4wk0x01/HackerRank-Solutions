int comparison(const void* a, const void* b){
    int* valA = *(int**)a;
    int* valB = *(int**)b;
    
    return valA[1] - valB[1];
}

int maximizeNonOverlappingMeetings(int meetings_rows, int meetings_columns, int** meetings) {
    
    //sorted_meetings = [[1, 2], [1, 3], [2, 3], [3, 4], ] // sorted by end_time
    
    if(meetings_rows <= 0) { return 0; }
    
    qsort(meetings, meetings_rows, sizeof(int*), comparison);
    
    int counter = 1;
    int previous_end = meetings[0][1]; // = 2
    
    for(int i = 1; i < meetings_rows; i++){
        if( meetings[i][0] >= previous_end ){
            previous_end = meetings[i][1];
            counter++;
        }
    }
    
    return counter;
    
}

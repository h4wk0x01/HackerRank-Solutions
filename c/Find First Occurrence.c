int findFirstOccurrence(int nums_count, int* nums, int target) {
    
    if(nums_count == 0){return -1;};
    
    int low = 0;
    int high = nums_count-1;
    int mid = (low+high)/2;
    int lowest_resp = INT_MAX;
    bool found = false;
    
    while(low <= high){
        if( target < nums[mid] ){
            high = mid - 1;
            mid = (low+high)/2;
        } else if ( target > nums[mid] ){
            low = mid + 1;
            mid = (low+high)/2;
        } else {
            // Found
            found = true;
            if(mid < lowest_resp){lowest_resp = mid;}
            high = mid - 1;
            mid = (low+high)/2;
        }
    }
    return found ? lowest_resp : -1;
}

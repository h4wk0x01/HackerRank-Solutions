int binarySearch(int nums_count, int* nums, int target) {
    
    if(nums_count == 0){ return -1; }
    
    if(nums_count == 1 && nums[0] != target){ return -1; }
    
    int low = 0;
    int high = nums_count-1;
    int mid = (low+high)/2;
    
    int answer = -1;
    while(low <= high){
        //printf("Low: %d - High: %d - Mid: %d\n", low, high, mid);
        if (target > nums[mid]) {
            if(mid+1 > nums_count){return -1;};
            low = mid + 1;
            mid = (low+high)/2;    
        } else if (target < nums[mid]) {
            if(mid-1 < 0){return -1;};
            high = mid - 1;
            mid = (low+high)/2;
        } else if (target == nums[mid]) {
            return mid;
        }
    }
    return answer;
}

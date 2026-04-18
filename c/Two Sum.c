int* findTaskPairForSlot(int taskDurations_count, int* taskDurations, int slotLength, int* result_count) {
  
  int* result = malloc( 2 * sizeof(int) );
  result[0] = -1;
  result[1] = -1;
  *result_count = 2;
  
  if ( taskDurations_count == 0 ) return result;
  
  int* hashMap = malloc( 2000001 * sizeof(int) );
  for( int i = 0; i < 2000001; i++ ) hashMap[i] = -1;
  
  int needed = 0;
  
  for( int i = 0; i < taskDurations_count; i++ ){
    needed = slotLength - taskDurations[i]; // i = 4, needed = 9-5=4,  hashMap[4] != -1 ??
    if( needed >= 0 && hashMap[needed] != -1  ){
        result[0] = hashMap[needed];
        result[1] = i;
        break;
    }
    hashMap[taskDurations[i]] = i;
  }
  
  free(hashMap);
  
  return result;
  

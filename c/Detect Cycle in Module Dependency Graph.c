bool dfs( int node, int* state, int dependencies_rows, int** dependencies) {
    
    if ( state[node] == 1 ){ return true; } // Gray, already visited. We've found a cycle! :)
    
    if ( state[node] == 2 ){ return false; } // Black, Dead End :(
    
    state[node] = 1; // Set as gray, visiting now
    
    for( int i = 0; i < dependencies_rows; i++ ){
        if( dependencies[i][0] == node ){ // found our node in the array
            int neighbor = dependencies[i][1]; // What it depends on ? Neighbor
            if( dfs( neighbor, state, dependencies_rows, dependencies) ) {
                return true;
            }
        }
    }
    
    state[node] = 2; // Set as black, we didn't find a path for this node :(
    
    return false;
}

bool hasCircularDependency(int n, int dependencies_rows, int dependencies_columns, int** dependencies) {
   
   /*
   */
   if( dependencies_rows == 0 ) { return false; }
   
   //GRAPH CYCLE
   
   // 0- White (Not Visited)  //  1- Gray (Visiting)  //  2-  Black (Dead End)
   int* state = malloc(n * sizeof(int)); 
   for(int i = 0; i < n; i++) state[i] = 0; // You'll get timeout in one of the tests if you use calloc instead of malloc
   
   for( int i = 0; i < n; i++ ){
        if( state[i] == 0 ){
            if (dfs( i, state, dependencies_rows, dependencies)){
                free(state);
                return true;
            }
        }
   }
   
   free(state);
   return false;
}

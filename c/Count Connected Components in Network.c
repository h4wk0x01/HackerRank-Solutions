void dfs( int node, int* visited, int links_rows, int** links ){
    
    visited[node] = 1;
    
    for( int i = 0; i < links_rows; i++ ){
        
        if( node == links[i][0] && visited[links[i][1]] != 1 ){
            dfs( links[i][1], visited, links_rows, links);
        }
        
        if( node == links[i][1] && visited[links[i][0]] != 1 ){
            dfs( links[i][0], visited, links_rows, links);
        }
        
    }
    
}

int countIsolatedCommunicationGroups(int links_rows, int links_columns, int** links, int n) {
    
    if( links_rows == 0 ) return 0;
    
    // DFS SOLUTION
    
    int* visited = malloc(1001 * sizeof(n)); // 1-Visited // 0-Not visited yet
    
    int components = 0;
    for( int i = 0; i < n; i++ ){
        if( visited[i] != 1 ){
            dfs( i, visited, links_rows, links);
            components++;
        }
    }
   return components;
}

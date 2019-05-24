// inside int main()---this is the DFS solution 
numCC = 0; 
dfs_num.assign(V, UNVISITED); // sets all vertices’ state to UNVISITED 
for (int i = 0; i < V; i++) // for each vertex i in [0..V-1] 
  if (dfs_num[i] == UNVISITED) // if vertex i is not visited yet 
    printf("CC %d:", ++numCC), dfs(i), printf("\n"); // 3 lines here!

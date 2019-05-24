/*
This file contains just pseudo code for dfs
*/

typedef pair<int, int> ii; // In this chapter, we will frequently use these 

typedef vector<ii> vii; // three data type shortcuts. They may look cryptic 

typedef vector<int> vi; // but they are useful in competitive programming

vi dfs_num; // global variable, initially all values are set to UNVISITED

void dfs(int u) 
{ 
  // DFS for normal usage: as graph traversal algorithm 
  dfs_num[u] = VISITED; // important: we mark this vertex as visited 
  for (int j = 0; j < (int)AdjList[u].size(); j++) 
  { // default DS: 
    AdjList ii v = AdjList[u][j]; // v is a (neighbor, weight) pair 
    if (dfs_num[v.first] == UNVISITED) // important check to avoid cycle d
      fs(v.first); // recursively visits unvisited neighbors of vertex u 
   }
} 
 // for simple graph traversal, we ignore the weight stored at v.second

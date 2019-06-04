# Fishmonger

ii go(int cur, int t_left) 
{                                                           // returns a pair (tollpaid, timeneeded) 
if (t_left < 0) return ii(INF, INF);                        // invalid state, prune 
if (cur == n - 1) return ii(0, 0);                          // at market, tollpaid=0, timeneeded=0 
if (memo[cur][t_left] != ii(-1, -1)) return memo[cur][t_left]; 
ii ans = ii(INF, INF); 
for (int X = 0; X < n; X++)
  if (cur != X) {                                            // go to another city 
  ii nextCity = go(X, t_left - travelTime[cur][X]);          // recursive step 
  if (nextCity.first + toll[cur][X] < ans.first) {           // pick the min cost 
  ans.first = nextCity.first + toll[cur][X]; 
  ans.second = nextCity.second + travelTime[cur][X]; }} 
  return memo[cur][t_left] = ans; }                          // store the answer to memo table

# Minimum vertex cover

int MVC(int v, int flag) {                                  // Minimum Vertex Cover 
int ans = 0; 
if (memo[v][flag] != -1) return memo[v][flag];              // top down DP 
else if (leaf[v])                                           // leaf[v] is true if v is a leaf, false otherwise 
ans = flag;                                                 // 1/0 = taken/not
else if (flag == 0) 
{                                                           // if v is not taken, we must take its children 
ans = 0;                                                    // Note: ‘Children’ is an Adjacency List that contains the 
                                                            // directed version of the tree (parent points to its children; but the 
                                                            // children does not point to parents) 
  for (int j = 0; j < (int)Children[v].size(); j++) 
  ans += MVC(Children[v][j], 1); 
}  
else if (flag == 1) 
{                                                            // if v is taken, take the minimum between 
ans = 1;                                                     // taking or not taking its children 
for (int j = 0; j < (int)Children[v].size(); j++) 
ans += min(MVC(Children.[v][j], 1), MVC(Children[v][j], 0)); } 
return memo[v][flag] = ans;
}

# Eulerian Graph

list<int> cyc;                                              // we need list for fast insertion in the middle
void EulerTour(list<int>::iterator i, int u) 
{ for (int j = 0; j < (int)AdjList[u].size(); j++) 
{ ii v = AdjList[u][j]; 
if (v.second) 
{                                                           // if this edge can still be used/not removed 
v.second = 0;                                               // make the weight of this edge to be 0 (‘removed’) 
for (int k = 0; k < (int)AdjList[v.first].size(); k++) 
{ ii uu = AdjList[v.first][k];                              // remove bi-directional edge 
if (uu.first == u && uu.second) { uu.second = 0; break; }} 
EulerTour(cyc.insert(i, u), v.first); }}}

// inside int main() 
cyc.clear(); 
EulerTour(cyc.begin(), A);                                                                    // cyc contains an Euler tour starting at A 
for (list<int>::iterator it = cyc.begin(); it != cyc.end(); it++) printf("%d\n", *it);        // the Euler tour


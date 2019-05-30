#include <iostream>
#include<utility>
#include<vector>
#include<queue>
using namespace std;

typedef pair<int, int> ii;
typedef vector<int > vi;
typedef vector<ii> vii;
typedef vector<vector<int>> vvi;
typedef vector<int> v;
typedef queue<int> qi; 


vvi graph;
v color;


bool isBipartite;

static const int INF = -1;


int main()
{
    int n, e;
    
    while(scanf("%d", &n) == 1 && n != 0)
    {
        scanf("%d", &e);
        
        isBipartite = true;
        graph.clear();
        graph.resize(n);
        color.clear();
        color.resize(n, INF);
        
        qi q;
        int a, b;
        for(int i=0;i<e;i++)
        {
            scanf("%d %d", &a, &b);
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        q.push(0);
        color[0] = 0;
        while(!q.empty())
        {
            int u = q.front(); q.pop();
            for(int i=0;i<(int)graph[u].size();i++)
            {
                int v = graph[u][i];
                if(color[v] == INF){ 
                color[v] = 1 - color[u];
                q.push(v);
                }
                else if(color[v] == color[u])
                {
                 isBipartite = false;
                 break;
                }
            }
        }
        isBipartite? printf("BICOLORABLE.\n"):printf("NOT BICOLORABLE.\n");
    }
}

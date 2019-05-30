#include<iostream>
#include<vector>
using namespace std;
typedef vector<vector<int>> vvi;
typedef vector<int> vi;

vvi network;
vi dfs_Num;
vi dfs_Low;
vi visited;
vi S;
int numSCC;
int dfscounter = 0;

static const int UNVISITED = -1;

void tarjanSSC(int u)
{
    dfs_Num[u] = dfs_Low[u] = dfscounter++;
    S.push_back(u);
    visited[u] = 1;
    for(int i=0;i<(int)network[u].size();i++)
    {
        int v = network[u][i];
        if(dfs_Num[v] == UNVISITED)
        {
            tarjanSSC(v);
        }
        if(visited[v])
        {
            dfs_Low[u] = min(dfs_Low[u], dfs_Low[v]);
        }
    }
    if(dfs_Num[u] == dfs_Low[u])
    {
        numSCC++;
        while(1)
        {
            int v = S.back(); S.pop_back();visited[v] = 0;
            //printf("%d", v);
            if(u == v) break;
        }
        //printf("\n")
    }
    
}

int main()
{
    int n, e;
    while(scanf("%d %d", &n, &e) == 2 && n!=0)
    {
        network.clear();
        network.resize(n+1);
        dfs_Num.clear();
        dfs_Num.resize(n+1, UNVISITED);
        dfs_Low.clear();
        dfs_Low.resize(n+1);
        visited.clear();
        visited.resize(n+1, 0);
        numSCC = 0;
        dfscounter =0;
        S.clear();
        int u, v, d;
        for(int i=0;i<e;i++)
        {
            scanf("%d %d %d", &u, &v, &d);
            if(d == 1) network[u].push_back(v);
            else if(d== 2) 
            {network[u].push_back(v);network[v].push_back(u);}
        }
        for(int i=1;i<=n;i++)
            if(dfs_Num[i] == UNVISITED)
                tarjanSSC(i);
        (numSCC==1)?puts("1"):puts("0");
    }
}

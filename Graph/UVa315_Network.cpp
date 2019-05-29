#include <iostream>
#include<algorithm>
#include<string>
#include<sstream>
#include<utility>
#include<vector>

using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

vvi network;
vi dfs_Num;
vi dfs_Low;
vi dfs_Parent;
static const int UNVISITED = -1;
int dfscounter = 1;
vector<bool> artipoint;
int rootChildren;
int dfs_root;
vii edge;

void FindSolution(int u)
{
    dfs_Num[u] = dfs_Low[u] = dfscounter++;
    for(int j=0;j<(int)network[u].size();j++)
    {
        int v = network[u][j];
        if(dfs_Num[v] == UNVISITED)
        {
            if(u == dfs_root) rootChildren++;
            dfs_Parent[v] = u;
            FindSolution(v);
            if(dfs_Low[v] >= dfs_Num[u]) artipoint[u] = true;
            //if(dfs_Low[V] > dfs_Num[u]) edge.push_back(make_pair(u, v);
            dfs_Low[u] = min(dfs_Low[u], dfs_Low[v]);
        }
        else if(v != dfs_Parent[u])
        {
            dfs_Low[u] = min(dfs_Low[u], dfs_Num[v]);
        }
    }
}

int main()
{
    int node;
    string s;
    while(cin>>node, node !=0)
    {
        cin.ignore();
        dfscounter = 1;
        //edge.clear();
        network.clear();
        network.resize(node + 1);
        dfs_Num.clear();
        dfs_Num.resize(node + 1, UNVISITED);
        dfs_Low.clear();
        dfs_Low.resize(node + 1, 0);
        dfs_Parent.clear();
        dfs_Parent.resize(node + 1, 0);
        artipoint.clear();
        artipoint.resize(node + 1, false);
        
        while(getline(cin, s) && s != "0")
        {
            stringstream ss(s);
            int u, v;
            ss >> u;
            while(ss >> v)
            {
                network[u].push_back(v);
                network[v].push_back(u);
            }
        }
        for(int i=0;i<node;i++)
        {
            if(dfs_Num[i] == UNVISITED)
            {
                dfs_root = i; rootChildren = 0;
                FindSolution(dfs_root);
                artipoint[dfs_root] = (rootChildren > 1);
            }
        }
        int count = 0;
        //printf("Articulation Points: \n");
        for(int i=0;i<=node;i++)
            if(artipoint[i])
                count++;
        printf("%d\n", count);
        
    }
}

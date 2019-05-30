#include <iostream>
#include<vector>
#include<utility>
#include<queue>
#include<algorithm>
using namespace std;

typedef vector<int > vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<pair<int, ii>> viii;
typedef queue<int> qi;
vi visited;
viii edge;
vi set;
vi ans;


int num;

bool comp(pair<int, ii> a, pair<int , ii> b)
{
    return (a.first < b.first);
}

int main()
{
    int n ,e;
    while(scanf("%d %d", &n, &e) == 2 && n)
    {
        edge.clear();
        set.clear();
        set.resize(n, 0);
        visited.clear();
        visited.resize(n, 0);
        
        ans.clear();
        num = 0;
        int u, v, w;
        for(int i=0;i<e;i++)
        {
            scanf("%d %d %d", &u, &v, &w);
            edge.push_back(make_pair(w, ii(u, v)));
            
            set[u] = u;
            set[v] = v;
            
        }
        
        sort(edge.begin(), edge.end(), comp);
        for(int i=0;i<e;i++)
        {
            pair<int, ii> front = edge[i];
            u = front.second.first;
            v = front.second.second;
            //printf("%d %d %d\n", u, v, edge[i].first);
            if(set[u] != set[v])
            {
                set[v] = set[u];
            }
            else if(set[u] == set[v])
            {
                ans.push_back(edge[i].first);
                num++;
            }
        }
        sort(ans.begin(), ans.end());
        if(num == 0) printf("forest");
        else
        {
            for(int i=0;i<(int)ans.size();i++)
                printf("%d ", ans[i]);
        }
        printf("\n");
    }
}

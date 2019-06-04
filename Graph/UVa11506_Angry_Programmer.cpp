#include <cstdio>
#include <vector>
#include <utility>
#include <bitset>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define INF 1e9
#define MAX_V 100

int res[MAX_V][MAX_V], mf, f, s, t;
int res2[MAX_V][MAX_V];
vector<vi> AdjList;
vi p;
vi sor, tar;
int ans;

void augment(int v, int minEdge) {
	if (v == s) {
		f = minEdge;
		return;
	} else if (p[v] != -1) {
		augment(p[v], min(minEdge, res[p[v]][v]));
		res[p[v]][v] -= f;
		res[v][p[v]] += f;
	}
}



void EdmondKarps() {
	mf = 0;
	while (1) {
		f = 0;
		bitset<MAX_V> visited;
		visited.set(s);
		queue<int> q;
		q.push(s);
		p.assign(MAX_V, -1);
		while (!q.empty()) {
			int u = q.front();
			q.pop();
			if (u == t)
				break;
			for (int i = 0; i < (int) AdjList[u].size(); i++) {
				int v = AdjList[u][i];
				if (res[u][v] > 0 && !visited.test(v)) {
					visited.set(v);
					q.push(v);
					p[v] = u;
				}
			}
		}
		augment(t, INF);
		if (f == 0)
			break;
		mf += f;
	}
}



int main() {
    int m, w;
    s =1;
    int x, weight, y;
    while(scanf("%d %d", &m, &w) == 2 && m)
    {
        ans = 0;
        t = m*2;
        AdjList.clear();
        AdjList.resize(MAX_V);
        for(int i=0; i<m-2;i++)
        {
            scanf("%d %d", &x, &weight);
            res[x*2 - 1][x*2] = weight;
            res2[x*2 - 1][x*2] = weight;
            AdjList[x*2-1].push_back(x*2);
            //AdjList[x*2].push_back(x*2-1);
        }
        for(int i=0;i<w;i++)
        {
            scanf("%d %d %d", &x, &y, &weight);
            res[x*2][y*2-1] = weight;
            res2[x*2][y*2-1] = weight;
            AdjList[x*2].push_back(y*2-1);
            //AdjList[y*2-1].push_back(x*2);
        }
        res[1][2] = INF;
        AdjList[1].push_back(2);
        res[m*2-1][m*2] = INF;
        AdjList[m*2-1].push_back(m*2);
        
        EdmondKarps();
        sor.clear();
        tar.clear();
        bitset<MAX_V> visited;
		visited.set(s);
		queue<int> q;
		q.push(1);
		while (!q.empty()) {
			int u = q.front();
			q.pop();
			if (u == t)
				break;
			for (int i = 0; i < (int) AdjList[u].size(); i++) {
				int v = AdjList[u][i];
				if (res[u][v] > 0 && !visited.test(v)) {
					visited.set(v);
					q.push(v);
					sor.push_back(v);
				}
			}
		}
		for(int i=0;i<(int)sor.size();i++)
		{
		    for(int j=0;j<(int)AdjList[sor[i]].size();j++)
		    {
		        if(res[sor[i]][AdjList[sor[i]][j]] == 0)
		        ans += res2[sor[i]][AdjList[sor[i]][j]];
		    }
		}
        
        
        printf("%d\n",ans);    
    }
    
		

	

	return 0;
}

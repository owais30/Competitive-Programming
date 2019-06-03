#include<iostream>
#include<vector>
#include<queue>
#include<utility>
#include<map>
using namespace std;

#define REP(i, n) for(int i=0;i<n;i++)
#define INF (1<<63)
#define IntInf (1<<15)
#define u64 unsigned long long
#define u32 long long

struct point
{
    int x, y, w;
};

vector<point> p;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef pair<int, ii> iii;

int main()
{
    int t;
    scanf("%d", &t);
    int n, m;
    int tx[] = {1, 0, -1, 0};
    int ty[] ={0, 1, 0, -1};
    int x, y;
    while(t--)
    {
        scanf("%d", &n);
        scanf("%d", &m);
        int mat[n][m];
        map<ii, int> dist;
        REP(i,n)
            REP(j,m)
            {
                scanf("%d", &mat[i][j]);
                dist[ii(i,j)] = IntInf;
            }
        priority_queue<ii, vector<ii>, greater<ii>> pq;
        pq.push(ii(0, 0));
        dist[ii(0, 0)] = mat[0][0];
        while(!pq.empty())
        {
            ii u = pq.top();pq.pop();
            int currx = u.first;
            int curry = u.second;
            for(int i=0;i<4;i++)
            {
                x = tx[i] + currx;
                y = ty[i] + curry;
                if(x >=0 && y >=0 && x < n && y < m)
                {
                    if(dist[ii(x, y)] > dist[ii(currx, curry)] + mat[x][y] )
                    {
                        dist[ii(x, y)] = dist[ii(currx, curry)] + mat[x][y];
                        pq.push(ii(x,y));
                    }
                }
            }
        }
        cout<<dist[ii(n-1,m-1)]<<endl;
    }
    
}

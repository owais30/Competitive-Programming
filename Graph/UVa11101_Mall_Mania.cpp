#include<iostream>
#include<vector>
using namespace std;

#define REP(i, n) for(int i=0;i<n;i++)
#define INF (1<<63)
#define IntInf (1<<15)
#define u64 unsigned long long
#define u32 long long

struct point
{
    int x, y;
};

typedef vector<point> p;

int main()
{
    int n ,m ;
    p m1, m2;
    while(scanf("%d", &n)==1 && n )
    {
        m1.clear();
        m1.resize(n);
        REP(i,n) scanf("%d %d",&m1[i].x, &m1[i].y);
        
        scanf("%d", &m);
        m2.clear();
        m2.resize(m);
        REP(i,m) scanf("%d %d", &m2[i].x, &m2[i].y);
        int ans = IntInf;
        REP(i,n)
            REP(j,m)
                ans = min(ans, abs(m1[i].x - m2[j].x) + abs(m1[i].y - m2[i].y));
        cout<<ans<<endl;
    }
}

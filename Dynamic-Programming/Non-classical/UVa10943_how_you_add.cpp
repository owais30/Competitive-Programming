#include <iostream>
using namespace std;

int way[100][100];

int ways(int n ,int k)
{
    if(k == 1) return 1;
    if(way[n][k] != -1) return way[n][k];
    
    int ans = 0;
    for(int i=0;i<=n;i++)
        ans += ways(n -i, k-1);
    
    return way[n][k] = ans;
}

int main()
{
    for(int i=0;i<100;i++)
        for(int j=0;j<100;j++)
            way[i][j] = -1;
    int n, k;
    while(scanf("%d %d", &n, &k) && n!=0 && k!=0)
    {
        printf("%d\n", ways(n, k)%100000);
    }
}

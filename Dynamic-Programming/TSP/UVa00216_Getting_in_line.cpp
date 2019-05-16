#include <iostream>
#include<cmath>
#include<cstring>
using namespace std;

float memo[8][1 << 8];
float dist[8][8];

float connect(int pos, int bitmask, int n)
{
    if(bitmask == ((1 << n) - 1)) return 0;
    
    if(memo[pos][bitmask] != -1) return memo[pos][bitmask];
   
    float ans = 200000000;
    
    for(int i=0; i< n; i++)
        if(i != pos && !(bitmask & (1 << i)))
            ans = min(ans, dist[pos][i] + connect(i, (bitmask | 1 << i), n));
   
 
    return memo[pos][bitmask] = ans;
    
}


int main()
{
    int n;
    scanf("%d", &n);
    
    while(n != 0)
    {
        for(int i=0;i<8;i++)
            for(int j=0;j<(1<<8);j++)
                memo[i][j] = -1.0;
        int x[n], y[n];
        for(int i=0;i<n;i++)
            scanf("%d %d", &x[i], &y[i]);
        
        for(int i = 0; i<n;i++)
            for(int j=0;j<n;j++)
            {
                dist[i][j] = pow(x[i]-x[j], 2) +  pow(y[i]- y[j], 2);
                dist[i][j] = pow(dist[i][j], 0.5);
            }
        
        float final = 200000000;
        for(int i=0;i<n;i++)
            final = min(final, connect(i, 1<<i, n));
        
        final = final + 16*(n-1);
        printf("%f\n", final);
        
        scanf("%d", &n);
    }
}

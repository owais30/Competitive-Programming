#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    int k;
    float z;
    float x;
    int ans = 0;
    while(scanf("%d", &k) == 1)
    {
        ans = 0;
        for(int y=k+1;y<=2*k;y++)
        {
            
            if((k*y) % (y - k) == 0)
            {
                ans++;
            }
        }
        printf("%d\n", ans);
    }
}

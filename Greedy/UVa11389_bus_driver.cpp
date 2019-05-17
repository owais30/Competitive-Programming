#include <iostream>
#include<algorithm>
using namespace std;

int main()
{
    int n, d, r;
    while(scanf("%d %d %d", &n, &d, &r) == 3 && n && d && r)
    {
        int m[n];
        int e[n];
        for(int i=0;i<n;i++)
            scanf("%d", &m[i]);
        for(int i=0;i<n;i++)
            scanf("%d", &e[i]);
            
        sort(m, m+n);
        sort(e, e+n);
        int sum = 0;
        for(int i=0;i<n;i++)
        {
            if(m[i] + e[n-i-1] > d)
            {
                sum += (m[i] + e[n-i-1] - d)*r;
            }
        }
        printf("%d\n", sum);
    }
}

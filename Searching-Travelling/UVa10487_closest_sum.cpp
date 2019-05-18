#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    int n;
    while(scanf("%d", &n) == 1 && n)
    {
        int a[n];
        for(int i=0;i<n;i++)
        scanf("%d", &a[i]);
        int m;
        scanf("%d", &m);
        while(m--)
        {
            int tar;
            scanf("%d", &tar);
            int diff = 1000000; 
            int ans = 0;
            for(int i=0;i<n-1;i++)
                for(int j=i+1;j<n;j++)
                    if(abs(a[i] + a[j] - tar) <= diff)
                    {
                        ans = a[i] + a[j];
                        diff = abs(a[i] + a[j] - tar);
                    }
            printf("%d\t", ans);
        }
        printf("\n");
    }
}

#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    int t, n;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        int a[n];
        int b[n-1];
        int am = 0;
        for(int i =0 ;i<n;i++)
        {    
            scanf("%d", &a[i]);
            if(i >= 1)
            {
                for(int j=0;j<i;j++)
                    if(a[j] <= a[i])
                        am++;
                
            }
        }
        printf("%d\n", am);
    }
}

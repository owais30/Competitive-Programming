#include <iostream>
#include<bits/stdc++.h>
using namespace std;


int main()
{
    int s, c;
    float av;
    while(scanf("%d %d", &c, &s) == 2)
    {
        int sp[2*c];
        int sum = 0;
        int cm[c] = {0};
        for(int i=0;i<2*c;i++)
        {    if(i < s) scanf("%d", &sp[i]);
            else
            sp[i] =  0;
            
            sum += sp[i];
        }    
        
        av = sum / c;
        sort(sp, sp+(2*c));
        float imb = 0.0;
        for(int i =0;i<2*c;i++)
            printf("%d\t", sp[i]);
        printf("\n");
        for(int i=0;i<c;i++)
        {
            cm[i] += sp[i] + sp[2*c - i-1];
        }
        for(int i =0;i<c;i++)
            printf("%d\t", cm[i]);
        for(int i=0;i<c;i++)
        {
            imb += abs(cm[i] - av);
        }
        printf("\n%f\n", imb);
    }
}

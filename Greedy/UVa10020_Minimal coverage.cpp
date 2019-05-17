#include<bits/stdc++.h>

using namespace std;

struct segment
{
  int l, r;  
};

bool comp(segment a, segment b)
{
    return (a.l < b.l);
}

int main()
{
    int m;
    scanf("%d", &m);
    int t;
    scanf("%d", &t);
    segment seg[t];
    for(int i=0;i<t;i++)
        scanf("%d %d", &seg[i].l, &seg[i].r);
    sort(seg, seg+t, comp);
    int v = 0;
    int count = 0;
    int curr;
    while(v < m)
    {
        curr = 0;
        for(int i=0;i<t;i++)
        {
           if(seg[curr].r <= seg[i].r && seg[i].l <= v) curr = i; 
        }
        
        v = seg[curr].r;
        printf("curr :%d v: %d\n",curr, v);
        count = count + 1;
    }
    printf("\n%d", count);
}

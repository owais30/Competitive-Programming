#include <iostream>
#include<algorithm>
using namespace std;

struct station
{
    int l, r;
};

bool comp(station a, station b)
{
    return (a.l < b.l);
}

int main()
{
    int l, g;
    while(scanf("%d %d", &l, &g) == 2 && (l | g))
    {
        int gas[g];
        int rad[g];
        station s[g];
        for(int i=0;i<g;i++)
        {
            scanf("%d %d", &gas[i], &rad[i]);
            s[i].l = gas[i] - rad[i];
            s[i].r = gas[i] + rad[i];
        }

            
        sort(s, s+g,comp);
        int ans = 0;
        int v = 0;
        int curr = 0;
        bool ok = false;
        while(v < l)
        {
            ok = false;
            curr = 0;
            for(int i=0;i<g;i++)
                if(s[i].l <= v) 
                {    ok = true;break;}
            if(ok){
            for(int i=0;i<g;i++)
            {
            
                if(s[i].l <= v && s[i].r >= s[curr].r) curr = i;
            }
            v = s[curr].r;
            ans++;}
            else
                break;
                
            if(ans == g && v< l)
            {
                ok = false;
                break;
            }
        }
        if(ok)
        printf("%d\n", g-ans);
        else
        printf("-1\n");
    }
}

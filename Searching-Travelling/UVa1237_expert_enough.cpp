#include <iostream>
#include<string>
using namespace std;

struct car
{
    char name[20];
    int l, h;
};

int main()
{
    int t;
   
    int count, ans, n, am, ts;
    scanf("%d", &t);
    while(t--)
    {
        
        scanf("%d", &n);
        car c[n];
        for(int i=0;i<n;i++)
            scanf("%s %d %d", c[i].name, &c[i].l, &c[i].h);
        
        scanf("%d", &ts);
        
        for(int j =0; j<ts;j++){
            count = 0;
        scanf("%d", &am);
       
        for(int i=0;i<n;i++)
        {
            if(c[i].l <= am && am <= c[i].h)
            {
                ans = i;
                count++;
            }
        }
        
        if(count == 1) printf("%s\n", c[ans].name);
        else printf("UN\n");
    }
    }
}

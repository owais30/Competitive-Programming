#include <iostream>
#include<bits/stdc++.h>
using namespace std;

bool isSafe(pair<int, int> curr, int rm, int cm, int r, int c)
{
    return (curr.first + rm >= 0 && curr.first + rm < r && curr.second + cm >= 0 && curr.second + cm < c);
}

int main()
{
    int t;
    scanf("%d", &t);
    int r, c, n, m;
    int w;
    int even = 0;
    int a, b;
    int odd= 0;
    for(int z=1;z<=t;z++)
    {
        scanf("%d %d %d %d", &r, &c, &n, &m);
        int grid[r][c];
        for(int i=0;i<r;i++)
            for(int j=0;j<c;j++)
                grid[i][j] = 0;
        scanf("%d", &w);
        for(int i=0;i<w;i++)
        {
            scanf("%d %d", &a, &b);
            grid[a][b] = 2;
        }
        int moven[] = {n, n, m, m, -n, -n, -m, -m};
        int movem[] = {m, -m, n, -n, m, -m, n, -n};
        queue<pair<int, int>> q;
        pair<int, int> curr;
        even = 0;
        odd = 0;
        int num = 0;
        q.push(make_pair(0,0));
        while(!q.empty())
        {
            curr = q.front();
            q.pop();
            num = 0;
            int p =0;
            for(int i=0;i<8;i++)
            {
                if(isSafe(curr, moven[i], movem[i], r, c))
                {
                    if(grid[curr.first + moven[i]][curr.second + movem[i]] != 2)
                    num++;
                    if(grid[curr.first + moven[i]][curr.second + movem[i]] == 0)
                    {
                        q.push(make_pair(curr.first+moven[i], curr.second+movem[i]));
                        grid[curr.first + moven[i]][curr.second + movem[i]] = 1;
                        p++;
                    }
                }
            }
            if(num % 2 == 0) even++;
            else odd++;
            printf("grid[%d][%d] %d %d %d\n", curr.first, curr.second, even, odd, p);
            grid[curr.first][curr.second] = 1;
        }
        printf("Case %d: %d %d\n",z, even, odd );
    }
}

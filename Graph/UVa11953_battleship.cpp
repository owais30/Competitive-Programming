#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int mover[] = {1, -1, 0,  0};
int movec[] = {0,  0, 1, -1};

void replace(string grid[], char ch1, char ch2, int i, int j, int n)
{
    if(grid[i][j] == ch1 || grid[i][j] == '@') grid[i][j] = ch2;
    else return;
    for(int k=0;k<4;k++)
    {
        if(i + mover[k] >= 0 && i + mover[k] < n && j + movec[k] >= 0 && j + movec[k] < n)
            replace(grid, ch1, ch2, i + mover[k], j + movec[k], n);
    }
}

int main()
{
    int t;
    int n;
    scanf("%d", &t);
    for(int z=1;z<=t;z++)
    {
        scanf("%d", &n);
        string grid[n];
        for(int i=0;i<n;i++)
            cin>>grid[i];
        int ans = 0;
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
            {
                if(grid[i][j] == 'x')
                {    
                    replace(grid, 'x', '.', i, j, n);
                    ans++;
                }
            }
        printf("Case %d: %d\n", z, ans);
    }
}

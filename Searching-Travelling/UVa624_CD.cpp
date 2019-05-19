#include <iostream>
using namespace std;

bool isSafe(int sum, int n)
{
    if(sum >n )
    return false;
    else
    return true;
}

int ans = 0;

int findSolution(int n, int d,int tap[], int next,int sum, int curr)
{
    if(next == d) return sum;
    if(sum == n) return sum;
    
    for(int i=next;i<d;i++)
    {
        if(isSafe(sum + tap[i], n))
        {
            ans = max(findSolution(n, d, tap, i+1, sum + tap[i], 1), ans);
        }
    }
    if(curr) return sum;
    else
    return ans;
}

int main()
{
    int n;
    int d;
    while(scanf("%d %d", &n, &d) == 2)
    {
        ans = 0;
        int tap[n];
        for(int i=0;i<d;i++)
            scanf("%d", &tap[i]);
        int ans = findSolution(n ,d, tap, 0, 0, 0);
        printf("%d\n", ans);

    }
}

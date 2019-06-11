#include <iostream>
#include <string>
#include <ctype.h>
#include <sstream>

using namespace std;

string a, b;

int dp[100][100];

int palindrome(int l, int r)
{
    if(l == r) return 1;
    if(l+1 == r) return (a[l] == a[r] ? 2 : 1);
    if(dp[l][r] != -1) return dp[l][r];
    if(a[l] == a[r]) return dp[l][r] = (palindrome(l+1, r-1) + 2);
    else return dp[l][r] = (max(palindrome(l+1, r), palindrome(l, r-1)));
}

int main()
{
    cin>>a;
    for(int i=0;i<100;i++)
        for(int j=0;j<100;j++)
            dp[i][j] = -1;
    cout<<palindrome(0, a.length()-1);       
}

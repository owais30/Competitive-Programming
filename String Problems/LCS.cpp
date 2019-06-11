#include <iostream>
#include <string>
#include <ctype.h>
#include <sstream>

using namespace std;

string a, b;

int dp[100][100];

int main()
{
    cin>>a>>b;
    for(int i=0;i<=a.length();i++)
        dp[i][0] = 0;
    for(int i=0;i<=b.length();i++)
        dp[0][i] = 0;
    
    for(int i=1;i<=a.length();i++)
        for(int j=1;j<=b.length();j++)
        {
            dp[i][j] = dp[i-1][j-1] + (a[i-1] == b[j-1] ? 1 : 0);
            dp[i][j] = max(dp[i][j], dp[i-1][j]);
            dp[i][j] = max(dp[i][j], dp[i][j-1]);
        }
    for(int i=0;i<=a.length();i++){
        for(int j=0;j<=b.length();j++)
            cout<<dp[i][j]<<" ";
        cout<<endl;
    }        
}

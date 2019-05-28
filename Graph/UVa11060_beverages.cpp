#include<bits/stdc++.h>

using namespace std;
map<string, int> m;
int c = 1;
int main()
{
    int t;
    int f;
    
    string s1, s2;
    while(scanf("%d", &t) != EOF)
    {
        m.clear();
    string str[t];
    int grid[t][t];
    int conn[t], pushed[t];
    for(int i=0;i<t;i++)
    {    for(int j=0;j<t;j++)
            grid[i][j] = 0;
    conn[i] = 0;pushed[i]=0;}
    for(int i=0;i<t;i++)
    {    
        cin>>str[i];
        m.insert(pair<string , int>(str[i], i));
    }
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>s1>>s2;
        grid[m.find(s1)->second][m.find(s2)->second] = 1;
        conn[m.find(s2)->second]++;
    }

    queue<int> q, ans;
    
    for(int i=0;i<t;i++)
        if(conn[i] == 0)
            {q.push(i);pushed[i] = 1;}
    while(!q.empty())
    {
        int tar = q.front();
        ans.push(tar);
        q.pop();
        for(int i=0;i<t;i++)
            if(grid[tar][i] == 1)
            {
                grid[tar][i] = 0;
                conn[i]--;
            }
        for(int i=0;i<t;i++)
            if(conn[i] == 0 && pushed[i] == 0)
             {   q.push(i); pushed[i] = 1;}
    }
    cout<<"Case #"<<c<<": Dilbert should drink beverages in this order:";
    while(!ans.empty())
    {
        cout<<" "<<str[ans.front()];
        ans.pop();
    }
    c++;
    cout<<".\n";
    }
}

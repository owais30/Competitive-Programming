#include <iostream>
#include<queue>
#include<vector>
#include<utility>
#include<string>
#include<algorithm>
#include<sstream>
#include<map>

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<string> vstring;
typedef queue<string> qs;


vstring vs;


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        
        string t, u;
        vs.clear();
        string s;
        while(cin>>s && s != "*")
        {
            vs.push_back(s);
        }
        
        cin.ignore();
        string line;
        int ans = 0;
        while(getline(cin, line) && line != "")
        {
            
            stringstream ss(line);
            ss>>s>>t;
            qs q;
            q.push(s);
            map<string, int> dist;
            dist[u] = 0;
            while(!q.empty())
            {
                u = q.front();q.pop();
                string v;
                int diff;
                for(int i=0;i<(int)vs.size();i++)
                {
                    diff = 0;
                    v = vs[i];
                    if(v.length() != u.length()) continue;
                    for(int j=0;j<(int)u.length(); j++)
                    {
                        if(v[j] != u[j]) diff++;
                        if(diff >= 2) break;
                    }
                    if(diff == 1)
                    {
                        dist[v] = dist[u] + 1;
                        if(v == t) {
                            while(!q.empty()) 
                            q.pop();
                        ans = dist[t];
                        break;}
                        q.push(v);
                    }
                }
                
            }
            cout<<s<<" "<<t<<" "<<ans<<endl;
        }
        
        
    }
}

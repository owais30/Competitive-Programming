#include <bits/stdc++.h>
#include <boost/algorithm/string.hpp>
using namespace std;

int main()
{
    char ch[] = "Hello!! Friends";
    string s(ch);
    cout<<strlen(ch)<<s.length()<<endl;
    reverse(s.begin(), s.end());
    cout<<s<<endl;
    vector<string> vs;
    boost::split(vs, s, boost::is_any_of(" "));
    for(string s: vs) cout<<s<<endl;
    char c[s.length()-1];
    strcpy(c, s.c_str());
    cout<<c<<endl;
    sort(vs.begin(), vs.end());
    for(string s: vs) {reverse(s.begin(), s.end());cout<<s<<endl;}
    return 0;
}

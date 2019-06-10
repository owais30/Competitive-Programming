#include<iostream>
#include<string>
#include<ctype.h>
#include<cstring>

using namespace std;

int x[] = {1, 0, -1, 0};
int y[] = {0, 1, 0, -1};

int n;
string mat[100];
string pat;
int t_k;

bool isSafe(int new_x, int new_y, char ch){
    if(new_x >=0 && new_x < n && new_y >=0 && new_y < n && mat[new_x][new_y] == ch)
        return true;
    return false;
}

bool findSolution(int curr_x, int curr_y, unsigned int matched, int start_x, int start_y, bool first)
{
    //cout<<"curr_x: "<<curr_x<<" curr_y: "<<curr_y<<endl;
    if(matched == pat.length()){
        printf("%d,%d %d,%d\n", start_x+1,start_y+1,curr_x+1, curr_y+1);
        return true;
    }
    
    for(int k=0;k<4;k++){
        if(first){
        if(isSafe(curr_x + x[k], curr_y + y[k], pat[matched])){
            t_k = k;
            if(findSolution(curr_x+x[k], curr_y + y[k], matched+1, start_x, start_y, false))
            {
                return true;
            }}
        }
        else
        {
            if(isSafe(curr_x + x[t_k], curr_y + y[t_k], pat[matched])){
            if(findSolution(curr_x+x[t_k], curr_y + y[t_k], matched+1, start_x, start_y, false))
            {
                return true;
            }}
        }
    }
    return false; 
}

int main()
{
    
    bool ans = false;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>mat[i];
    while(1)
    {
        cin>>pat;
        
        if(pat == "0") break;
        cout<<pat<<": ";
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)
                if(pat[0] == mat[i][j])
                {
                    ans = findSolution(i, j, 1, i, j, true);
                    if(ans) break;
                }
            if(ans) break;
        }    
        if(ans == false){cout<<"Not FOUND"<<endl;}
    }
    return 0;
}

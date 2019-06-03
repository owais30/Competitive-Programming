#include <iostream>
#include <vector>
using namespace std;

const static int N = 100;
const static int INF = 1000;

int main()
{    
    int Case = 1;   
    int a, b;
    while (cin >> a >> b, !(a == 0 && b == 0))
    {
        vector<vector<int> > adj(N + 1, vector<int>(N + 1, INF));

        do {
            adj[a][b] = 1;
        } while (cin >> a >> b, !(a == 0 && b == 0));

        for (int k = 1; k <= N; ++k)
            for (int i = 1; i <= N; ++i)
                for (int j = 1; j <= N; ++j)
                    adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);

        int sum = 0, count = 0;
        for (int i = 1; i <= N; ++i)
            for (int j = 1; j <= N; ++j)
                if (i != j && adj[i][j] != INF)
                {
                    sum += adj[i][j];
                    ++count;
                }
            
        cout << "Case "<< Case++<< ": average length between pages = "<< (double)sum / count<< " clicks"<< endl;
    }
    
}

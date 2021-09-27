
const int N = 2e6+10;

vector<int> g[N], gt[N];
int vis[N], comp[N];
vector<int> order, result;
int sz = 0;
int cc;

void add_edge(int x, int y)
{
	g[x].push_back(y);
	gt[y].push_back(x);
}

void add_disjunction(int x, int y)
{
	add_edge(x^1, y);
	add_edge(y^1, x);
}

void dfs(int u)
{
	if(vis[u] == 1) return;
	vis[u] = 1;
	for(int v: g[u])
		dfs(v);
	order.push_back(u);
}

void dfs(int u ,int cnt)
{
	if(comp[u]) return;
	comp[u] = cnt;
	for(int v: gt[u])
		dfs(v, cnt);
}

bool solve2sat()
{
	for(int i=1; i<=sz*2+1; i++)
		dfs(i);
	reverse(order.begin(), order.end());
	for(int x: order)
		if(comp[x] == 0)
		{
			cc++;
			dfs(x, cc);
		}
	for(int i=1; i<=sz; i++)
	{
		if(comp[i*2] == comp[2*i+1]) return 0;
		else if(comp[i*2] > comp[i*2+1]) result.push_back(i);
	}
	return true;
}

int main()
{
	
}

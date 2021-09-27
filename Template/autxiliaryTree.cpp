const int maxn = 2e5+10;
vector<int> g[maxn], gvt[maxn];
bool important[maxn];
vector<int> node;
int ct = 0;
int parent[maxn][20];
int st[maxn], ed[maxn];
int level[maxn];

void dfs(int u, int par=0, int l = 0)
{
	parent[u][0] = par;
	level[u] = l;
	for(int i=1; i<20; i++){
		if(parent[u][i-1] == 0) break;
		parent[u][i] = parent[parent[u][i-1]][i-1];
	}
	st[u] = ++ct;
	for(int v: g[u]){
		if(v == par) continue;
		dfs(v, u, l+1);
	}
	ed[u] = ct;
}

bool upper(int u, int v){
	return (st[u] <= st[v] && ed[v] <= ed[u]);
}

int lca(int u, int v)
{
	if(upper(u, v)) return u;
	if(upper(v, u)) return v;
	
	for(int i=19; i>=0; i--){
		if(parent[u][i] != 0 && !upper(parent[u][i], v)){
			u = parent[u][i];
		}
	}
	assert(upper(parent[u][0], v) && parent[u][0] != 0);
	return parent[u][0];
}

bool cmp(int u, int v){
    if(st[u] == st[v]) return u < v;
    return st[u] < st[v];
}

int virtual_tree()
{
	vector<int> vec;
	for(int x: node) vec.push_back(x);
	assert(vec.size() != 0);
	sort(vec.begin(), vec.end(), cmp);
	int k = node.size();
	//if(p)cout << k << endl;
	for(int i=0; i<k-1; i++){
		vec.push_back(lca(vec[i], vec[i+1]));
	} 
	sort(vec.begin(), vec.end(), cmp);
	vec.erase(unique(vec.begin(), vec.end()), vec.end());
	for(int x: vec) gvt[x].clear();
	vector<int> stck;
	stck.push_back(vec[0]);
	for(int i = 1; i <(int)vec.size(); i++){
		int cur = vec[i];
		while(stck.size() >= 2 && !upper(stck.back(), cur)) {
			gvt[stck[stck.size()-2]].push_back(stck.back());
            gvt[stck.back()].push_back(stck[stck.size()-2]);
			stck.pop_back();
		}
		stck.push_back(vec[i]);
	}
	while(stck.size() >= 2){
		gvt[stck[stck.size()-2]].push_back(stck.back());
        gvt[stck.back()].push_back(stck[stck.size()-2]);
		stck.pop_back();
	}
	assert(stck.size() == 1);
	return stck.back();
}

// use
// verified 613D
// modified on 1111E
int n;
cin >> n;
for(int i=0; i<n-1; i++){
	int u, v;
	cin >> u >> v;
	g[u].push_back(v);
	g[v].push_back(u);
}
dfs(1, 0);
int q;
cin >> q;
for(int itr=0; itr<q; itr++){
	int k;
	cin >> k;
	node.clear();
	node.resize(k);
	for(int i=0; i<k; i++) cin >> node[i];
	for(int x: node) important[x] = true;
	int root = virtual_tree();
	ans = 0;
	ignore = solve(root);
	cout << ans << endl;
	for(int x: node) important[x] = false;
}


// basic testing on 163E

// not complete 
// need improvements in code
// TODO: template use


const int MAXN = (1 << 20); //  > 10 ^ 6
const int OFFSET = 5; // offset to avoid infinite looping

// fenwick tree with query down and update up
struct fenwick_tree
{
	int tr[MAXN];
	int sz;
 
	void clear() { memset(tr, 0, sizeof(tr)); }
	void init(int _sz) { clear(); sz = OFFSET + _sz + 1; }
	
	int query(int idx)
	{
		idx += OFFSET;
 
		int ans = 0;
		for(; idx >= 1; idx -= (idx & -idx))
			ans += tr[idx];
 
		return ans;
	}
 
	void update(int idx, int val)
	{
		idx += OFFSET;
		for(; idx <= sz; idx += (idx & -idx))
			tr[idx] += val;
	}	
};
 
struct aho_corasick
{
	int psz, link[MAXN];
	map<char, int> to[MAXN];
	vector<int> leaves;
	vector<int> adj[MAXN];
	int st[MAXN], en[MAXN], dfs_time;
	int is_inside[MAXN];
	fenwick_tree t;
 
	void clear() 
	{
		for(int i = 0; i < psz; i++) is_inside[i] = 0;
		for(int i = 0; i < psz; i++)
			adj[i].clear(), link[i] = 0, to[i].clear();
 
		t.clear();
		leaves.clear();
		psz = 1;
	}
 
	aho_corasick() { memset(link, 0, sizeof(link)); psz = 0; clear(); }
 
	void add_word(string s)
	{
		int curr_node = 0;
		for(char c: s)
		{
			if(!to[curr_node][c]) 
				to[curr_node][c] = (psz++);
		
			curr_node = to[curr_node][c];
		}
 
		leaves.push_back(curr_node); // leaves of every string ith string have leaves = leaves[i]
		is_inside[leaves.size() - 1] = 0; // inside or removed from trie
	}
 
	void push_links()
	{
		queue<int> Q;
		int u, v, j;
		char c;
 
		link[0] = -1;
		Q.push(0);
 
		while(!Q.empty())
		{
			u = Q.front();
			Q.pop();
 
			for(auto it: to[u])
			{
				v = it.second;
				c = it.first;
				j = link[u];
 
				while(j != -1 && !to[j].count(c)) j = link[j];
				if(j != -1) link[v] = to[j][c];
				else link[v] = 0;
			
				Q.push(v);
			}
		}
	}
 
	int query(string s)
	{
		int ans = 0, u = 0;
 
		for(char c: s)
		{
			while(u >= 0 && !to[u].count(c)) u = link[u]; 
			if(u != -1) { u = to[u][c]; ans += t.query(st[u]); }
			// ans += t.query(st[u])  parent sum technique
			// ans += t.query(ed[u])  child sum technique
			else u = 0;
		}
 
		return ans;
	}
 
	void build_graph()
	{
		for(int i = 1; i < psz; i++)
			adj[link[i]].push_back(i);
		cerr << "Suffix Tree Ready!" << endl;
		// reverse of suffix links is tree edge
	}
 
	void pre_dfs(int u)
	{
		st[u] = ++dfs_time;
		for(int v: adj[u])
			pre_dfs(v);
		en[u] = dfs_time;
	}
 
	void print_dfs(string s, int u)
	{
		cout << s << ": " << u << " -> " << t.query(st[u]) << " " << st[u] << ", " << en[u] << "    link: " << link[u] << endl;
		for(auto it: to[u])
			if(it.second)
				print_dfs(s + it.first, it.second);
	}
	
	void insert(int idx)
	{
		if(is_inside[idx]) return;
 
		t.update(st[leaves[idx]], 1);
		t.update(en[leaves[idx]] + 1, -1);
		is_inside[idx] = 1;
	}
 
	void erase(int idx)
	{
		if(!is_inside[idx]) return;
 
		t.update(st[leaves[idx]], -1);
		t.update(en[leaves[idx]] + 1, 1);
		is_inside[idx] = 0;
	}
 
	void init()
	{
		push_links();
		build_graph();
		dfs_time = 0;
		pre_dfs(0);
		t.init(dfs_time);
 
		for(int i = 0; i < (int)leaves.size(); i++)
			insert(i);
		cerr << "Aho-Corasick Ready!" << endl;
	}
};

aho_corasick aho;

// Aho-corasick algorithm
// Code hos.lyric contest 963/D

const int N = 1e6+10;
const int A = 26;
int nxt[N][A];
int fail[N];
vector<int> ac[N], matches[N];
int V = 0;
int root = 0;
int L[N];

int newNode(){
	const int u = V++;
	fill(nxt[u], nxt[u]+A, -1);
	ac[u].clear();
	return u;
}

void bfs()
{
	queue<int> q;
	q.push(root);
	while(!q.empty()){
		int c = q.front();
		q.pop();
		for(int a = 0; a < A; a++){
			int &v = nxt[c][a];
			if(v != -1){
				fail[v] = (c == 0) ? 0 : nxt[fail[c]][a];
				ac[v].insert(ac[v].end(), ac[fail[v]].begin(), ac[fail[v]].end());
				q.push(v);
			}
			else{
				v = (c == 0) ? 0 : nxt[fail[c]][a];
			}
		}
	}
}

void add_string(string s, int id)
{
	L[id] = (int)s.length();
	int u = root;
	for(int i=0; i<(int)s.length(); i++){
		int c = s[i] - 'a';
		int &v = nxt[u][c];
		if(v == -1) {
			v = newNode();
		}
		u = v;
	}
	ac[u].push_back(id);
}

void prepare(vector<string> vs, string S)
{
	V = 0;
	newNode();
	for(int i=0; i<N; i++) matches[i].clear();
	int id = 0;
	for(string s: vs) add_string(s, id++);
	bfs();
	int u = root;
	for(int i=0; i<(int)S.length(); i++){
		int c = S[i] - 'a';
		u = nxt[u][c];
		for(const int j: ac[u]){
			matches[j].push_back(i + 1);
		}
	}
}

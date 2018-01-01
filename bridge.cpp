#define N 100000
struct edge {
  int src, dst;
  edge(int s, int d)
    : src(s), dst(d) { }
};

typedef vector<edge> vertex;
typedef vector<vertex> graph;

int c[N], cc[N];

void visit(graph &g, int v, int u, vertex &br, vector<vector<int> > &te, stack<int> &roots, stack<int> &S, vector<bool> &inS, vector<int> &num, int &time){
	num[v] = ++time;
	S.push(v); inS[v] = true;
	roots.push(v);
	for(auto e: g[v]){
		int w = e.dst;
		if(num[w]==0)
			visit(g, w, v, br, te, roots, S, inS, num, time);
		else if(u!=w && inS[w])
			while(num[roots.top()] > num[w]) roots.pop();
	}
	if(v==roots.top()){
		br.push_back(edge(u, v));
		te.push_back(vector<int>());
		while(1){
			int w = S.top(); S.pop(); inS[w] = false;
			te.back().push_back(w);
			if(v==w) break;
		}
		roots.pop();
	}
}

void bridge(graph &g, vertex &br, vector<vector<int> > &te){
	int n = g.size();
	vector<int> num(n);
	vector<bool> inS(n);
	stack<int> roots, S;
	int time = 0;
	for(int u = 0; u < n; u++){
		if(num[u] == 0){
			visit(g, u, n, br, te, roots, S, inS, num, time);
			br.pop_back();
		}
	}
}

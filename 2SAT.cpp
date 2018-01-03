// from http://www.prefield.com/algorithm/misc/2-sat.html (spagetthi source logo)
#define VAR(x) ((x)<<1)
#define NOT(x) ((x)^1)

void visit(int v, vector<vector<int>> &g, vector<int> &ord, vector<int> &num, int k){
	if(num[v]>=0) return;
	num[v] = k;
	rep(i, g[v].size()){
		visit(g[v][i], g, ord, num, k);
	}
	ord.pb(v);
}

bool twoSAT(int m, vector<P> &cs){
	int n = m*2;
	vector<vector<int>> g(n), h(n);
	rep(i, cs.size()){
		int u = cs[i].fst, v = cs[i].snd;
		g[NOT(u)].pb(v);
		g[NOT(v)].pb(u);
		h[v].pb(NOT(u));
		h[u].pb(NOT(v));
	}
	vector<int> num(n, -1), ord, dro;
	rep(i, n) visit(i, g, ord, num, i);
	reverse(all(ord));
	fill(all(num), -1);
	rep(i, n) visit(ord[i], h, dro, num, i);
	rep(i, n) if(num[i]==num[NOT(i)]) return false;
	return true;
}

#define V 1100
struct edge{ll to, cap, rev;};
vector<edge> G[V];
ll level[V];
int iter[V];

void add_edge(ll from, ll to, ll cap){
	G[from].push_back((edge){to, cap, (ll)G[to].size()});
	G[to].push_back((edge){from, 0LL, (ll)G[from].size()-1});
	//G[to].push_back((edge){from, cap, G[from].size()-1});
}

void bfs(int s){
	memset(level, -1, sizeof(level));
	queue<int> q;
	level[s] = 0;
	q.push(s);
	while(!q.empty()){
		int v = q.front(); q.pop();
		for(auto &&e: G[v]){
			if(e.cap>0 && level[e.to]<0){
				level[e.to] = level[v]+1;
				q.push(e.to);
			}
		}
	}
}

ll dfs(int v, int t, ll f){
	if(v==t) return f;
	for(int &i = iter[v]; i < (int)G[v].size(); i++){
		edge &e = G[v][i];
		if(e.cap>0 && level[v]<level[e.to]){
			ll d = dfs(e.to, t, min(f, e.cap));
			if(d>0){
				e.cap -= d;
				G[e.to][e.rev].cap += d;
				return d;
			}
		}
	}
	return 0;
}

ll max_flow(int s, int t){
	ll flow = 0;
	while(bfs(s), level[t]>=0){
		memset(iter, 0, sizeof(iter));
		ll f;
		while((f = dfs(s, t, INF))>0) flow += f;
	}
	return flow;
}

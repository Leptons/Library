#define V 10010

struct edge {
  int to, cap, cost, rev;

};
typedef vector<edge> vertex;
typedef vector<vertex> graph;
int dist[V];
int h[V];
int prevv[V], preve[V];


graph g;

void add_edge(int from, int to, int cap, int cost){
	//cout<<from<<" "<<to<<" "<<cap<<" "<<cost<<endl;
	g[from].push_back((edge){to, cap, cost, (int)g[to].size()});
	g[to].push_back((edge){from, 0, -cost, (int)g[from].size()-1});
}

int min_cost_flow(int s, int t, int f){
	int res = 0;
	fill(h, h+V, 0);
	// Bellman-Ford
	/* 
	for(int i = 0; i < V; i++){
		for(int j = 0; j < g[i].size(); j++){
			edge &e = g[i][j];
			if(e.cap == 0) continue;
			int u = e.to;
			h[u] = min(h[u], h[i]+e.cost);
		}
	}
	*/
	while(f>0){
		priority_queue<P, vector<P>, greater<P> > q;
		fill(dist, dist+V, INF);
		dist[s] = 0;
		q.push(P(0,s));
		while(!q.empty()){
			P p = q.top(); q.pop();
			int v = p.second;
			if(dist[v] < p.first) continue;
			for(int i = 0; i < g[v].size(); i++){
				edge &e = g[v][i];
				if(e.cap > 0 && dist[e.to] > dist[v] + e.cost + h[v] - h[e.to]){
					dist[e.to] = dist[v] + e.cost + h[v] - h[e.to];
					prevv[e.to] = v;
					preve[e.to] = i;
					q.push(P(dist[e.to],e.to));
				}
			}
		}
		if(dist[t] == INF){
			return -1;
		}
		for(int v = 0; v < V; v++)h[v] += dist[v];

		int d = f;
		for(int v = t; v != s; v = prevv[v]){
			d = min(d, g[prevv[v]][preve[v]].cap);
		}
		f -= d;
		res += d*h[t];
		for(int v = t; v != s; v = prevv[v]){
			edge &e = g[prevv[v]][preve[v]];
			e.cap -= d;
			g[v][e.rev].cap += d;
		}
	}
	return res;
}

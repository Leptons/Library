#include <iostream>
#include <vector>
#include <queue>
#define INF (100000*10000)
using namespace std;
struct edge{
	int dst, len;
	edge(int d, int l)
		: dst(d), len(l) {}
};
bool operator < (const edge& e, const edge& f){
	return e.len>f.len;
}
typedef vector<edge> vertex;
typedef vector<vertex> graph;

graph g;
int V, E, r;
int dist[100000];

void dijkstra(int r){
	fill(dist, dist+V, INF);

	priority_queue<edge> q;
	dist[r] = 0;
	q.push(edge(r, 0));
	while(!q.empty()){
		edge e = q.top(); q.pop();
		if(e.len > dist[e.dst]) continue;
		for(auto f : g[e.dst]){
			if(e.len+f.len < dist[f.dst]){
				dist[f.dst] = e.len+f.len;
				q.push(edge(f.dst, dist[f.dst]));
			}
		}
	}
}

int main(){
	cin>>V>>E>>r;
	g = graph(V);
	for(int i = 0; i < E; i++){
		int s, t, d;
		cin>>s>>t>>d;
		g[s].push_back(edge(t,d));
		//g[t].push_back(edge(s,d)); //if directed graph
	}

	dijkstra(r);

	for(int i = 0; i < V; i++){
		if(dist[i]==INF) cout<<"INF"<<endl;
		else cout<<dist[i]<<endl;
	}

	return 0;
}


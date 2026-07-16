#include <bits/stdc++.h>
using namespace std;

int dfs (int u,int p,const vector<vector<pair<int,int>>> &adj){
	if(u==1){
		return 0;
	}
	for(auto edge:adj[u]){
		int v=edge.first;
		int penalty=edge.second;

		if(v!=p){
			return penalty + dfs(v,u,adj);
		}
	}
	return 0;
}

int main(){
	int n;
	cin>>n;

	vector<vector<pair<int,int>>> adj(n+1);
	int total_cost=0;

	for(int i=0;i<n;i++){
		int u,v,c;
		cin>>u>>v>>c;

		total_cost+=c;

		//Forward edge: follows traffic, cost is 0
		adj[u].push_back({v,0});
		//Reverse edge: against traffic, must pay 'c' to redirect
		adj[v].push_back({u,c});
	}

	//Node 1 has exactly 2 neighbors. We manually take the first step down one of those paths.
	int next_node = adj[1][0].first;
	int first_penalty = adj[1][0].second;

	//The cost of this cycle is our first step's penalty + the result of the DFS
	int path_cost = first_penalty + dfs(next_node,1,adj);

	//The answer is the minimum of travelling the ring clockwise vs counter-clockwise
	cout<<min(path_cost,total_cost-path_cost)<<"\n";

	return 0;
}

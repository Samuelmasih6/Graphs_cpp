//problem: https://codeforces.com/contest/796/problem/D
#include <bits/stdc++.h>
using namespace std;

int n,k,d;
//adj stores pairs of {neighbor city, original road index}
vector<vector<pair<int,int>>> adj;
vector<bool> visited;
vector<bool> edge_used;

int main(){
	cin>>n>>k>>d;

	adj.resize(n+1);
	visited.assign(n+1,false);
	edge_used.assign(n,false);

	queue<int> q;

	//1. Multi-source initialization
	for(int i=0; i<k; i++){
		int p;
		cin>>p;

		//avoid adding duplicate police stations
		if(!visited[p]){
			q.push(p);
			visited[p]=true;
		}
	}

	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		adj[u].push_back({v,i});
		adj[v].push_back({u,i});
	}

	//2. Domain expansion
	while(!q.empty()){
		int u=q.front();
		q.pop();

		for(auto[v,idx]:adj[u]){
			//if the city is unvisited, claim it and keep the road!
			if(!visited[v]){
				visited[v]=true;
				edge_used[idx]=true;
				q.push(v);
			}
		}
	}

	//3. The cleanup
	vector<int> deleted_roads;
	for(int i=1;i<n;i++){
		if(!edge_used[i]){
			deleted_roads.push_back(i);
		}
	}
	cout<<deleted_roads.size()<<endl;
	for(int road:deleted_roads){
		cout<<road<<" ";
	}
	cout<<"\n";
	return 0;
}

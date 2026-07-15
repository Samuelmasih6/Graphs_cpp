//problem: https://cses.fi/problemset/task/1666

#include <bits/stdc++.h>
#include <vector>
using namespace std;

int n,m;
vector<vector<int>> adj;
vector <bool> visited;

void dfs(int u){
	visited[u]=true;
	for(int v:adj[u]){
		if(!visited[v])
		dfs(v);
	}
}

int main(){
	cin>>n>>m;

	visited.assign(n+1,false);
	adj.resize(n+1);

	for(int i=0; i<n; i++){
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	vector<int>leader;

	for(int i=0;i<n;i++){
		if(!visited[i]){
			leader.push_back(i);
			dfs(i);
		}
	}
	int k= leader.size()-1;
	cout<<k<<endl;

	for(int i=0;i<k;i++){
		cout<<leader[i]<<" "<<leader[i+1]<<" ";
	}

}

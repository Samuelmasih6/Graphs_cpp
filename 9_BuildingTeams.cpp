//problem: https://cses.fi/problemset/task/1668
//
#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<vector<int>> adj;
vector<int>team;

bool dfs(int u){
	for(int v:adj[u]){
		if(team[v]==0){
			team[v]=3-team[u];
			if(!dfs(v)){
				return false;
			}
		} else if(team[v]==team[u]){
			return false;
		}
	}
	return true;
}

int main(){
	cin>>n>>m;

	adj.resize(n+1);
	team.resize(n+1,0);

	for(int i =0;i<m;i++){
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	for(int i=1;i<=n;i++){
		if(team[i]==0){
			team[i]=1;
			if(!dfs(i)){
				cout<<"IMPOSSIBLE\n";
				return 0;
			}
		}
	}

	for(int i=1;i<=n;i++){
		cout<<team[i]<<" ";
	}
	cout<<"\n";

	return 0;
}

// input
// 5 3
// 1 2
// 1 3
// 4 5
// output
// 1 2 2 1 2

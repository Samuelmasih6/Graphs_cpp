//problem: https://codeforces.com/contest/813/problem/C

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
int n,x;
vector<int>distA,distB;

void dfs(int u, int p,int d,vector<int>&dist){
	dist[u]=d;

	for(int v:adj[u]){
		if(v!=p){
			dfs(v,u,d+1,dist);
		}
	}
}

int main(){
	cin>>n>>x;
	adj.resize(n+1);
	distA.resize(n+1,0);
	distB.resize(n+1,0);

	for(int i=0;i<n-1;i++){
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	dfs(1,0,0,distA);
	dfs(x,0,0,distB);

	int ans=0;
	for(int i=1;i<=n;i++){
		if(distB[i]<distA[i]){
			ans=max(ans,distA[i]*2);
		}
	}
	cout<<ans<<"\n";
	return 0;
}

//input
// 4 3
// 1 2
// 2 3
// 2 4
//output
// 4
//
// 5 2
// 1 2
// 2 3
// 3 4
// 2 5
//
// 6

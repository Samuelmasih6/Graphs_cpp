//problem: https://codeforces.com/contest/862/problem/B
//

#include <bits/stdc++.h>
using namespace std;

int n;
vector <vector<int>> adj;
long long cnt[2];

void dfs(int u,int p,int color){
	cnt [color]++;

	for(int v:adj[u]){
		if(v!=p){
			dfs(v,u,1-color);
		}
	}
}

int main(){
	cin>>n;
	adj.resize(n+1);

	for(int i=0;i<n-1;i++){
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	dfs(1,0,0);

	long long max_possible_edges = cnt[0]*cnt[1];
	long long ans = max_possible_edges-(n-1);
	cout<<ans<<"\n";
	return 0;
}

//input
// 3
// 1 2
// 1 3
//output
// 0
//
// 5
// 1 2
// 2 3
// 3 4
// 4 5
//
// 2

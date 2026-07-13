//problem: https://codeforces.com/problemset/problem/580/C
#include <bits/stdc++.h>
using namespace std;

int n,m;
vector <int> has_cat;
vector<vector<int>> adj;
int valid_restaurants=0;

void dfs(int u,int p, int consecutive_cats){
	if(has_cat[u]==1) consecutive_cats++;
	else consecutive_cats=0;

	if(consecutive_cats>m) return;

	bool is_leaf =true;

	for(int v:adj[u]){
		if(v!=p){
			is_leaf=false;
			dfs(v,u,consecutive_cats);
		}
	}

	if(is_leaf){
		valid_restaurants++;
	}
}

int main(){
	cin>>n>>m;

	has_cat.resize(n+1);
	adj.resize(n+1);

	for(int i=1;i<=n;i++){
		cin>>has_cat[i];
	}

	for(int i=0;i<n-1;i++){
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	dfs(1,0,0);

	cout <<valid_restaurants<<"\n";
}

//input
// 4 1
// 1 1 0 0
// 1 2
// 1 3
// 1 4
// output
// 2

// input
// 7 1
// 1 0 1 1 0 0 0
// 1 2
// 1 3
// 2 4
// 2 5
// 3 6
// 3 7
// output
// 2

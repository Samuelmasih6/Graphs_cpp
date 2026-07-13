//problem: https://cses.fi/problemset/task/1674

#include <bits/stdc++.h>
using namespace std;

int n;
vector <vector<int>> adj;
vector <int> sub;

void dfs(int u){
	sub[u]=0;

	for(int v:adj[u]){
		dfs(v);
		sub[u]+=sub[v]+1;
	}
}

int main(){
	cin>>n;
	adj.resize(n+1);
	sub.assign(n+1,0);

	for(int i=2;i<=n;i++){
		int boss;
		cin>>boss;
		adj[boss].push_back(i);
	}

	dfs(1);

	for(int i=1;i<=n;i++){
		cout<<sub[i]<<" ";
	}
	cout<<"\n";
}


//Input:

// 5
// 1 1 2 3
// Output:

// 4 1 1 0 0

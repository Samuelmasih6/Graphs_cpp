//problem:https://codeforces.com/contest/1144/problem/F

#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<vector<int>>adj;
vector<int>color;

bool dfs(int u,int c){
	color[u]=c;
	for(int v:adj[u]){
		if(color[v]==-1){
			if(!dfs(v,1-c)){
				return false;
			}
		}else if(color[v]==color[u]){
			return false;
		}
	}
	return true;
}

int main(){
	cin>>n>>m;

	adj.resize(n+1);
	color.resize(n+1,-1);
	vector<pair<int,int>>edges(m);

	for(int i=0;i<m;i++){
		int u,v;
		cin>>u>>v;
		edges[i]={u,v};
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	if(!dfs(1,0)){
		cout<<"NO\n";
	}else{
		cout<<"YES\n";

		for(int i=0;i<m;++i){
			int u=edges[i].first;

			if(color[u]==0){
				cout<<"0";
			}else{
				cout<<"1";
			}
		}
		cout<<"\n";
	}
	return 0;
}


//input
// 6 5
// 1 5
// 2 1
// 1 4
// 3 1
// 6 1
//output
// YES
// 10100

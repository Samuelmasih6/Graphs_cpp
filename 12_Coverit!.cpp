//problem: https://codeforces.com/contest/1176/problem/E
#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<vector<int>>adj;
vector<bool> visited;

vector<int>color_0;
vector<int>color_1;

void dfs(int u,int c){
	visited[u]=true;

	if(c==0){
		color_0.push_back(u);
	} else{
		color_1.push_back(u);
	}

	for(int v:adj[u]){
		if(!visited[v]){
			dfs(v,1-c);
		}
	}
}

void solve(){
	cin>>n>>m;
	 adj.assign(n+1,vector<int>());
		visited.assign(n+1,false);

		color_0.clear();
		color_1.clear();

		for(int i=0;i<m;i++){
			int u,v;
			cin>>u>>v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		dfs(1,0);

		if((int)color_0.size()<=n/2){
			cout<<color_0.size()<<"\n";
			for(int u:color_0){
			cout<<u<<" ";
			}
			cout<<"\n";
		}else{
			cout<<color_1.size()<<"\n";
			for(int u:color_1){
				cout<<u<<" ";
			}
			cout<<"\n";
		}
}
int main(){
	int t;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}

//input
// 2
// 4 6
// 1 2
// 1 3
// 1 4
// 2 3
// 2 4
// 3 4
// 6 8
// 2 5
// 5 4
// 4 3
// 4 1
// 1 3
// 2 3
// 2 6
// 5 6
// output
// 2
// 1 3
// 3
// 4 3 6
// If there are multiple answers, you can print any.

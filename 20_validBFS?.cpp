//problem: http://codeforces.com/contest/1037/problem/D
#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> adj;
vector<int> target_sequence;
vector<int> relative_order;
vector<int> bfs_sequence;
vector<bool> visited;

void bfs(){
	queue <int> q;
	q.push(1);

	visited[1]=true;

	while(!q.empty()){
		int u=q.front();
		q.pop();

		//record the order in which nodes are actually processed
		bfs_sequence.push_back(u);

		for(int v:adj[u]){
			if(!visited[v]){
				visited[v]=true;
				q.push(v);
			}
		}
	}
}

int main(){
	cin>>n;

	adj.resize(n+1);
	target_sequence.resize(n);
	relative_order.resize(n+1);
	visited.assign(n+1,false);

	for(int i=0;i<n-1;i++){
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	for(int i=0;i<n;i++){
		cin>>target_sequence[i];
		relative_order[target_sequence[i]]=i;
	}

	//Sort every adjacency list based on our ustome ranking
	for(int i=1;i<=n;++i){
		sort(adj[i].begin(0,adj[i].end(),[&](int a, int b){
			return relative_order[a]<relative_order[b];
		});
	}

	bfs();

	if(bfs_sequence==target_sequence){
		cout<<"YES\n";
	} else{
		cout<<"NO\n";
	}
	return 0;

}

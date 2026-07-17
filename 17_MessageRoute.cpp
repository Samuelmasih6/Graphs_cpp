//problem: https://cses.fi/problemset/task/1667
#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<vector<int>> adj;
vector<int> parent;
vector<bool>visited;

void bfs(int start){
	queue<int>q;

	//1. Initialize the start node
	q.push(start);
	visited[start]=true;

	//2. Process the queue layer by layer
	while(!q.empty()){
		int u = q.front();
		q.pop();

		//3. Explore neighbors
		for(int v:adj[u]){
			if(!visited[v]){
				visited[v]=true;

				// "To get to v, I came from u"
				parent[v] = u;

				q.push(v);
			}
		}
	}

}
int main(){
	cin>>n>>m;
	adj.resize(n+1);
	// Initialize parents to -1 (meaning no parent)
	parent.resize(n+1,-1);
	visited.resize(n+1,false);

	for(int i=0;i<m;++i){
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	bfs(1);

	if(!visited[n]){
		cout<<"IMPOSSIBLE\n";
		return 0;
	}

	vector<int> path;

	//reconstruct the path
	// start at n, walk backward using the parent array until er hit -1

	for(int curr = n; curr !=-1; curr = parent[curr]){
		path.push_back(curr);
	}

	reverse(path.begin(),path.end());

	cout<<path.size()<<"\n";
	for(int v:path){
		cout<<v<<" ";
	}
	return 0;
}

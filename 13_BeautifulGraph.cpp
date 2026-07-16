//problem: https://codeforces.com/contest/1093/problem/D

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const ll MOD =998244353;
const int MAXN = 300005;

int n,m;
vector<vector<int>> adj(MAXN);
vector<int>color;
ll power_of_2[MAXN];

ll c0,c1;
bool is_bipartite;

void precompute(){
	power_of_2[0] = 1;
	for(int i=1;i<MAXN;i++){
		power_of_2[i]=(power_of_2[i-1]*2)%MOD;
	}
}

void dfs(int u,int c){
	color[u]=c;
	if(c==0)c0++;
	else c1++;

	for(int v:adj[u]){
		if(color[v]==c){
			is_bipartite=false;
		}
		if(color[v]==-1){
			dfs(v, 1-c);
		}
	}
}

void solve(){
	cin>>n>>m;

	adj.assign(n+1,vector<int>());
	color.assign(n+1,-1);

	for(int i=0;i<m;++i){
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	ll total_ways =1;

	for(int i=1;i<=n;++i){
		if(color[i]==-1){
			c0=0;
			c1=0;
			is_bipartite=true;

			dfs(i,0);

			if(!is_bipartite){
			cout<<0<<endl;
			return;
			}

			ll curr_comp_ways = (power_of_2[c0]+power_of_2[c1]) % MOD;
			total_ways=(total_ways*curr_comp_ways)%MOD;
		}
	}
	cout<<total_ways<<endl;
}

int main(){
	precompute();

	int t;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}

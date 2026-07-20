//problem: https://codeforces.com/contest/35/problem/C
#include <iostream>
#include <vector>
#include <queue>
#include <cstdio>

using namespace std;

int n,m,k;

int dr[]={-1,1,0,0};
int dc[]={0,0,-1,1};

int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	cin>>n>>m;

	vector<vector<bool>> visited(n+1,vector<bool>(m+1,false));
	queue<pair<int,int>> q;

	int last_r=1,last_c=1;

	//1. multi source initialization
	//push all starting fires into the queue at distance 0
	for(int i=0;i<k;i++){
		int r,c;
		cin>>r>>c;
		q.push({r,c});
		visited[r][c]=true;

		//in case the forest is full of fire from start
		last_r=r;
		last_c=c;
	}

	//2. the simultaneous wave
	while(!q.empty()){
		int r=q.front().first;
		int c=q.front().second;
		q.pop();

		//continuously update the last visited cell
		last_r=r;
		last_c=c;

		//explore 4 adjacent directions
		for(int i=0;i<4;i++){
			int nr=r+dr[i];
			int nc=c+dc[i];

			//check boundaries (1-based indexing)
			if(nr>=1 && nr<=n && nc>=1 && nc<=m){
				//if unvisited, ignite it and push it to the queue
				if(!visited[nr][nc]){
					visited[nr][nc]=true;
					q.push({nr,nc});
				}
			}
		}
	}

	//3. Print the last cell that caught the fire
	cout<<last_r<<" "<<last_c<<"\n";

	return 0;
}





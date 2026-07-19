//problem: https://cses.fi/problemset/task/3217
#include <bits/stdc++.h>
using namespace std;

int n;

//The 8 possible L-shaped jumps for a Knight
int dr[]={-2,-2,-1,-1,1,1,2,2};
int dc[]={-1,1,-2,2,-2,2,-1,1};

int main(){
	cin>>n;

	//dist array acts as our 'visited' array. -1 means univisted
	vector<vector<int>> dist(n,vector<int>(n,-1));
	queue<pair<int,int>> q;

	//start BFS from the top-left corner(0,0)
	q.push({0,0});
	dist[0][0];

	//process the queue
	while(!q.empty()){
		int r=q.front().first;
		int c=q.front().second;
		q.pop();

		//explore all 8 knights jumps
		for(int i=0;i<8;i++){
			int nr=r+dr[i];
			int nc=c+dc[i];

			//1. Check if the jump is within the board boundaries
			//2. Check if the cell is unvisited
			if(nr>=0 && nr<n && nc>=0 && nc<n){
				if(dist[nr][nc]==-1){
                               		//the distance to the new cell is current distance
                                	dist[nr][nc]=dist[r][c]+1;
                                	q.push({nr,nc});
                        	}
			}
		}
	}

	//Print the fully calculated distance grid
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<dist[i][j]<<(j==n-1?"";" ");
		}
		cout<<"\n";
	}
	return 0;
}

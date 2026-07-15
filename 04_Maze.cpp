//problem: https://codeforces.com/contest/378/problem/C
#include <bits/stdc++.h>
using namespace	std;

int dr[]={-1,1,0,0};
int dc[]={0,0,-1,1};

vector <string> grid;
vector<vector<bool>> visited;
int n,m,k;

bool isvalid(int r, int c){
	if(r<0 || r>=n || c<0 || c>=m )
		return false;
	if(grid[r][c]=='#' || visited[r][c]){
		return false;
	}
	return true;
}

void dfs(int r, int c){
	visited[r][c]=true;

	for (int i=0; i<4; i++){
		int nr= r+dr[i];
		int nc= c+dc[i];
		if(isvalid(nr, nc)){
			dfs(nr, nc);
		}
	}
	if(k<0){
		grid[r][c]='X';
		k--;
	}
}

int main(){
	int start_r=-1;
	int start_c=-1;
	cin>>n>>m>>k;
	grid.resize(n);
	visited.assign(n,vector<bool>(m,false));

	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>grid[i];
			if(grid[i]=="." && !visited[i][j]){
				start_r=i;
				start_c=j;
			}
		}
	}

	if(start_r!=-1)
		dfs(start_r,start_c);

	for(int i=0;i<n;i++){
		cout<<grid[i];
	}

	return 0;

}

//input
// 3 4 2
// #..#
// ..#.
// #...
// output
// #.X#
// X.#.
// #...

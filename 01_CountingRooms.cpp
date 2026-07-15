// problem: https://cses.fi/problemset/task/1192

#include <bits/stdc++.h>
#include <vector>
using namespace std;

vector <string> grid;
vector <vector <bool>> visited;

int dr[]={-1,1,0,0};
int dc[]={0,0,-1,1};

int n, m;
bool isvalid(int r, int c){
	if(r<0 || r>n || c<0 || c>m )
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
}

int main(){
	cin>>n>>m;
	grid.resize(n);
	visited.assign(n, vector<bool>(m,false));

	for(int i=0; i<n; i++){
		cin>>grid[i];
	}

	int rooms=0;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(grid[i][j] == '.' && !visited[i][j]){
				dfs(i,j);
				rooms++;
			}
		}
	}

	cout<<rooms<<endl;

	return 0;
}

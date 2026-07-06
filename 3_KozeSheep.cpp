//problem: https://www.spoj.com/problems/KOZE/

#include <bits/stdc++.h>
using namespace std;

vector <string> grid;
vector <vector <bool>> visited;

int dr[]={-1,1,0,0};
int dc[]={0,0,-1,1};

int n, m;
bool isvalid(int r, int c){
	if(r<0 || r>=n || c<0 || c>=m )
		return false;
	if(grid[r][c]=='#' || visited[r][c]){
		return false;
	}
	return true;
}

void dfs(int r,int c,int &sheep,int &wolves,bool &can_escape){
	visited[r][c] = true;

	if(grid[r][c] == 'k') sheep++;
	if(grid[r][c] == 'v') wolves++;

	if(r==0 || r==n-1 || c==0 || c==m-1){
		can_escape = true;
	}

	for (int i=0; i<4; i++){
		int nr= r+dr[i];
		int nc= c+dc[i];
		if(isvalid(nr, nc)){
			dfs(nr, nc,sheep,wolves,can_escape);
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

	int total_surv_wolves = 0;
	int total_surv_sheep = 0 ;

	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(grid[i][j] != '#' && !visited[i][j]){
				int sector_sheep = 0;
				int sector_wolves = 0;
				bool can_escape  = false;
				dfs(i,j,sector_sheep,sector_wolves,can_escape);

				if(can_escape){
					total_surv_sheep+=sector_sheep;
					total_surv_wolves+=sector_wolves;
				}else{
					if(sector_sheep>sector_wolves){
						total_surv_sheep+=sector_sheep;
					}else{
						total_surv_wolves+=sector_wolves;
					}
				}
			}
		}
	}

	cout<<total_surv_sheep<<" "<<total_surv_wolves;
	return 0;
}

//Input:
// 8 8
// .######.
// #..k...#
// #.####.#
// #.#v.#.#
// #.#.k#k#
// #k.##..#
// #.v..v.#
// .######.

// Output:
// 3 1

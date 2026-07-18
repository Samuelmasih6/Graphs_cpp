//problem: https://cses.fi/problemset/task/1193/

#include <algorithm>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

int n,m;
vector<string>grid;
vector<vector<bool>> visited;
vector<vector<int>> previous_dir;

int dr[]={-1,1,0,0};
int dc[]={0,0,-1,1};
char dir_chars[]={'U','D','L','r'};

int start_r, start_c, end_r, end_c;

void bfs(){
    queue<pair<int,int>> q;

    //1. Initialize the start node
    q.push({start_r, start_c});
    visited[start_r][start_c]=true;

    //2. Process the queue
    while(!q.empty()){
        auto [r,c]=q.front();
        q.pop();

        //Early exit if we hit the target
        if(r==end_r && c==end_c){
            return;
        }

        //3. Explore all 4 adjacent directions
        for(int i=0;i<4;i++){
            int nr= r + dr[i];
            int nc= c + dc[i];

            //check if the new coordinate is within bounds
            if(nr<0||nr>=n||nc<0||nc>=m||grid[nr][nc]=='#') continue;

            if(!visited[nr][nc]){
            	visited[nr][nc]=true;
             //store the index of the direction we took to get here
            	previous_dir[nr][nc]=i;
             	q.push({nr,nc});
            }
        }
    }
}


int main(){
	cin>>n>>m;
	grid.resize(n);
	visited.assign(n,vector<bool>(m,false));
	previous_dir.assign(n,vector<int>(m,-1));

	for(int i=0;i<n;i++){
		cin>>grid[i];
		for(int j=0;j<m;j++){
			if(grid[i][j]=='A'){
				start_r=i;
				start_c=j;
			}else if(grid[i][j]=='B'){
				end_r=i;
				end_c=j;
			}
		}
	}

	bfs();

	if(visited[end_r][end_c]){
		cout<<"YES\n";

		string path="";
		int r=end_r,c=end_c;

		//RECONSTRUCT THE PATH
		//Walk backward until we hit the starting coordiantion
		while(r!=start_r||c!=start_c){
			int dir=previous_dir[r][c];

			path+=dir_chars[dir];

			//Do the exact opposite move to step backward
			r-=dr[dir];
			c-=dc[dir];
		}

		//The path was traced backwards, so reverse it
		reverse(path.begin(),path.end());

		cout<<path.size()<<"\n";
		cout<<path<<"\n";
	}else{
		cout<<"NO\n";
	}
	return 0;
}

//problem:
#include <bits/stdc++.h>
using namespace std;

const int INF=1e9;

int n,m;
vector<string> grid;
vector<vector<int>> monster_dist;
vector<vector<int>> player_dist;
vector<vector<int>> previous_dir;

int dr[]={-1,1,0,0};
int dc[]={0,0,-1,1};
char dir_chars[]={'U','D','L','R'};

int start_r,start_c;
int end_r=-1,end_c=-1;

int main(){
	cin>>n>>m;
	grid.resize(n);
	monster_dist.assign(n,vector<int>(m,INF));
	player_dist.assign(n,vector<int>(m,INF));
	previous_dir.assign(n,vector<int>(m,INF));

	queue<pair<int,int>> mq;
	queue<pair<int,int>> pq;

	for(int i=0;i<n;i++){
		cin>>grid[i];
		for(int j=0;j<m;j++){
			if(grid[i][j]=='M'){
				mq.push({i,j});
				monster_dist[i][j]=0;
			} else if(grid[i][j]=='A'){
				start_r=i;
				start_c=j;
				pq.push({i,j});
				player_dist[i][j]=0;
			}
		}
	}

	//1.Monster BFS (Multi-source)
	while(!mq.empty()){
		int r=mq.front().first;
		int c=mq.front().second;
		mq.pop();

		for(int i=0;i<4;i++){
			int nr=r+dr[i];
			int nc=c+dc[i];

			if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]!='#'){
				if(monster_dist[r][c]+1<monster_dist[nr][nc]){
					monster_dist[nr][nc]=monster_dist[r][c]+1;
					mq.push({nr,nc});
				}
			}
		}
	}

	//2. Player BFS (single-source with constraints)
	bool possible=false;

	while(!pq.empty()){
		int r=pq.front().first;
		int c=pq.front().second;
		pq.pop();

		//check if reached the a boundary
		if(r==0 || r==n-1 || c==0 || c==m-1){
			possible = true;
			end_r = r;
			end_c = c;
			break;
		}

		for(int i=0;i<4;i++){
			int nr = r + dr[i];
			int nc = c + dc[i];

			if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]!='#'){
                                //the survival rule: we must be strictly faster than the monsters
				if(player_dist[r][c]+1<monster_dist[nr][nc] && player_dist[r][c]+1< player_dist[nr][nc]){
                                        player_dist[nr][nc]=player_dist[r][c]+1;
					previous_dir[nr][nc]=i; //drop the directional breadcrumb
                                        pq.push({nr,nc});
                }
            }
		}
	}

	//3. Result & Path construction
	if(!possible){
		cout<<"NO\n";
	} else{
		cout<<"YES\n";
		string path = "";

		int curr_r = end_r;
		int curr_c = end_c;

		while(curr_r!=start_r || curr_c != start_c){
			int d = previous_dir[curr_r][curr_c];
			path+=dir_chars[d];
			curr_r -= dr[d];
			curr_c -= dc[d];
		}
		reverse(path.begin(),path.end());
		cout<<path.length()<<"\n";
		cout<<path<<"\n";
	}
		return 0;
}

//problem: https://codeforces.com/contest/727/problem/A

#include <bits/stdc++.h>
using namespace std;

long long a,b;
vector<long long> path;

bool dfs(long long current){
	if(current==b){
		path.push_back(current);
		return true;
	}
	if(current>b){
		return false;
	}
	path.push_back(current);

	//branch 1:try multiplying by 2
	if(dfs(current*2)){
		return true;
	}
	//branch 2:try appending 1
	if(dfs(current*10+1)){
		return true;
	}

	//Backtracking
	// //if we reach here, neither branch worked. This state is a dead end
	// we must remove it from our path tracker before returning false
	path.pop_back();
	return false;
}

int main(){
	cin>>a>>b;

	if(dfs(a)){
		cout<<"YES\n";
		cout<<path.size()<<"\n";

		for(int i=0;i<path.size();i++){
			cout<<path[i]<<(i==path.size()-1?"":" ");
		}
		cout<<"\n";
	} else {
		cout<<"NO\n";
	}
	return 0;
}

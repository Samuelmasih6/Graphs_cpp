//problem: https://leetcode.com/problems/number-of-provinces/description/
class Solution {
public:
    void dfs(int u,vector<vector<int>>& isConnected,vector<bool>&visited){
        visited[u]=true;
        for(int i=0;i<isConnected.size();i++){
            if(isConnected[u][i] && !visited[i]){
                dfs(i,isConnected,visited);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int result=0;
        int n=isConnected.size();
        vector<bool>visited(n);

        for(int i=0;i<n;i++){
            if(!visited[i]){
                result++;
                dfs(i,isConnected,visited);
            }
        }

        return result;
    }
};

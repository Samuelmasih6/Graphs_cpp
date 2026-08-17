#include <bits/stdc++.h>
using namespace std;

vector <vector<int>> t;
int LCS(const string& s1, const string& s2,int n,int m){
    if(n==0 || m==0)
        return 0;
    if(t[n][m]!=-1)
        return t[n][m];

    if(s1[n-1]==s2[m-1])
        return t[n][m] = 1+LCS(s1,s2,n-1,m-1);
    else
        return t[n][m] = max(LCS(s1,s2,n,m-1),LCS(s1,s2,n-1,m));
}

int main(){
    int n,m;
    cin>>n>>m;
    string s1,s2;
    cin>>s1>>s2;
    t.assign(n+1, vector<int>(m+1,-1));
    cout<<"length: "<<LCS(s1,s2,n,m);
}

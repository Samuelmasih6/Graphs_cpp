#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dp;
int ans = 0;

int LCSubstring(string &s1, string &s2, int n, int m) {

    if (n == 0 || m == 0)
        return 0;

    if (dp[n][m] != -1)
        return dp[n][m];

    if (s1[n - 1] == s2[m - 1]) {
        dp[n][m] = 1 + LCSubstring(s1, s2, n - 1, m - 1);

        ans = max(ans, dp[n][m]);

        return dp[n][m];
    }

    // Characters don't match, so contiguous substring breaks
    dp[n][m] = 0;

    // We still need to explore other possible substrings
    LCSubstring(s1, s2, n - 1, m);
    LCSubstring(s1, s2, n, m - 1);

    return dp[n][m];
}

int main() {

    string s1, s2;
    cin >> s1 >> s2;

    int n = s1.length();
    int m = s2.length();

    dp.assign(n + 1, vector<int>(m + 1, -1));

    LCSubstring(s1, s2, n, m);

    cout << "Length: " << ans << endl;

    return 0;
}

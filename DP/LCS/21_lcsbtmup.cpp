#include <bits/stdc++.h>
using namespace std;

int main() {
    string s1, s2;

    cin >> s1 >> s2;

    int n = s1.length();
    int m = s2.length();

    // dp[i][j] = LCS length of first i characters of s1
    // and first j characters of s2
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    // Build the table
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {

            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    cout << "Length: " << dp[n][m] << endl;

    return 0;
}

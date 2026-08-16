//problem: https://leetcode.com/problems/coin-change/description/
//problem: https://leetcode.com/problems/coin-change-ii/description/
//
// knapsack pattern
// because you either include the coin or not
// knapsack's weight[] -> coin[]
// Target weight -> Target amount
// it is unbound knapsack because infinite number of coins can be used
// like subset sum
// if(arr[i-1]<=j)
//      t[i][j]=t[i-1][j]||t[i-1][j-arr[i-1]] either max or min according to problem
// else
//      t[i][j]=t[i-1][j]
// but while count of subset or number of ways,
// we use + instead of || because there are ways possible from every number
//
#include <bits/stdc++.h>
using namespace std;

// Number of combinations
long long countWays(vector<int>& coins, int target) {
    vector<long long> dp(target + 1);
    dp[0] = 1;

    for (int coin : coins) {
        for (int amount = coin; amount <= target; amount++) {
            dp[amount] += dp[amount - coin];
        }
    }

    return dp[target];
}

// Number of permutations
long long countPermutations(vector<int>& coins, int target) {
    vector<long long> dp(target + 1);
    dp[0] = 1;

    for (int amount = 1; amount <= target; amount++) {
        for (int coin : coins) {
            if (amount >= coin) {
                dp[amount] += dp[amount - coin];
            }
        }
    }

    return dp[target];
}

// Minimum number of coins
int minCoins(vector<int>& coins, int target) {
    vector<int> dp(target + 1, INT_MAX);
    dp[0] = 0;

    for (int amount = 1; amount <= target; amount++) {
        for (int coin : coins) {
            if (amount >= coin && dp[amount - coin] != INT_MAX) {
                dp[amount] = min(
                    dp[amount],
                    dp[amount - coin] + 1
                );
            }
        }
    }

    return dp[target] == INT_MAX ? -1 : dp[target];
}

// Maximum number of coins
int maxCoins(vector<int>& coins, int target) {
    vector<int> dp(target + 1, INT_MIN);
    dp[0] = 0;

    for (int amount = 1; amount <= target; amount++) {
        for (int coin : coins) {
            if (amount >= coin && dp[amount - coin] != INT_MIN) {
                dp[amount] = max(
                    dp[amount],
                    dp[amount - coin] + 1
                );
            }
        }
    }

    return dp[target] == INT_MIN ? -1 : dp[target];
}

int main() {
    vector<int> coins = {1, 2, 5};
    int target = 5;

    cout << "Number of combinations : "
         << countWays(coins, target) << '\n';

    cout << "Number of permutations : "
         << countPermutations(coins, target) << '\n';

    cout << "Minimum coins          : "
         << minCoins(coins, target) << '\n';

    cout << "Maximum coins          : "
         << maxCoins(coins, target) << '\n';

    return 0;
}

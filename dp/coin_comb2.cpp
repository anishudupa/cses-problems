#include <iostream>
#include <bits/stdc++.h>

using namespace std;
const long long MOD = 1e9 + 7;
int main()
{

  int n, x;
  cin >> n >> x;
  vector<int> coins(n);
  for (int i = 0; i < n; i++)
    cin >> coins[i];
  vector<int> dp(x + 1);
  for (int i = n - 1; i >= 0; i--)
  {
    vector<int> newRow(x + 1);
    newRow[0] = 1;
    for (int j = 1; j <= x; j++)
    {
      // dp[i][j] = dp[i + 1][j];
      // if (j - coins[i] >= 0)
      //   dp[i][j] = (dp[i][j] + dp[i][j - coins[i]]) % MOD;
      newRow[j] = dp[j];
      if (j - coins[i] >= 0)
        newRow[j] = (newRow[j] + newRow[j - coins[i]]) % MOD;
    }
    dp = newRow;
  }
  cout << dp[x];
  return 0;
}
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1e9 + 7;
int main()
{
  int n, x;
  cin >> n >> x;
  vector<int> coins(n);
  vector<int> dp(x + 1);
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  dp[0] = 1;
  for (int i = 0; i < n; i++)
    cin >> coins[i];
  for (int i = 1; i <= x; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (i - coins[j] >= 0)
        dp[i] = (dp[i] + dp[i - coins[j]]) % MOD;
    }
  }
  cout << dp[x];
  return 0;
}
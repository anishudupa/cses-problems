#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int MOD = (int)1e9 + 7;
// int dfs(int n, vector<int> &memo)
// {
//   if (n == 0)
//     return 1;
//   if (memo[n] != -1)
//     return memo[n];
//   int res = 0;
//   for (int i = 1; i <= 6; i++)
//   {
//     if (i > n)
//       break;
//     res = (res + dfs(n - i, memo)) % MOD;
//   }
//   return memo[n] = res;
// }
int main()
{
  int n;
  cin >> n;
  vector<int> dp(n + 1);
  dp[0] = 1;
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= 6; j++)
    {
      if (j > i)
        break;
      dp[i] = (dp[i] + dp[i - j]) % MOD;
    }
  }
  cout << dp[n] << endl;
  return 0;
}
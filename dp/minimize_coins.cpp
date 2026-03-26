#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n, x;
  cin >> n >> x;
  vector<int> coins(n);
  vector<int> dp(x + 1, x + 1);
  for (int i = 0; i < n; i++)
  {
    cin >> coins[i];
  }
  dp[0] = 0;
  for (int i = 1; i <= x; i++)
  {
    for (int &c : coins)
    {
      if (i - c >= 0)
        dp[i] = min(dp[i], 1 + dp[i - c]);
    }
  }
  int res = (dp[x] == x + 1) ? -1 : dp[x];
  cout << res << endl;
  return 0;
}
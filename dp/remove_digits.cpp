#include <iostream>
#include <bits/stdc++.h>

using namespace std;
vector<int> memo;

// memoization
int dfs(int n)
{
  if (n == 0)
    return 0;
  if (memo[n] != -1)
    return memo[n];
  string str = to_string(n);
  int res = INT_MAX;
  for (int i = 0; i < str.size(); i++)
  {
    if (str[i] == '0')
      continue;
    int newn = n - (str[i] - '0');
    res = min(res, 1 + dfs(newn));
  }
  return memo[n] = res;
}

int main()
{
  int n;
  cin >> n;
  string str = to_string(n);

  // tabulation
  vector<int> dp(n + 1);
  dp[0] = 0;
  for (int i = 1; i <= n; i++)
  {
    string str = to_string(i);
    int res = INT_MAX;
    for (char &ch : str)
    {
      if (ch == '0')
        continue;
      int newn = i - (ch - '0');
      res = min(res, 1 + dp[newn]);
    }
    dp[i] = res;
  }
  cout << dp[n];
  return 0;
}
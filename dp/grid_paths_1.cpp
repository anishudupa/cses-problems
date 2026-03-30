#include <iostream>
#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1e9 + 7;
vector<vector<int>> memo;

// MEMOIZATION
int dfs(vector<vector<char>> &grid, int n, int r, int c)
{
  if (r < 0 || c < 0 || r == n || c == n || grid[r][c] == '*')
    return 0;
  if (r == n - 1 and c == n - 1)
    return 1;
  if (memo[r][c] != -1)
    return memo[r][c];
  return memo[r][c] = (dfs(grid, n, r + 1, c) + dfs(grid, n, r, c + 1)) % MOD;
}
int main()
{

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;
  vector<vector<char>> grid(n, vector<char>(n));
  vector<int> dp(n + 1);
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cin >> grid[i][j];
    }
  }

  // TABULATION
  if (grid[n - 1][n - 1] == '*')
  {
    cout << 0;
    return 0;
  }
  for (int i = n - 1; i >= 0; i--)
  {
    vector<int> newRow(n + 1);
    if (i == n - 1)
      newRow[n - 1] = 1;
    for (int j = n - 1; j >= 0; j--)
    {
      if (grid[i][j] != '*' and !(i == n - 1 and j == n - 1))
      {
        newRow[j] = (dp[j] + newRow[j + 1]) % MOD;
      }
    }
    dp = newRow;
  }

  cout << dp[0];
  return 0;
}
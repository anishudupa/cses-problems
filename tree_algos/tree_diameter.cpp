#include <iostream>
#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
vector<vector<int>> graph(N);
vector<int> depth(N);

void dfs(int root, int par = -1)
{
  for (int &c : graph[root])
  {
    if (c == par)
      continue;
    depth[c] = 1 + depth[root];
    dfs(c, root);
  }
}
int main()
{

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;
  int x, y;
  for (int i = 0; i < n - 1; i++)
  {
    cin >> x >> y;
    graph[x].push_back(y);
    graph[y].push_back(x);
  }
  dfs(1);
  int maxd = -1, maxn;
  for (int i = 1; i <= n; i++)
  {
    if (depth[i] > maxd)
    {
      maxd = depth[i];
      maxn = i;
    }
    depth[i] = 0;
  }

  dfs(maxn);

  maxd = -1;
  for (int i = 1; i <= n; i++)
  {
    if (depth[i] > maxd)
    {
      maxd = depth[i];
    }
  }

  cout << maxd;
  return 0;
}
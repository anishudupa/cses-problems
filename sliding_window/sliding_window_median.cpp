#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class MedianStream
{
  multiset<int> mins, maxs;

public:
  void add(int num)
  {
    if (!maxs.empty() and *maxs.begin() <= num)
      maxs.insert(num);
    else
      mins.insert(num);
    adjust();
  }

  void del(int num)
  {
    auto it = mins.find(num);
    if (it != mins.end())
    {
      mins.erase(it);
    }
    else
    {
      it = maxs.find(num);
      if (it != maxs.end())
        maxs.erase(it);
    }
    adjust();
  }

  int median()
  {
    if (mins.size() >= maxs.size())
      return *mins.rbegin();
    return *maxs.begin();
  }

  void adjust()
  {
    if (maxs.size() > mins.size() + 1)
    {
      mins.insert(*maxs.begin());
      maxs.erase(maxs.begin());
    }
    if (mins.size() > maxs.size() + 1)
    {
      auto it = mins.end();
      it--;
      maxs.insert(*it);
      mins.erase(it);
    }
  }
};

int main()
{

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n, k;
  cin >> n >> k;
  int arr[n];
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  MedianStream ms;
  for (int i = 0; i < n; i++)
  {
    ms.add(arr[i]);
    if (i >= k)
      ms.del(arr[i - k]);
    if (i >= k - 1)
      cout << ms.median() << " ";
  }
  return 0;
}
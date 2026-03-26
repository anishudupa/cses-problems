#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
  string str;
  cin >> str;
  vector<int> count(26);
  int maxi = 1, curr = 1;
  for (int i = 1; i < str.size(); i++)
  {
    if (str[i] == str[i - 1])
      curr += 1;
    else
      curr = 1;
    maxi = max(maxi, curr);
  }

  cout << maxi;
  return 0;
}
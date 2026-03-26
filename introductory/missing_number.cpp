#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  cin >> n;
  long long given_xor = 0, inp, all_xor = 0;
  for (int i = 1; i < n; i++)
  {
    cin >> inp;
    given_xor ^= inp;
    all_xor ^= i;
  }
  all_xor ^= n;
  long long res = all_xor ^ given_xor;
  cout << res;
  return 0;
}
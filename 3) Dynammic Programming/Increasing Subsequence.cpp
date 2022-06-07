#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const long long MAXVAL = 10000000;
long long arr[MAXVAL];
const int mod = 1e9 + 7;

int main()
{
  int n;
  cin >> n;
  vector<int> dp;
  // dp[x]:minimum ending value of an increasing subsequence of length x+1, using the elements considered so far
  for (int i = 0; i < n; i++)
  {
    int x;
    cin >> x;
    auto it = lower_bound(dp.begin(), dp.end(), x) - dp.begin();
    if (it == dp.size())
    {
      dp.push_back(x);
      // if thats the case then all ending elements of LIS of lenght dp.size() are smaller than this element so said element will constitute the ending element of the LIS of lenght dp.size()+1
    }
    else
    {
      dp[it] = x;
      // modify the ending element of the LIS of lenght it so that it is better for after(ex 7 3 5 LIS of lenght 1 initially 7 becomes 3 afterward, or else answer would be 1 instead of 2)
    }
  }
  cout << dp.size() << endl;
}
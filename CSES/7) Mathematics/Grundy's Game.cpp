#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
ll mod = 1e9 + 7;

#define int long long
#define endl '\n'

vector<int> dp(2001, 0);
// dp[i] = grundy value of i
// dp[i] = mex({dp[j]^dp[i-j]: j in [1,i/2)}) (because u cant split in equal sizes)
// you take xor because these are the new pair of states you are in.

int mex(vector<int> &v)
{
    set<int> s;
    for (int i : v)
        s.insert(i);
    int ans = (int)v.size();
    for (int i = 0; i <= (int)v.size(); i++)
    {
        if (s.count(i) == 0)
        {
            return i;
        }
    }
    return -1;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    for (int i = 3; i <= 2000; i++)
    {
        vector<int> v;
        for (int j = 1; 2 * j < i; j++)
        {
            v.push_back(dp[j] ^ dp[i - j]);
        }
        dp[i] = mex(v);
    }
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        if (n >= 2000)
        {
            cout << "first" << endl;
            continue;
        }
        cout << (dp[n] != 0 ? "first" : "second") << endl;
    }

    return 0;
}
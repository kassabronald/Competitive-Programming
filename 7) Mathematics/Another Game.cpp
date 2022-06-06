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
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int ans = 0;
        int off = 0;
        while (n--)
        {
            int x;
            cin >> x;
            if (x % 2)
            {
                off = 1;
            }
            // final state is simply the state with 0 things left.
            // winning state is any state with a column of odd (because needs to be 1 1 1 1 0 1 1 1 or something to
            // be the last to remove)
            // if there are odd columns make them even by removing one from each and now the player is in losing pos.
        }
        cout << (off == 0 ? "second" : "first") << endl;
    }

    return 0;
}
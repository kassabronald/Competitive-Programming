#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll mod = 1e9 + 7;

#define int long long
#define endl '\n'

int ceiling(int a, int b)
{
    int val = (a / b) + ((a % b) != 0);
    return val;
}

template <typename T1, typename T2>
ostream &operator<<(ostream &os, const vector<pair<T1, T2>> vec)
{
    int n = vec.size();
    os << "[";
    for (int i = 0; i < n - 1; i++)
    {
        os << "{" << vec[i].first << ", " << vec[i].second << "} ,";
    }
    os << "{" << vec[n - 1].first << ", " << vec[n - 1].second << "}]";
    return os;
}

template <typename T>
ostream &operator<<(ostream &os, const vector<T> vec)
{
    int n = vec.size();
    os << "[";
    for (int i = 0; i < n - 1; i++)
    {
        os << vec[i] << ", ";
    }
    os << vec[n - 1] << "]" << endl;
    return os;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, x;
    cin >> n >> x;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    // dp[mask] = {ride(mask), last(mask)}
    //          = {min number of rides to accomodate people represented
    //             by mask, weight of the last ride (i.e remaining one)}
    vector<pair<int, int>> dp(1 << n);
    dp[0] = {1, 0};
    for (int mask = 1; mask < (1 << n); mask++)
    {
        dp[mask] = {n + 1, 0};
        for (int j = 0; j < n; j++)
        {
            if (mask & (1 << j))
            {
                pair<int, int> ans = dp[mask ^ (1 << j)];
                bool is = (ans.second + v[j] <= x);
                if (is)
                {
                    ans.second += v[j];
                }
                else
                {
                    ans.first++;
                    ans.second = v[j];
                }
                dp[mask] = min(dp[mask], ans);
            }
        }
    }
    cout << dp[(1 << n) - 1].first << endl;

    return 0;
}
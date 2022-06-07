#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll mod = 1e9 + 7;

#define int long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()

int dp[20][10][2][2];

// solve(s, N, digit, leadingZeros, tight)
//= number of N digit numbers who's leftmost digit != digit
//+ can I put leadingZeros and am I under tight constraints?
int solve(string s, int N, int digit, bool leadingZeros, bool tight)
{
    if (N == 0)
    {
        dp[N][digit][leadingZeros][tight] = 1;
        return 1;
    }
    if (dp[N][digit][leadingZeros][tight] != -1)
    {
        return dp[N][digit][leadingZeros][tight];
    }
    int lowerBound = 0;
    int upperBound = (tight == 0 ? 9 : s[(int)s.size() - N] - '0');
    int ans = 0;
    for (int dig = lowerBound; dig <= upperBound; dig++)
    {
        if (leadingZeros == 0 && dig == digit)
        {
            continue; // illegal
        }
        ans += solve(s, N - 1, dig, (leadingZeros & dig == 0), (tight & (dig == upperBound)));
    }
    return dp[N][digit][leadingZeros][tight] = ans;
}

//'b'-'a' --> which number in alphabet
//'4'-'0' --> get int representation

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int l, r;
    cin >> l >> r;
    string s = to_string(r);
    string p = to_string(l - 1);
    memset(dp, -1, sizeof dp);
    int ans1 = solve(s, (int)s.size(), -1, 1, 1);
    memset(dp, -1, sizeof dp);
    int ans2 = solve(p, (int)p.size(), -1, 1, 1);
    cout << ans1 - ans2 << endl;

    return 0;
}
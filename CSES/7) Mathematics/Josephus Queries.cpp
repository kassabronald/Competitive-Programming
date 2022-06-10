#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll mod = 1e9 + 7;

#define int long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()

int solve(int n, int k)
{
    if (1 <= k && k <= ((n + 1) / 2))
    {
        // return 2*k^th number of the bucket in question
        return 2 * k % n == 0 ? n : 2 * k % n;
    }
    int ans = solve(n / 2, k - (n + 1) / 2);
    if (n % 2)
    {
        // if(ans == 1){
        //     return n;
        // }
        return 2 * ans + 1;
    }
    else
    {
        return 2 * ans - 1;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int q;
    cin >> q;
    while (q--)
    {
        int n, k;
        cin >> n >> k;
        cout << solve(n, k) << endl;
    }

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll mod = 1e9 + 7;

#define int long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, x;
    cin >> n >> x;
    map<int, int> m;
    m[0] = 1;
    int summ = 0;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        summ += t;
        ans += m[summ - x];

        m[summ]++;
    }
    cout << ans << endl;

    return 0;
}
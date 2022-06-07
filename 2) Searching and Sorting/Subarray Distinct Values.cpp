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
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    int l = 0;
    int ans = 0;
    map<int, int> m;
    for (int r = 0; r < n; r++)
    {
        m[v[r]]++;

        while (l < r && (int)m.size() > k)
        {
            m[v[l]]--;
            if (m[v[l]] == 0)
            {
                m.erase(v[l]);
            }
            l++;
        }
        ans += r - l + 1;
    }
    cout << ans << endl;

    return 0;
}
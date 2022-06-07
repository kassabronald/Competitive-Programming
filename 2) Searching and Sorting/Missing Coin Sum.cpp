#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll mod = 1e9 + 7;

#define int long long
#define endl '\n'

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> v(n);
    int add = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        add += v[i];
    }
    sort(v.begin(), v.end());
    if (v[0] != 1)
    {
        cout << 1 << endl;
    }
    else
    {
        int summ = 1;
        int last = 1;
        int ans = add + 1;
        for (int i = 1; i < n; i++)
        {
            int mini = v[i];
            int maxi = summ + v[i];
            if (mini - last > 1)
            {
                ans = last + 1;
                break;
            }
            else
            {
                last = maxi;
                summ += v[i];
            }
        }
        cout << ans << endl;
    }

    return 0;
}
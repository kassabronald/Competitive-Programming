#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll mod = 1e9 + 7;

#define int long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()

int compare(pair<int, int> p1, pair<int, int> p2)
{
    if (p1.second != p2.second)
    {
        return p1.second < p2.second;
    }
    return p1.first < p2.first;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i].first >> v[i].second;
    }

    sort(v.begin(), v.end(), compare);
    multiset<int> ending;
    int ans = 0;
    for (int i = 0; i < k; i++)
    {
        ending.insert(0);
    }
    for (int i = 0; i < n; i++)
    {
        auto it = ending.upper_bound(v[i].first);
        if (it != ending.begin())
        {
            it--;
            ending.erase(it);
            ending.insert(v[i].second);
            ans++;
        }
    }
    cout << ans << endl;

    return 0;
}

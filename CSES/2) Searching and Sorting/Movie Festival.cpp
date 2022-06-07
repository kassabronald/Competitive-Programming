
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
    cin >> n;
    k = 1;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i].first >> v[i].second;
    }
    sort(v.begin(), v.end(), compare);
    set<int> available;
    for (int i = 0; i <= k - 1; i++)
    {
        available.insert(i);
    }
    int ans = k;
    int i = k;
    int j = 0;
    while (i < n)
    {
        j = (*available.begin());
        int curr = v[j].second;
        while (i < n && v[i].first < curr)
        {
            i++;
        }
        if (i == n)
        {
            break;
        }
        available.erase(j);
        available.insert(i);
        ans++;
    }
    cout << ans << endl;

    return 0;
}
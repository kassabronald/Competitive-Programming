#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll mod = 1e9 + 7;

#define int long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()

struct interval
{
    int x, y, idx;

    bool operator<(interval i)
    {
        if (x == i.x)
        {
            return y > i.y;
        }
        return x < i.x;
    }
};

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<interval> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i].x;
        cin >> v[i].y;
        v[i].idx = i;
    }
    sort(v.begin(), v.end());
    vector<int> contains(n), is_contained(n);
    int max_end = 0;
    for (int i = 0; i < n; i++)
    {
        if (v[i].y <= max_end)
        {
            is_contained[v[i].idx] = 1;
        }
        max_end = max(max_end, v[i].y);
    }
    int min_end = 1e18;
    for (int i = n - 1; i >= 0; i--)
    {
        if (v[i].y >= min_end)
        {
            contains[v[i].idx] = 1;
        }
        min_end = min(min_end, v[i].y);
    }
    for (int i : contains)
    {
        cout << i << " ";
    }
    cout << endl;
    for (int i : is_contained)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
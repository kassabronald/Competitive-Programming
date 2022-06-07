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
            return y < i.y;
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
    vector<interval> v(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i].x;
        cin >> v[i].y;
        v[i].idx = i;
    }
    sort(v.begin(), v.end());

    set<int> s;
    set<pair<int, int>> days;
    for (int i = 1; i <= n; i++)
    {
        s.insert(i);
    }
    vector<int> which(n + 1);
    for (int i = 1; i <= n; i++)
    {
        if (!days.empty())
        {
            auto it = days.upper_bound({v[i].x, 0});

            if (it != days.begin())
            {
                it--;
            }
            pair<int, int> elem = *it;
            if (elem.first <= v[i].x)
            {
                days.erase(elem);
                days.insert({v[i].y + 1, elem.second});
                which[v[i].idx] = elem.second;
            }
            else
            {
                int room = *s.begin();
                int when_end = v[i].y + 1;
                days.insert({when_end, room});
                s.erase(room);
                which[v[i].idx] = room;
            }
        }
        else
        {
            int room = *s.begin();
            int when_end = v[i].y + 1;
            days.insert({when_end, room});
            s.erase(room);
            which[v[i].idx] = room;
        }
    }
    map<int, int> m;
    for (int i = 1; i <= n; i++)
    {
        m[which[i]]++;
    }
    cout << (int)m.size() << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << which[i] << " ";
    }
    cout << endl;

    return 0;
}
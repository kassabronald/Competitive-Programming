#include <bits/stdc++.h>
using namespace std;

struct DSU
{

    map<int, vector<int>> SETS;
    vector<int> representative;
    DSU(int n)
    {
        representative.resize(n);
    }
    void make_set(int x)
    {
        vector<int> vec = {x};
        SETS[x] = vec;
        representative[x] = x;
    }
    int find_set(int y)
    {
        return representative[y];
    }
    int size(int u)
    {
        return SETS[find_set(u)].size();
    }
    void merge(int x, int y)
    {
        int sx = size(x);
        int sy = size(y);

        if (sx < sy)
        {
            int tmp = find_set(x);
            for (int i : SETS[find_set(x)])
            {
                SETS[find_set(y)].push_back(i);
                representative[i] = find_set(y);
            }

            SETS.erase(tmp);
        }
        else
        {

            int tmp = find_set(y);
            for (int i : SETS[find_set(y)])
            {
                SETS[find_set(x)].push_back(i);
                representative[i] = find_set(x);
            }
            SETS.erase(tmp);
        }
    }
};

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    DSU dsu(n);
    for (int i = 0; i < n; i++)
    {
        dsu.make_set(i);
    }
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        if (dsu.find_set(u) != dsu.find_set(v))
        {
            dsu.merge(u, v);
        }
    }
    cout << (int)dsu.SETS.size() - 1 << endl;
    auto it = dsu.SETS.begin();
    int relevant = it->first;
    dsu.SETS.erase(it);
    for (auto other = dsu.SETS.begin(); other != dsu.SETS.end(); other++)
    {
        cout << relevant + 1 << " " << other->first + 1 << endl;
    }

    return 0;
}
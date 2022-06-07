#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
const int MAXD = 31;

int parent[MAXN][MAXD];
// parent[i][d] = 2^dth parent of i
//              = 2^(d-1)st parent of my 2^(d-1)st parent
//              = parent[parent[i][d-1]][d-1]

int jump(int x, int k)
{
    // returns the k^th parent of x.
    for (int i = 0; i < 30; i++)
    {
        if (k & (1 << i))
        {
            x = parent[x][i];
        }
    }
    return x;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        int v;
        cin >> v;
        parent[i][0] = v;
    }
    for (int j = 1; j < 30; j++)
    {
        for (int i = 1; i <= n; i++)
        {
            parent[i][j] = parent[parent[i][j - 1]][j - 1];
        }
    }

    while (q--)
    {
        int x, k;
        cin >> x >> k;
        cout << jump(x, k) << endl;
    }

    return 0;
}
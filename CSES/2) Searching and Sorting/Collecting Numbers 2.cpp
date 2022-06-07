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
    int n, M;
    cin >> n >> M;
    vector<int> v(n + 1);
    map<int, int> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
        m[v[i]] = i;
    }
    m[n + 1] = n + 1;
    int ans = 1;
    for (int i = 1; i <= n - 1; i++)
    {
        if (m[i] > m[i + 1])
        {
            ans++;
        }
    }
    while (M--)
    {
        int i, j;
        cin >> i >> j;
        if (i > j)
        {
            swap(i, j);
        }
        // check how many inversions where added or removed.
        int preV_i = m[v[i] - 1];
        int after_i = m[v[i] + 1];
        int preV_j = m[v[j] - 1];
        int after_j = m[v[j] + 1];
        int penalty = 0;
        if (abs(v[i] - v[j]) == 1)
        {
            m[v[i]] = j;
            m[v[j]] = i;
            if (v[i] > v[j])
            {
                penalty--;
                if (i > preV_j && j < preV_j)
                {
                    penalty--;
                }
                if (i < preV_j && j > preV_j)
                {
                    penalty++;
                }
                if (j < after_i && i > after_i)
                {
                    penalty--;
                }
                if (j > after_i && i < after_i)
                {
                    penalty++;
                }
            }
            if (v[j] > v[i])
            {
                penalty++;
                if (j > preV_i && i < preV_i)
                {
                    penalty--;
                }
                if (j < preV_i && i > preV_i)
                {
                    penalty++;
                }
                if (i < after_j && j > after_j)
                {
                    penalty--;
                }
                if (i > after_j && j < after_j)
                {
                    penalty++;
                }
            }
            swap(v[i], v[j]);
        }
        else
        {
            m[v[i]] = j;
            m[v[j]] = i;
            if (j > preV_i && i < preV_i)
            {
                penalty--;
            }
            if (j < preV_i && i > preV_i)
            {
                penalty++;
            }
            if (i > preV_j && j < preV_j)
            {
                penalty--;
            }
            if (i < preV_j && j > preV_j)
            {
                penalty++;
            }
            if (j < after_i && i > after_i)
            {
                penalty--;
            }
            if (j > after_i && i < after_i)
            {
                penalty++;
            }
            if (i < after_j && j > after_j)
            {
                penalty--;
            }
            if (i > after_j && j < after_j)
            {
                penalty++;
            }
            swap(v[i], v[j]);
        }
        ans += penalty;
        cout << ans << endl;
    }

    return 0;

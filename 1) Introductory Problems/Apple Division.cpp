#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <map>
#include <math.h>
#include <algorithm>
#include <set>
using namespace std;

typedef long long ll;
ll mod = 1e9 + 7;

#define int long long
#define endl '\n'

int f(vector<int> &v)
{
    int n = (int)v.size();
    int ans = 1e18;
    for (int mask = 0; mask < (1 << n); mask++)
    {
        int grp1 = 0;
        int grp2 = 0;
        for (int j = 0; j < n; j++)
        {
            if (mask & (1 << j))
            {
                grp1 += v[j];
            }
            else
            {
                grp2 += v[j];
            }
        }
        ans = min(ans, abs(grp2 - grp1));
    }
    return ans;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> v(n);
    int summ = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        summ += v[i];
    }
    cout << f(v) << endl;

    return 0;
}
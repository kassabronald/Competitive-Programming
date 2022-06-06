#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <map>
#include <math.h>
#include <algorithm>
#include <unordered_map>
#include <set>
#include <unordered_set>
using namespace std;

typedef long long ll;
ll mod = 1e9 + 7;

#define int long long
#define endl '\n'

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int m;
    cin >> m;
    for (int n = 1; n <= m; n++)
    {
        int k1, k2, ktot, red;
        k1 = n * n;
        k2 = k1 - 1;
        ktot = k1 * k2 / 2;
        red = 4 * (n - 1) * (n - 2);
        cout << ktot - red << endl;
    }

    return 0;
}
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
const long long MAXVAL = 10000000;
long long arr[MAXVAL];
long long arr2[MAXVAL];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n, x;
    cin >> n >> x;
    map<ll, vector<ll>> M;
    for (ll i = 1; i <= n; i++)
    {
        ll k;
        cin >> k;
        M[k].push_back(i);
    }
    bool b = false;
    for (auto it = M.begin(); it != M.end(); it++)
    {
        if (M.find(x - (it->first)) != M.end())
        {
            if (x - it->first == it->first)
            {
                if (it->second.size() > 1)
                {
                    cout << it->second[0] << " " << it->second[1] << endl;
                    b = true;
                    break;
                }
            }
            else
            {
                cout << it->second[0] << " " << M[x - it->first][0] << endl;
                b = true;
                break;
            }
        }
    }
    if (!b)
    {
        cout << "IMPOSSIBLE" << endl;
    }

    return 0;
}
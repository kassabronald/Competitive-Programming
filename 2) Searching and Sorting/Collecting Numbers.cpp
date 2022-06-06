#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const long long MAXVAL = 10000000;
long long arr[MAXVAL];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin >> n;
    unordered_map<ll, ll> M;
    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i];
        M[arr[i]] = i;
    }
    ll res = 1;
    for (ll i = 1; i <= n - 1; i++)
    {
        if (M[i] > M[i + 1])
        {
            res++;
        }
    }
    cout << res << endl;

    return 0;
}
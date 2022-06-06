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
    ll res = 0;
    ll sum = (n * (n + 1)) / 2;
    for (ll i = 0; i < n - 1; i++)
    {
        ll k;
        cin >> k;
        res += k;
    }
    cout << sum - res << endl;

    return 0;
}
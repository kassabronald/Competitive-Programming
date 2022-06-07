#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const long long MAXVAL = 10000000;
long long arr[MAXVAL];

void solve(ll arr[], ll n)
{
    ll res = 0;
    for (ll i = 1; i < n; i++)
    {
        if (arr[i - 1] > arr[i])
        {
            res += arr[i - 1] - arr[i];
            arr[i] += arr[i - 1] - arr[i];
        }
    }
    cout << res << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin >> n;
    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    solve(arr, n);

    return 0;
}
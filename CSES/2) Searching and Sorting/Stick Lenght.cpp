#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const long long MAXVAL = 10000000;
long long arr[MAXVAL];

ll solu(ll arr[], ll n, ll median)
{
    ll count = 0;
    for (ll i = 0; i < n; i++)
    {
        count += abs(median - arr[i]);
    }
    return count;
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
    sort(arr, arr + n);
    if (n % 2)
    {
        ll median = arr[n / 2];
        cout << solu(arr, n, median);
    }
    else
    {
        ll median1 = arr[n / 2];
        ll median2 = arr[(n / 2) + 1];
        cout << min(solu(arr, n, median1), solu(arr, n, median2));
    }

    return 0;
}
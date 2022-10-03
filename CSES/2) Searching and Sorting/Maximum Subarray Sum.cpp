#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin >> n;
    vector<ll> vec(n, -1);
    ll neg_count = 0;
    for (ll i = 0; i < n; i++)
    {
        ll k;
        cin >> k;
        vec[i] = k;
    }
    ll M = *max_element(vec.begin(), vec.end());
    if (M < 0)
    {
        cout << M << endl;
    }
    else
    {
        ll curr = 0;
        ll maxi = 0;
        for (ll i = 0; i < n; i++)
        {
            curr += vec[i];
            if (curr < 0)
            {
                curr = 0;
            }
            maxi = max(curr, maxi);
        }
        cout << maxi << endl;
    }
    return 0;
}
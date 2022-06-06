#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const long long MAXVAL = 10000000;
long long arr[MAXVAL];

int main()
{
    ll n;
    cin >> n;
    for (ll i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    stack<pair<ll, ll>> S;
    vector<ll> vec(n + 1, 0);
    ll i = 2;
    S.push({arr[1], 1});
    while (i <= n)
    {
        if (arr[i] > S.top().first)
        {
            vec[i] = S.top().second;
            S.push({arr[i], i});
        }
        else
        {
            if (!S.empty())
            {
                while (!S.empty() && arr[i] <= S.top().first)
                {
                    if (!S.empty())
                    {
                        S.pop();
                    }
                }
            }
            if (S.empty())
            {
                vec[i] = 0;
                S.push({arr[i], i});
            }
            else
            {
                vec[i] = S.top().second;
                S.push({arr[i], i});
            }
        }
        i++;
    }
    for (int i = 1; i <= n; i++)
    {
        cout << vec[i] << " ";
    }

    return 0;
}
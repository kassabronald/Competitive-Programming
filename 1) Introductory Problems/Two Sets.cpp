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
    ll sum = (n * (n + 1)) / 2;

    if (sum % 2 != 0)
    {
        cout << "NO" << endl;
    }
    else
    {
        cout << "YES" << endl;
        ll flag1 = -1;
        ll sum1 = 0;
        vector<ll> vec;
        ll i = 0;
        while (sum1 < sum / 2)
        {
            sum1 += i;
            if (sum1 < sum / 2)
            {
                i++;
                vec.push_back(i);
            }
        }
        if (sum1 > sum / 2)
        {
            flag1 = sum1 - sum / 2;
            cout << vec.size() - 1 << endl;
        }
        else
        {
            cout << vec.size() << endl;
        }
        for (ll i = 0; i < vec.size(); i++)
        {
            if (vec[i] != flag1)
            {
                cout << vec[i] << " ";
            }
        }
        cout << endl;
        if (flag1 != -1)
        {
            cout << n - i + 1 << endl;
            cout << flag1 << " ";
        }
        else
        {
            cout << n - i << endl;
        }
        for (ll j = i + 1; j <= n; j++)
        {
            cout << j << " ";
        }
    }

    return 0;
}
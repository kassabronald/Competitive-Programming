#include <bits/stdc++.h>
using namespace std;

const int val = 1e6 + 1;
int divisors[val];
int maxx = 0;

void f(int &n)
{
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            divisors[i]++;
            if (n / i != i)
            {
                divisors[n / i]++;
            }
        }
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int k;
        cin >> k;
        f(k);
    }
    for (int i = 1e6; i >= 1; i--)
    {
        if (divisors[i] > 1)
        {
            cout << i << endl;
            break;
        }
    }

    return 0;
}

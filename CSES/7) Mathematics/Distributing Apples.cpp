#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll mod = 1e9 + 7;

#define int long long
#define endl '\n'

int modPow(int x, int n)
{
    x %= mod;
    int res = 1;
    while (n > 0)
    {
        if (n & 1)
            res = res * x % mod;
        x = x * x % mod;
        n = (n >> 1);
    }
    return res;
}

int modInverse(int x)
{
    return modPow(x, mod - 2);
}

int fact(int n)
{
    int res = 1;
    for (int i = 2; i <= n; i++)
    {
        res = (res * i) % mod;
    }
    return res;
}

int choose(int a, int b)
{
    int res = (fact(a) * modInverse((fact(b) * fact(a - b)) % mod)) % mod;
    return res;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    // basically number of solutions of:
    // x1+x2+...+xn = m, xi >= 0;
    // solution is (m+n-1)Cm
    int res = choose(m + n - 1, m);
    cout << res << endl;

    return 0;
}

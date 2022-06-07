#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll mod = 1e9 + 7;

#define int long long
#define endl '\n'

vector<int> fact(1e6 + 7, 1);

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

int choose(int a, int b)
{
    int res = (fact[a] * modInverse((fact[b] * fact[a - b]) % mod)) % mod;
    return res;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    for (int i = 1; i <= 1e6; i++)
    {
        fact[i] = (fact[i - 1] * i) % mod;
    }
    int n;
    cin >> n;
    while (n--)
    {
        int a, b;
        cin >> a >> b;
        cout << choose(a, b) << endl;
    }

    return 0;
}
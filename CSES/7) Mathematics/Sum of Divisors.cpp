#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll mod = 1e9 + 7;

#define int long long
#define endl '\n'
const int MAXn = 1e6;
int sieve[MAXn];

int gcd(int a, int b)
{
    return (b ? gcd(b, a % b) : a);
}

void buildSieve(int n)
{
    for (int x = 2; x <= n; x++)
    {
        if (sieve[x])
            continue;
        for (int u = 2 * x; u <= n; u += x)
        {
            sieve[u] = x;
        }
    }
}

int eulerPhi(int n)
{
    int res = n;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0)
        {
            while (n % i == 0)
            {
                n /= i;
            }               // to get the prime factor.
            res -= res / i; // res/i is how many numbers have i as a divisor between 1 and res, and we know i|res.)
        }
    if (n > 1)
    {
        res -= res / n;
    }
    return res;
}

int modPow(int x, int n, int mod)
{
    if (n == 0)
    {
        return 1 % mod;
    }
    int u = modPow(x, n / 2, mod);
    u = (u * u) % mod;
    if (n % 2)
    {
        u = (u * x) % mod;
    }
    return u;
}

// p is prime.
int modInverse(int x, int p)
{
    return modPow(x, p - 2, p);
}

int summ(int i)
{
    return (((i % mod) * ((i + 1) % mod)) % mod * modInverse(2, mod)) % mod;
}

int f(int j, int i)
{
    return (summ(j) % mod - summ(i - 1) % mod + mod) % mod;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int ans = 0;
    int i = 1;
    while (i <= n)
    {
        int q = n / i;
        int next = (n / q) + 1;
        int x = next - i, y = i + next - 1;
        if (x % 2 == 0)
        {
            x /= 2;
        }
        else
        {
            y /= 2;
        }
        x %= mod, y %= mod;
        ans = (ans + q % mod * x % mod * y % mod) % mod;
        i = next;
    }
    cout << ans % mod << endl;

    return 0;
}
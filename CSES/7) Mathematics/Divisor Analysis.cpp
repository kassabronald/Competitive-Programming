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
    int num = 1;
    int sumDiv = 1;
    int prodDiv = 1;
    map<int, int> m;
    int d = 1;
    while (n--)
    {
        int p, a;
        cin >> p >> a;
        m[p] = a;
        num = (num * (a + 1)) % mod;
        int sumOfDivOfThisPrime = (modPow(p, a + 1, mod) - 1) % mod * (modInverse(p - 1, mod)) % mod;
        sumDiv = (sumDiv % mod * sumOfDivOfThisPrime % mod) % mod;
        int val = modPow(p, a * (a + 1) / 2, mod);
        prodDiv = (modPow(prodDiv, a + 1, mod) * modPow(val, d, mod)) % mod;
        d = (d * (a + 1)) % (mod - 1);
    }

    cout << num << " " << sumDiv << " " << prodDiv << endl;

    return 0;
}
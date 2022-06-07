#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll mod = 1e9 + 7;

#define int long long
#define endl '\n'
const int MAXn = 1e6;
int sieve[MAXn];

map<int, int> prime_number_decomposition(int x)
{
    map<int, int> res;
    while (x % 2 == 0)
    {
        x /= 2;
        res[2]++;
    }
    for (int i = 3; i * i <= x; i++)
    {
        while (x % i == 0)
        {
            x /= i;
            res[i]++;
        }
    }
    if (x > 2)
    {
        res[x]++;
    }
    return res;
}

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

int NumberOfDivisors(int n)
{
    map<int, int> p = prime_number_decomposition(n);
    int ans = 1;
    for (auto it = p.begin(); it != p.end(); it++)
    {
        ans *= (it->second + 1);
    }
    return ans;
}

vector<int> PhiRange(int n)
{
    vector<int> phi(n + 1, 0);
    phi[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        phi[i] = (i);
    }
    for (int x = 2; x <= n; x++)
    {
        if (phi[x] == x)
        { // i.e x is prime.
            for (int u = x; u <= n; u += x)
            {
                phi[u] -= phi[u] / x; // number of numbers divisible by the prime x. (remove them)
            }
        }
    }
    return phi;
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
vector<int> fac(1e6 + 1, 1);
int choose(int a, int b)
{
    int res = (fac[a] * modInverse((fac[b] * fac[a - b]) % mod)) % mod;
    return res;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    vector<int> cho(1e6 + 1, 1);
    for (int i = 2; i <= 1e6; i++)
    {
        fac[i] = (fac[i - 1] * i) % mod;
    }
    int n;
    cin >> n;
    int total = fact(n);
    int bad = 0;
    for (int i = 0; i <= n; i++)
    {
        cho[i] = choose(n, i);
    }
    // number of function f: {1,2,..n}-->{1,2,..n}
    // st f(x) = x for at least one x in [1,n]
    // inclusion exclusion
    for (int i = 1; i <= n; i++)
    {
        if (i % 2)
        {
            bad = (bad + cho[i] * fac[n - i]) % mod;
        }
        else
        {
            bad = (bad - cho[i] * fac[n - i]) % mod;
        }
    }
    cout << (total - bad + mod) % mod << endl;

    return 0;
}

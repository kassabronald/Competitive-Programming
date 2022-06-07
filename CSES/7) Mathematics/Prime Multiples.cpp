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
    ll n, k;
    cin >> n >> k;
    vector<ll> primes(k);
    for (ll i = 0; i < k; i++)
    {
        cin >> primes[i];
    }
    // inclusion exclusion
    // answer is n/2 + n/3 + n/5 - (n/6 + n/10 + n/15) + (n/30)
    ll ans = 0;
    for (ll i = 1; i < (1 << k); i++)
    { // iterate over all subsets. (except empty (i=0)) //i tells you which
        // bit is on.(i.e which element we take) if r^th bit is on we take the r^th element.
        // go from 0 to 2^(k-1) = (1<<k)-1
        vector<ll> v;
        for (ll j = 0; j < k; j++)
        { // go through all elements.
            if (i & (1 << j))
            { // meaning we take this element because j^th bit of i is on
                v.push_back(primes[j]);
            }
        }
        ll count = 1;
        for (ll p : v)
        {
            if (count > n / p)
            {
                count = n + 1;
                break;
            }
            count *= p;
        }
        if (v.size() % 2)
        {
            ans += (n / count); // odd so add in inclusion exclusion
        }
        else
        {
            ans -= (n / count); // even so remove.
        }
    }

    cout << ans << endl;

    return 0;
}
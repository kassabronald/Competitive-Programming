#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll mod = 1e9 + 7;

#define int long long
#define endl '\n'

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

const int MAXn = 1e6;
int sieve[MAXn];

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
    if (n == 0)
    {
        return 0;
    }
    if (n == 1)
    {
        return 1;
    }
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

int choose(int a, int b)
{
    int res = (fact(a) * modInverse((fact(b) * fact(a - b)) % mod)) % mod;
    return res;
}

template <typename T>
ostream &operator<<(ostream &os, const vector<T> vec)
{
    int n = vec.size();
    os << "[";
    for (int i = 0; i < n - 1; i++)
    {
        os << vec[i] << ", ";
    }
    os << vec[n - 1] << "]" << endl;
    return os;
}

template <typename T>
void removeDuplicates(vector<T> &v)
{
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
}

int mex(unordered_set<int> &s)
{
    int n = (int)s.size();
    int mex = n + 1;
    for (int i = 0; i <= n; i++)
    {
        if (s.find(i) == s.end())
        {
            return i;
        }
    }
    return mex;
}

int grundyNumber(int x, vector<int> &vals, vector<int> &dp)
{
    if (x == 0)
    {
        return 0;
        // terminal state
    }
    if (dp[x] != -1)
    {
        return dp[x];
    }
    unordered_set<int> s;
    for (int i : vals)
    {
        s.insert(grundyNumber(x - i, vals, dp));
    }
    return dp[x] = mex(s);
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int ans = 0;
        vector<int> vals = {1, 2, 3};
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            // int tmp = grundyNumber(x,vals);
            ans ^= (x % 4);
            // why? because 0,k,2k,3k,... are target positions (i.e) we want to move into them
            // thus reduce the game to simple NIM by taking the piles modulo 4.
            // say a pile has 21 stones. Since you can move to 20 which is a multiple of 4 then your opponent
            // can only go to 19,18 or 17 and you can once again go to a winning position (namely 16)
            // he can only go to 15,14,13 you go to 12 he goes to 11 10 9 you go to 8 he goes
            // to 7,6,5 you go to 4, he goes to 1,2,3 you go to 0 you win.
        }
        cout << (ans == 0 ? "second" : "first") << endl;
    }

    return 0;
}
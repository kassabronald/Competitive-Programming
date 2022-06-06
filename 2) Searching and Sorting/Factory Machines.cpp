#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll mod = 1e9 + 7;

vector<int> prime_number_decomposition(int x)
{
    vector<int> res;
    while (x % 2 == 0)
    {
        x /= 2;
        res.push_back(2);
    }
    for (int i = 3; i * i <= x; i++)
    {
        while (x % i == 0)
        {
            x /= i;
            res.push_back(i);
        }
    }
    if (x > 2)
    {
        res.push_back(x);
    }
    return res;
}

ll power(ll x, ll y)
{
    ll res = 1;
    while (y > 0)
    {
        if (y & 1)
        {
            res = res * x;
            res %= mod;
        }
        y = y >> 1;
        x = (x * x) % mod;
    }
    return res % mod;
}

template <typename T>
void print_vec(vector<T> vec)
{
    int n = vec.size();
    if (n == 0)
    {
        cout << "[]" << endl;
        return;
    }
    cout << "[";
    for (int i = 0; i < n - 1; i++)
    {
        cout << vec[i] << ", ";
    }
    cout << vec[n - 1] << "]" << endl;
}

template <typename T>
void print_vec_vec(vector<vector<T>> vec)
{
    int n = vec.size();
    if (n == 0)
    {
        cout << "[{}]" << endl;
        return;
    }
    cout << "[";
    for (int i = 0; i < n - 1; i++)
    {
        print_vec(vec[i]);
    }
}

template <typename T>
void print_vec_pairs(vector<pair<T, T>> vec)
{
    int n = vec.size();
    if (n == 0)
    {
        cout << "[{}]" << endl;
        return;
    }
    cout << "[";
    for (int i = 0; i < n - 1; i++)
    {
        cout << "{" << vec[i].first << ", " << vec[i].second << "} ,";
    }
    cout << "{" << vec[n - 1].first << ", " << vec[n - 1].second << "}]" << endl;
}

int getMSB(int n)
{
    return __builtin_clz(n);
}

bool check(ll mid, vector<ll> &v, ll t)
{
    ll tot = 0;
    for (ll i = 0; i < v.size(); ++i)
    {
        tot += (mid / v[i]);
    }
    return tot >= t;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n, t;
    cin >> n >> t;
    vector<ll> v(n);
    ll minn = 1e9 + 7;
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
        minn = min(minn, v[i]);
    }
    ll end = minn * t;
    ll start = 1;
    while (start < end)
    {
        ll mid = (start + end) >> 1;
        if (check(mid, v, t))
        {
            end = mid;
        }
        else
        {
            start = mid + 1;
        }
    }
    cout << start << endl;

    return 0;
}
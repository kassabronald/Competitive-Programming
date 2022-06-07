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
    print_vec(vec[n - 1]);
    cout << "]" << endl;
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

struct triplet
{
    ll i, j, k;
    triplet(ll ii, ll jj, ll kk)
    {
        i = ii;
        j = jj;
        k = kk;
    }
};

pair<ll, ll> sum(vector<pair<ll, ll>> &v, ll t, ll i)
{

    ll j = v.size() - 1;
    while (i < j)
    {
        ll s = v[i].first + v[j].first;
        if (s < t)
        {
            i++;
        }
        else if (s > t)
        {
            j--;
        }
        else
        {
            return {v[i].second, v[j].second};
        }
    }
    return {-1, -1};
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n, x;
    cin >> n >> x;
    vector<pair<ll, ll>> v(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i].first;
        v[i].second = i;
    }
    sort(v.begin(), v.end());
    triplet ans(-1, -1, -1);
    for (ll i = 0; i < n; i++)
    {
        pair<ll, ll> a = sum(v, x - v[i].first, i + 1);
        if (a.first != -1)
        {
            ans.i = a.first;
            ans.j = a.second;
            ans.k = v[i].second;
            break;
        }
    }
    if (ans.i != -1)
    {
        cout << ans.i + 1 << " " << ans.j + 1 << " " << ans.k + 1 << endl;
    }
    else
    {
        cout << "IMPOSSIBLE" << endl;
    }

    return 0;
}
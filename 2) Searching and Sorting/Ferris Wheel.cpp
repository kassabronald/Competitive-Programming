#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <map>
#include <math.h>
#include <algorithm>
#include <unordered_map>
#include <set>
#include <unordered_set>
using namespace std;

typedef long long ll;
const long long MAXVAL = 10000000;
long long arr[MAXVAL];

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

ll power(int a, int b, int mod)
{
    if (b == 0)
    {
        return 1;
    }
    if (b == 1)
    {
        return a % mod;
    }
    ll res = power(a, b / 2, mod);
    if (b % 2)
    {
        return (((res * res) % mod) * a) % mod;
    }
    else
    {
        return (res * res) % mod;
    }
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

string get_binary(int num)
{
    string res(33, '0');
    int cc = 0;
    while (num >= 1)
    {
        if (num % 2)
        {
            res[cc] = '1';
        }
        else
        {
            res[cc] = '0';
        }
        cc++;
        num /= 2;
    }
    reverse(res.begin(), res.end());
    return res;
}

vector<string> binary(vector<int> vec)
{
    vector<string> res;
    for (int i : vec)
    {
        string s = get_binary(i);
        res.push_back(s);
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n, x;
    cin >> n >> x;
    vector<ll> w(n, 0);
    for (ll i = 0; i < n; i++)
    {
        cin >> w[i];
    }
    sort(w.begin(), w.end());
    ll i = 0;
    ll j = n - 1;
    ll ans = 0;
    while (i <= j)
    {
        if (w[i] + w[j] <= x)
        {
            ans++;
            i++;
            j--;
        }
        else
        {
            j--;
            ans++;
        }
    }
    cout << ans << endl;

    return 0;
}
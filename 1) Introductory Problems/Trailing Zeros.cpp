#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <map>
#include <math.h>
#include <algorithm>
// #include<unordered_map>
// #include<set>
// #include<unordered_set>
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

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin >> n;
    ll ans = 0;
    ll i = 5;
    while (i <= n)
    {
        ans += (n / i);
        i *= 5; // count num of 5 in 1*2*3*4*5....*n (in prime number decomposition) bc 2*5 = 10 and e want num of 10
        // but make sure to take care of powers of 5 that add a 5 to the pnd
    }
    cout << ans << endl;

    return 0;
}
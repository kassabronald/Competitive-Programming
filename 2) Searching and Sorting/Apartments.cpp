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

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> ppl(n, 0);
    vector<int> appa(m, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> ppl[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> appa[i];
    }
    sort(ppl.begin(), ppl.end());
    sort(appa.begin(), appa.end());
    int i = 0;
    int j = 0;
    int count = 0;
    while (i < n)
    {
        while (j < m && (ppl[i] - k > appa[j]))
        {
            j++;
        }
        if (j < m && abs(ppl[i] - appa[j]) <= k)
        {
            count++;
            j++;
        }
        i++;
    }
    cout << count << endl;

    return 0;
}
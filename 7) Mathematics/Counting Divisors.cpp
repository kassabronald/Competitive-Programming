#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const long long MAXVAL = 10000000;
long long arr[MAXVAL];

int prime_number_decomposition(int x)
{
    vector<int> tmp;
    int power = 0;
    int total = 1;
    while (x % 2 == 0)
    {
        x /= 2;
        power++;
    }
    tmp.push_back(power);
    for (int i = 3; i * i <= x; i++)
    {
        if (x % i == 0)
        {
            int poww = 0;
            while (x % i == 0)
            {
                x /= i;
                poww++;
            }
            tmp.push_back(poww);
        }
    }
    if (x > 2)
    {
        tmp.push_back(1);
    }
    for (int i : tmp)
    {
        if (i != 0)
        {
            total = total * (i + 1);
        }
    }
    return total;
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
    int n;
    cin >> n;
    while (n--)
    {
        int x;
        cin >> x;
        cout << prime_number_decomposition(x) << endl;
    }

    return 0;
}
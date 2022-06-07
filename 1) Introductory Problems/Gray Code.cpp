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

vector<string> generate(int n)
{
    if (n == 1)
    {
        vector<string> vec = {"0", "1"};
        return vec;
    }
    vector<string> res;
    vector<string> vec = generate(n - 1);
    for (string s : vec)
    {
        string tmp = s;
        s += "0";
        res.push_back(s);
    }
    for (int i = vec.size() - 1; i >= 0; i--)
    {
        string s = vec[i];
        s += "1";
        res.push_back(s);
    }
    return res;
}

bool differ_by_1(string s1, string s2)
{
    int n = s1.size();
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (s1[i] != s2[i])
        {
            count++;
        }
    }
    return count == 1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin >> n;
    string s(n, '0');
    vector<string> vec = generate(n);
    for (string s : vec)
    {
        cout << s << endl;
    }

    return 0;
}
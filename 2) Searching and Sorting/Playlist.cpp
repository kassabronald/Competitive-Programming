#include <bits/stdc++.h>
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

bool is_sorted(vector<int> vec, int n)
{
    for (int i = 1; i < n; i++)
    {
        if (vec[i] > vec[i + 1])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> vec(n + 1, 0);
    map<int, int> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> vec[i];
        if (m[vec[i]] == 0)
        {
            m[vec[i]] = i;
        }
    }
    int i = 1;
    int j = 2;
    int ans = 1;
    set<int> s;
    s.insert(vec[i]);
    while (j <= n)
    {
        // cout<<"i="<<i<<" j="<<j<<endl;
        // cout<<"m[1]="<<m[1]<<endl;
        if (s.find(vec[j]) == s.end())
        {
            s.insert(vec[j]);
            m[vec[j]] = j;
        }
        else
        {
            i = max(i, m[vec[j]] + 1);
            m[vec[j]] = j;
            j = max(i, j);
        }
        ans = max(ans, j - i + 1);
        j++;
    }
    cout << ans << endl;

    return 0;
}
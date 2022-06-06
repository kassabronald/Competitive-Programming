#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll mod = 1e9 + 7;

#define int long long
#define endl '\n'

template <typename T>
ostream &operator<<(ostream &os, const vector<T> vec)
{
    int n = vec.size();
    if (n == 0)
    {
        os << "[]" << endl;
        return os;
    }
    os << "[";
    for (int i = 0; i < n - 1; i++)
    {
        os << vec[i] << ", ";
    }
    os << vec[n - 1] << "]" << endl;
    return os;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    vector<int> pref(n);
    map<int, int> m;
    m[0] = 1;
    for (int i = 0; i < n; i++)
    {
        pref[i] = (i == 0 ? v[i] : pref[i - 1] + v[i]);
        m[((pref[i]) % n + n) % n]++;
    }
    int ans = 0;
    for (auto it : m)
    {
        ans += (it.second * (it.second - 1)) / 2;
    }
    cout << ans << endl;

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll mod = 1e9 + 7;

#define int long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()

// z[i] := length of the longest string that is, at the same time, a prefix of s and a prefix of the suffix of s starting at i .

vector<int> z_function(string s)
{
    int n = (int)s.length();
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; ++i)
    {
        if (i <= r)
        {
            z[i] = min(r - i + 1, z[i - l]);
        }

        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
        {
            z[i]++;
        }

        if (i + z[i] - 1 > r)
        {
            l = i, r = i + z[i] - 1;
        }
    }
    return z;
}

// p[i] := length of the longest proper prefix of the substring s[0...i] which is also a suffix of this substring.

vector<int> prefix_function(string &s)
{
    int n = (int)s.size();
    vector<int> p(n);
    p[0] = 0;
    for (int i = 1; i < n; i++)
    {
        int l = p[i - 1];
        while (l > 0 && s[i] != s[l])
        {
            l = p[l - 1];
        }
        if (s[i] == s[l])
        {
            l++;
        }
        p[i] = l;
    }
    return p;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    int n = (int)s.size();
    vector<int> z = z_function(s);
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        if (z[i] + i >= n)
        {
            ans.push_back(i);
        }
    }
    for (int i : ans)
    {
        cout << i << " ";
    }
    cout << n << " ";
    cout << endl;

    return 0;
}
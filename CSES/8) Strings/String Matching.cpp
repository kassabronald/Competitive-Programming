#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll mod = 1e9 + 9;

#define int long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()

const int p = 31;
const int N = 1e6 + 1;

vector<int> computeHash(string &s)
{
    int n = (int)s.size();
    vector<int> h(n), pows(n);
    h[0] = (s[0] - 'a' + 1) % mod;
    pows[0] = 1;
    for (int i = 1; i < n; i++)
    {
        pows[i] = (pows[i - 1] * p) % mod;
        h[i] = (h[i - 1] + (s[i] - 'a' + 1) * pows[i]) % mod;
    }
    return h;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    string t;
    cin >> s >> t;
    int n = (int)t.size();
    int m = (int)s.size();
    vector<int> pows(max(n, m) + 1, 1);
    for (int i = 1; i < (int)pows.size(); i++)
    {
        pows[i] = (pows[i - 1] * p) % mod;
    }
    vector<int> hs = computeHash(s);
    vector<int> ht = computeHash(t);
    int final = ht[n - 1];
    int ans = 0;
    for (int i = 0; i < m - n + 1; i++)
    {

        int curHash = (hs[i + n - 1] - (i == 0 ? 0 : hs[i - 1]) + mod) % mod;
        ans += (curHash == (final * pows[i]) % mod);
    }
    cout << ans << endl;

    return 0;
}
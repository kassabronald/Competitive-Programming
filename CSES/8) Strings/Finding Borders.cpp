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
    cin >> s;
    int n = (int)s.size();
    vector<int> pows(n, 1);
    for (int i = 1; i < n; i++)
    {
        pows[i] = (pows[i - 1] * p) % mod;
    }
    vector<int> ans;
    vector<int> h = computeHash(s);
    int i = 0;
    int j = n - 1;
    int size = 1;
    while (size < n)
    {
        if (size == n)
        {
            break;
        }
        int hs = h[i];                                     // multiplied by p^0
        int hf = (h[n - 1] - h[n - size - 1] + mod) % mod; // multiplied by p^(j-size)
        if ((hs * pows[n - size]) % mod == hf)
        {
            ans.push_back(size);
        }
        i++;
        j--;
        size++;
    }
    for (int i : ans)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
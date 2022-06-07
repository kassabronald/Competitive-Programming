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
int arr[MAXVAL];

void solve(string s)
{
    int n = s.size();
    unordered_map<char, int> M;
    string res(n, '?');
    for (int i = 0; i < n; i++)
    {
        M[s[i]]++;
    }

    for (int i = 0; i < n; i++)
    {
        if (M[s[i]] % 2 != 0)
        {
            if (n % 2 == 0)
            {
                cout << "NO SOLUTION" << endl;
                return;
            }
            else
            {
                res[(n / 2)] = s[i];
                M[s[i]]--;
            }
        }
    }
    int j = 0;
    for (auto it = M.begin(); it != M.end(); it++)
    {
        int q = (it->second) / 2;
        char c = it->first;
        for (int i = 0; i < q; i++)
        {
            res[j] = c;
            res[n - j - 1] = c;
            M[c] -= 1;
            j++;
        }
    }
    for (char c : res)
    {
        if (c == '?')
        {
            cout << "NO SOLUTION" << endl;
            return;
        }
    }

    cout << res << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    solve(s);

    return 0;
}
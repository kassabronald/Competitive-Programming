#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const long long MAXVAL = 10000000;
long long arr[MAXVAL];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    int ans = 0;
    char curr = s[0];
    for (int i = 0; i < s.size(); i++)
    {
        int res = 0;
        while (s[i] == curr)
        {
            res++;
            i++;
        }
        ans = max(ans, res);
        curr = s[i];
        i--;
    }
    cout << ans << endl;

    return 0;
}

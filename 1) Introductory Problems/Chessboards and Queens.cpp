#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll mod = 1e9 + 7;

#define int long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
int res;
int n;
vector<string> grid(8);
vector<int> column(8);
vector<int> diag1(16);
vector<int> diag2(16);
void search(int y)
{
    if (y == n)
    {
        res++;
        return;
    }
    for (int x = 0; x < n; x++)
    {
        if (column[x] || grid[x][y] == '*' || diag2[x - y + n - 1] || diag1[x + y])
        {
            continue;
        }
        column[x] = diag1[x + y] = diag2[x - y + n - 1] = 1;
        search(y + 1);
        column[x] = diag1[x + y] = diag2[x - y + n - 1] = 0;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    n = 8;

    for (int i = 0; i < 8; i++)
    {
        cin >> grid[i];
    }
    search(0);
    cout << res << endl;

    return 0;
}
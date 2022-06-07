#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll mod = 1e9 + 7;

#define int long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()

void dfs(vector<string> &grid, vector<vector<bool>> &visited, int i, int j)
{
    visited[i][j] = true;

    vector<pair<int, int>> nbhds = {{i + 1, j}, {i, j + 1}, {i - 1, j}, {i, j - 1}};
    for (pair<int, int> p : nbhds)
    {

        if (p.first >= 0 && p.second >= 0 && p.first < (int)grid.size() && p.second < (int)grid[0].size())
        {
            if (grid[p.first][p.second] == '.' && !visited[p.first][p.second])
            {
                dfs(grid, visited, p.first, p.second);
            }
        }
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    for (int i = 0; i < n; i++)
    {
        cin >> grid[i];
    }
    vector<vector<bool>> visited(n, vector<bool>(m, 0));
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == '.' && !visited[i][j])
            {
                dfs(grid, visited, i, j);
                ans++;
            }
        }
    }
    cout << ans << endl;

    return 0;
}
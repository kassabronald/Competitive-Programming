#include <bits/stdc++.h>
using namespace std;

vector<string> grid(1001);
vector<vector<bool>> visited(1001, vector<bool>(1001, false));
vector<char> curr;
int n, m;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

bool good(int i, int j)
{
    return (i >= 0 && j >= 0 && i < n && j < m && !visited[i][j] && grid[i][j] != '#');
}

bool bfs(int i, int j)
{
    int n = (int)grid.size();
    int m = (int)grid[0].size();
    queue<pair<int, int>> q;
    q.push({i, j});
    pair<int, int> a = {-1, -1};
    vector<vector<pair<int, int>>> parent(n, vector<pair<int, int>>(m, {-1, -1}));
    while (!q.empty())
    {
        pair<int, int> curr = q.front();

        int i = curr.first;
        int j = curr.second;
        visited[i][j] = true;
        q.pop();
        for (int l = 0; l < 4; l++)
        {
            int ii = i + dx[l];
            int jj = j + dy[l];
            if (good(ii, jj))
            {
                if (grid[ii][jj] == 'B')
                {
                    a = {ii, jj};
                    parent[ii][jj] = {i, j};
                    break;
                }
                parent[ii][jj] = {i, j};
                q.push({ii, jj});
                visited[ii][jj] = true;
            }
        }
        if (a.first != -1)
        {
            break;
        }
    }
    if (a.first == -1)
    {
        return false;
    }
    else
    {
        while (grid[a.first][a.second] != 'A')
        {
            pair<int, int> tmp = parent[a.first][a.second];
            if (tmp.first == a.first + 1)
            {
                curr.push_back('U');
            }
            if (tmp.first == a.first - 1)
            {
                curr.push_back('D');
            }
            if (tmp.second == a.second + 1)
            {
                curr.push_back('L');
            }
            if (tmp.second == a.second - 1)
            {
                curr.push_back('R');
            }
            a = tmp;
        }
        reverse(curr.begin(), curr.end());
        return true;
    }
}

int32_t main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> grid[i];
    }

    bool is = false;
    bool done = false;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 'A')
            {
                is = bfs(i, j);
                done = true;

                break;
            }
        }
        if (done)
        {
            break;
        }
    }
    if (is)
    {
        cout << "YES" << endl;
        cout << (int)curr.size() << endl;
        for (char c : curr)
        {
            cout << c << "";
        }
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}
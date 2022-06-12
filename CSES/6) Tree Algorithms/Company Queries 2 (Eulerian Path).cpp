#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
vector<int> depth(2 * MAXN + 2);
vector<int> idx(MAXN);             // idx[i] is the latest index of i in the eulerian tour
vector<int> rev_idx(2 * MAXN + 2); // rev_idx[i] = which node has idx i in the euleurian tour
vector<vector<int>> adj(MAXN);

struct RMQ_index
{
    vector<vector<int>> sparse_table;
    vector<int> logb2;
    vector<int> v;

    RMQ_index(vector<int> &B, int n)
    {
        for (int i = 0; i < n; i++)
        {
            v.push_back(B[i]);
        }
        logb2.resize(n + 1);
        for (int i = 0; (1 << i) <= n; i++)
        {
            logb2[1 << i] = i;
        }
        for (int i = 1; i <= n; i++)
        {
            logb2[i] = max(logb2[i], logb2[i - 1]);
        }
        sparse_table.resize(n + 1, vector<int>(logb2[n] + 1, 1e9 + 7));
        for (int i = 0; i < n; i++)
        {
            sparse_table[i][0] = i;
        }

        for (int j = 1; j <= logb2[n]; j++)
        {
            for (int i = 0; i + (1 << j) - 1 < n; i++)
            {

                int x = v[sparse_table[i][j - 1]];
                int y = v[sparse_table[i + (1 << (j - 1))][j - 1]];
                sparse_table[i][j] = (x < y ? sparse_table[i][j - 1] : sparse_table[i + (1 << (j - 1))][j - 1]);
            }
        }
    }
    // return idx of min(v[i...j])
    int query(int i, int j)
    {
        if (i > j)
        {
            swap(i, j);
        }
        int size = j - i + 1;
        int k = logb2[size];
        int x = v[sparse_table[i][k]];
        int y = v[sparse_table[j - (1 << k) + 1][k]];
        return x < y ? sparse_table[i][k] : sparse_table[j - (1 << k) + 1][k];
    }
};

void dfs(int u, int p, int &cur_idx, int &depth_so_far)
{
    depth[cur_idx] = depth_so_far;
    idx[u] = cur_idx;
    rev_idx[cur_idx] = u;
    for (int v : adj[u])
    {
        if (v != p)
        {
            int prev = depth[cur_idx];
            cur_idx++;
            depth[cur_idx] = prev + 1;
            depth_so_far++;
            dfs(v, u, cur_idx, depth_so_far);
            cur_idx++;
            depth_so_far--;
            idx[u] = cur_idx;
            rev_idx[cur_idx] = u;
            depth[cur_idx] = depth_so_far;
        }
    }
}

int query_lca(int a, int b, RMQ_index &rmq)
{
    int posa = idx[a];
    int posb = idx[b];
    int min_depth_idx = rmq.query(posa, posb);
    int lca = rev_idx[min_depth_idx];
    return lca;
}

int main()
{
    int n, q;
    cin >> n >> q;
    for (int i = 2; i <= n; i++)
    {
        int a;
        cin >> a;
        a--;
        adj[a].push_back(i - 1);
        adj[i - 1].push_back(a);
    }
    int cur_idx = 0;
    int which = 0;
    dfs(0, -1, cur_idx, which);
    RMQ_index rmq(depth, 2 * n);

    while (q--)
    {
        int a;
        int b;
        cin >> a >> b;
        a--;
        b--;
        cout << query_lca(a, b, rmq) + 1 << endl;
    }

    return 0;
}

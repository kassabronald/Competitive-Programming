#include <bits/stdc++.h>
using namespace std;

struct edge
{
    int u, v;
    edge() {}
    edge(int _u, int _v) : u(_u), v(_v) {}
};

struct node
{
    vector<edge> edges;
};

struct graph
{
    vector<node> nodes;
    int n;
    graph(int _n) : n(_n) { nodes.resize(n); }

    void add_edge(int u, int v)
    {
        nodes[u].edges.emplace_back(u, v);
        nodes[v].edges.emplace_back(v, u);
    }

    void BFS(int u, int dest, vector<int> &parent, vector<bool> &visited)
    {

        queue<int> q;
        q.push(u);
        visited[u] = true;
        while (!q.empty())
        {
            int curr = q.front();
            q.pop();
            for (edge e : nodes[curr].edges)
            {
                if (visited[e.v] == false)
                {

                    visited[e.v] = true;
                    parent[e.v] = curr;
                    if (e.v == dest)
                    {
                        return;
                    }
                    q.push(e.v);
                }
            }
        }
    }
};

int main()
{
    int n, m;
    cin >> n >> m;
    graph G(n);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        G.add_edge(a, b);
    }

    vector<int> parent(n, 0);
    vector<bool> visited(n, 0);
    G.BFS(0, n - 1, parent, visited);
    if (visited[n - 1] == false)
    {
        cout << "IMPOSSIBLE" << endl;
    }
    else
    {
        int res = 0;
        vector<int> final;
        int curr = n - 1;
        final.push_back(curr);
        res++;
        while (curr != 0)
        {
            curr = parent[curr];
            res++;
            final.push_back(curr);
        }
        reverse(final.begin(), final.end());
        cout << res << endl;
        for (int i : final)
        {
            cout << i + 1 << " ";
        }
        cout << endl;
    }

    return 0;
}
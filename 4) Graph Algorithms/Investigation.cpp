#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll mod = 1e9 + 7;

#define int long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()

template <typename T>
ostream &operator<<(ostream &os, const vector<T> vec)
{
    int n = vec.size();
    if (n == 0)
    {
        os << "[]" << endl;
        return os;
    }
    os << "[";
    for (int i = 0; i < n - 1; i++)
    {
        os << vec[i] << ", ";
    }
    os << vec[n - 1] << "]" << endl;
    return os;
}

// graph class.
struct edge
{
    // add if weighted + constructor!
    int w;
    int u, v;
    edge() {}
    edge(int _u, int _v, int _w) : u(_u), v(_v), w(_w) {}
};

struct node
{
    vector<edge> edges;
};

struct graph
{
    vector<node> nodes;
    int n;
    vector<edge> edges;
    graph(int _n) : n(_n) { nodes.resize(n); }

    void add_edge(int u, int v, int w)
    {
        edge e(u, v, w);
        edge ep(v, u, w);
        nodes[u].edges.push_back(e);
        // add if undirected.
        //  nodes[v].edges.push_back(ep);
        // edges.push_back(ep);
        edges.push_back(e);
    }

    void dijkstra(int u)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, u});
        map<pair<int, int>, int> m1; // m1[{x, y}] = number of paths to reach y with cost x
        map<pair<int, int>, int> m2; // m2[{x, y}] = minimum nodes needed to reach y with cost x
        map<pair<int, int>, int> m3; // m3[{x, y}] = maximum nodes needed to reach y with cost x
        m1[{0, u}] = 1;
        vector<bool> visited(n, false);
        vector<int> dist(n, 1e18);
        dist[u] = 0;
        while (!pq.empty())
        {
            pair<int, int> p = pq.top();
            if (visited[p.second])
            {
                pq.pop();
                continue;
            }
            int curr = p.second;
            visited[curr] = true;
            pq.pop();
            for (auto &e : nodes[curr].edges)
            {
                if (dist[e.v] == dist[curr] + e.w)
                {
                    m1[{dist[e.v], e.v}] = (m1[{dist[curr], curr}] + m1[{dist[e.v], e.v}]) % mod;
                    m2[{dist[e.v], e.v}] = min(m2[{dist[curr], curr}] + 1, m2[{dist[e.v], e.v}]);
                    m3[{dist[e.v], e.v}] = max(m3[{dist[curr], curr}] + 1, m3[{dist[e.v], e.v}]);
                }

                if (dist[e.v] > dist[curr] + e.w)
                {
                    dist[e.v] = dist[curr] + e.w;
                    pq.push({dist[e.v], e.v});
                    m1[{dist[e.v], e.v}] = m1[{dist[curr], curr}] % mod;
                    m2[{dist[e.v], e.v}] = m2[{dist[curr], curr}] + 1;
                    m3[{dist[e.v], e.v}] = m3[{dist[curr], curr}] + 1;
                }
            }
        }
        cout << dist[n - 1] << " ";
        cout << m1[{dist[n - 1], n - 1}] << " ";
        cout << m2[{dist[n - 1], n - 1}] << " ";
        cout << m3[{dist[n - 1], n - 1}] << endl;
        return;
    }
};

ostream &operator<<(ostream &os, const graph g)
{
    for (int i = 0; i < g.n; i++)
    {
        os << i << " is adjacent to : ";
        for (auto &e : g.nodes[i].edges)
        {
            os << e.v << " ";
        }
        os << endl;
    }
    return os;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    graph g(n);
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        u--;
        v--;
        g.add_edge(u, v, w);
    }
    g.dijkstra(0);

    return 0;
}
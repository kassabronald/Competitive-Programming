#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1ll << 60;

struct edge
{
    int u, v;
    ll w;
    edge() {}
    edge(int _u, int _v, ll _w) : u(_u), v(_v), w(_w) {}
};

struct node
{
    vector<edge> edges;
};

// idea : dist[i][j] = estimate for the j'th shortest path from s to i.
//  the main observation is that computing the j'th shortest path is similar to the actual shortest path:
// dist[i][j] = min(dist[u][j] + w(u, i), dist[u][j]).
// In typical Dijkstra you only visit each node once. Here no we might revisit a node if it improves its kth SP.

struct graph
{
    vector<node> nodes;
    ll n;
    graph(ll _n) : n(_n), nodes(_n) {}

    void add_edge(ll u, ll v, ll w)
    {
        nodes[u].edges.emplace_back(u, v, w);
    }

    vector<ll> dijkstra(ll s, ll t, ll k)
    {
        vector<vector<ll>> dist(n, vector<ll>(k, INF));
        dist[s][0] = 0ll;
        priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
        pq.push({0, s});

        while (!pq.empty())
        {
            ll u = pq.top().second;
            // current vertext under consideration
            ll d = pq.top().first;
            // current path cost under consideration (might be any of the 1...k'th SP)

            pq.pop();
            // cout<<"current vertex is : " << u +1<< " and current cost under consideration is : " << d << endl;
            if (dist[u][k - 1] < d)
            {
                // cout<<"kth shortest path from s to " << u+1 << " is : " << dist[u][k-1] << " and is less than the cost under consideration : " << d << endl;
                continue;
                // basically our current k'th SP is < the current path we are investigating so drop it.
            }

            for (edge e : nodes[u].edges)
            {
                ll v = e.v;
                ll c = e.w;
                // cout<<" end point of edge under consideration is : " << e.v+1 << " and weight of that edge is " << e.w << endl;
                if (dist[v][k - 1] > c + d)
                {
                    // cout<<"kth shortest path to " << v+1 << " is " << dist[v][k-1] << " but our cost under consideration " << d << " + the weight of the edge linking " << u+1 << " to " << v+1 << " being " << c << " is less than this kth shortest path so update it" << endl;
                    dist[v][k - 1] = c + d;
                    pq.push({dist[v][k - 1], v});
                    sort(dist[v].begin(), dist[v].end());
                    // so that the kth SP is what we are considering.
                    //  cout<<"let us see what the vector of kth shortest path to " << v+1 << " now looks like: ";
                    //  print_vec(dist[v]);
                }
            }
        }
        return move(dist.back());
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    ll n, m, k;
    cin >> n >> m >> k;
    graph g1(n);
    for (int i = 0; i < m; i++)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        g1.add_edge(a, b, c);
    }
    vector<ll> vec = g1.dijkstra(0, n - 1, k);
    for (ll c : vec)
    {
        cout << c << " ";
    }

    cin.ignore(2);
    return 0;
}
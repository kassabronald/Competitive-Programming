#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1ll << 60;

template <typename T>
void print_vec(vector<T> vec)
{
	int n = vec.size();
	if (n == 0)
	{
		cout << "[]" << endl;
		return;
	}
	cout << "[";
	for (int i = 0; i < n - 1; i++)
	{
		cout << vec[i] << ", ";
	}
	cout << vec[n - 1] << "]" << endl;
}

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

struct graph
{
	vector<node> nodes;
	int n;
	graph(int _n) : n(_n), nodes(_n) {}

	void add_edge(int u, int v, ll w)
	{
		nodes[u].edges.emplace_back(u, v, w);
	}

	vector<ll> dijkstra(int s, int t)
	{
		vector<ll> dist(n, INF);
		dist[s] = 0ll;
		vector<ll> maxes(n, -INF);
		priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
		pq.push({0, s});
		vector<bool> visited(n, false);

		while (!pq.empty())
		{
			if (visited[pq.top().second])
			{
				pq.pop();
				continue;
			}
			int cur = pq.top().second;
			pq.pop();
			visited[cur] = true;
			for (edge &e : nodes[cur].edges)
			{
				if (dist[e.v] > dist[cur] + e.w)
				{
					dist[e.v] = dist[cur] + e.w;
					pq.push({dist[e.v], e.v});
				}
			}
		}
		return move(dist);
	}
};

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m;
	graph g1(n);
	graph g2(n);
	for (int i = 0; i < m; i++)
	{
		ll a, b, c;
		cin >> a >> b >> c;
		a--;
		b--;
		g1.add_edge(a, b, c);
		g2.add_edge(b, a, c);
	}
	vector<ll> vec1 = g1.dijkstra(0, n - 1);
	vector<ll> vec2 = g2.dijkstra(n - 1, 0);
	ll ans = 1e18 + 7;
	for (int i = 0; i < n; i++)
	{
		for (auto &e : g1.nodes[i].edges)
		{
			ans = min(ans, vec1[i] + vec2[e.v] + e.w / 2);
		}
	}
	cout << ans << endl;

	cin.ignore(2);
	return 0;
}
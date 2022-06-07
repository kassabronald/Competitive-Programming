#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll mod = 1e9 + 7;

#define int long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()

// graph class.
struct edge
{
	// add if weighted + constructor!
	//  int w;
	int u, v;
	edge() {}
	edge(int _u, int _v) : u(_u), v(_v) {}
};

struct node
{
	vector<edge> edges;
	vector<edge> incoming;
};

struct graph
{
	vector<node> nodes;
	int n;
	vector<edge> edges;
	graph(int _n) : n(_n) { nodes.resize(n); }

	void add_edge(int u, int v)
	{
		edge e(u, v);
		edge ep(v, u);
		nodes[u].edges.push_back(e);
		// add if undirected.
		//  nodes[v].edges.push_back(ep);
		// edges.push_back(ep);
		edges.push_back(e);
		nodes[v].incoming.push_back(e);
	}

	void compute()
	{
		vector<int> indegree(n, 0);
		vector<int> dp(n, 0);
		dp[0] = 1;
		// dp[v] = number of ways to reach node v
		//       = sum(dp[u] + 1 / (u,v) in E)
		for (auto &e : edges)
		{
			indegree[e.v]++;
		}
		queue<int> q;
		for (int i = 0; i < n; i++)
		{
			if (indegree[i] == 0)
			{
				q.push(i);
			}
		}
		while (!q.empty())
		{
			int curr = q.front();
			q.pop();
			for (auto &e : nodes[curr].edges)
			{
				indegree[e.v]--;
				if (indegree[e.v] == 0)
				{
					q.push(e.v);
				}
			}
			for (auto &e : nodes[curr].incoming)
			{
				dp[curr] = (dp[curr] + dp[e.u]) % mod;
			}
		}
		cout << dp[n - 1] << endl;
	}
};

ostream &operator<<(ostream &os, const graph g)
{
	for (int i = 0; i < g.n; i++)
	{
		os << i + 1 << " is adjacent to : ";
		for (auto &e : g.nodes[i].edges)
		{
			os << e.v + 1 << " ";
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
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		g.add_edge(u, v);
	}
	g.compute();

	return 0;
}
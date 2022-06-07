#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll mod = 1e9 + 7;

#define int long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()

int ceiling(int a, int b)
{
    int val = (a / b) + ((a % b) != 0);
    return val;
}

vector<int> prime_number_decomposition(int x)
{
    vector<int> res;
    while (x % 2 == 0)
    {
        x /= 2;
        res.push_back(2);
    }
    for (int i = 3; i * i <= x; i++)
    {
        while (x % i == 0)
        {
            x /= i;
            res.push_back(i);
        }
    }
    if (x > 2)
    {
        res.push_back(x);
    }
    return res;
}

void printBin(int n)
{
    std::bitset<32> y(n);
    cout << y << endl;
}

ll power(ll x, ll y)
{
    ll res = 1;
    while (y > 0)
    {
        if (y & 1)
        {
            res = res * x;
            res %= mod;
        }
        y = y >> 1;
        x = (x * x) % mod;
    }
    return res % mod;
}

int modInverse(int x)
{
    return power(x, mod - 2);
}

// returns sum of elmts in vec.
template <typename T>
T SumVector(vector<T> &v)
{
    int ans = 0;
    for (auto &it : v)
    {
        ans += it;
    }
    return ans;
}

template <typename T>
T minimum(vector<T> &v)
{
    int ans = 1e10;
    for (auto &it : v)
    {
        ans = min(ans, it);
    }
    return ans;
}

template <typename T>
T maximum(vector<T> &v)
{
    int ans = -1e10;
    for (auto &it : v)
    {
        ans = max(ans, it);
    }
    return ans;
}

// returns prefSum of vec.
template <typename T>
vector<T> prefixSum(vector<T> &v)
{
    int n = (int)v.size();
    vector<T> p(n);
    p[0] = v[0];
    for (int i = 1; i < n; i++)
    {
        p[i] = p[i - 1] + v[i];
    }
    return p;
}

template <typename T>
void removeDuplicates(vector<T> &v)
{
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
}

int stringToInt(string s)
{
    int n = (int)s.size();
    reverse(s.begin(), s.end());
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans = ans + (s[i] - '0') * pow(10, i);
    }
    return ans;
}

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
    }

    void DFS()
    {
        vector<int> order(n); // only matters if DAG or directed + SCC.
        vector<bool> visited(n, false);
        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                DFS_util(i, visited, order);
            }
        }
        reverse(order.begin(), order.end());
    }
    void DFS_util(int i, vector<bool> &visited, vector<int> &order)
    {
        visited[i] = true;
        for (auto &e : nodes[i].edges)
        {
            if (!visited[e.v])
            {
                DFS_util(e.v, visited, order);
            }
        }
        order.push_back(i);
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

vector<int> SuffixMexes(vector<int> &v)
{
    int n = (int)v.size();
    vector<int> suffix(n);
    vector<int> vis(n + 1);
    for (int i = n - 1, x = 0; i >= 0; i--)
    {
        vis[v[i]] = 1;
        while (vis[x])
        {
            x++;
        }
        suffix[i] = x;
    }
    return suffix;
}

template <typename T1, typename T2>
ostream &operator<<(ostream &os, const map<T1, T2> m)
{
    for (auto it = m.begin(); it != m.end(); it++)
    {
        os << "{" << it->first << "," << it->second << "} ";
    }
    return os;
}

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

template <typename T1, typename T2>
ostream &operator<<(ostream &os, const vector<pair<T1, T2>> vec)
{
    int n = vec.size();
    os << "[";
    for (int i = 0; i < n - 1; i++)
    {
        os << "{" << vec[i].first << ", " << vec[i].second << "} ,";
    }
    os << "{" << vec[n - 1].first << ", " << vec[n - 1].second << "}]";
    return os;
}

template <typename T1, typename T2>
ostream &operator<<(ostream &os, const pair<T1, T2> p)
{
    os << p.first << " " << p.second;
    return os;
}

template <typename T>
ostream &operator<<(ostream &os, const set<T> s)
{
    for (auto it : s)
    {
        cout << it << " ";
    }
    cout << endl;
    return os;
}

template <typename T>
istream &operator>>(istream &istream, vector<T> &v)
{
    for (auto &it : v)
    {
        cin >> it;
    }
    return istream;
}

template <typename T1, typename T2>
istream &operator>>(istream &istream, vector<pair<T1, T2>> &v)
{
    for (auto &it : v)
    {
        cin >> it.first >> it.second;
    }
    return istream;
}

struct triplet
{
    int x, i1, i2;
    triplet(int c, int d, int e)
    {
        x = c;
        i1 = d;
        i2 = e;
    }

    bool operator<(triplet y)
    {
        return x < y.x;
    }
};

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, x;
    cin >> n >> x;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    vector<triplet> p;
    map<int, vector<pair<int, int>>> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            triplet pp(v[i] + v[j], i + 1, j + 1);
            p.push_back(pp);
            m[v[i] + v[j]].push_back({i + 1, j + 1});
        }
    }
    sort(all(p));
    vector<int> ans = {-1, -1, -1, -1};
    for (int i = 0; i < (int)p.size(); i++)
    {
        int current = p[i].x;
        int i1 = p[i].i1;
        int i2 = p[i].i2;
        if (m[x - current].size() > 0)
        {
            // cout<<i1<<" " << i2<<" "<<x-current<<" "<<m[x-current]<<endl;
            for (pair<int, int> l : m[x - current])
            {
                if (l.first != i1 && l.second != i2 && l.second != i1 && l.first != i2)
                {
                    ans = {l.first, l.second, i1, i2};
                    break;
                }
                if (ans[0] != -1)
                {
                    break;
                }
            }
        }
    }
    if (ans[0] != -1)
    {
        for (int i : ans)
        {
            cout << i << " ";
        }
    }
    else
    {
        cout << "IMPOSSIBLE" << endl;
    }

    return 0;
}
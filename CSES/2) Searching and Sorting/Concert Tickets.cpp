#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <map>
#include <math.h>
#include <algorithm>
#include <unordered_map>
#include <set>
#include <unordered_set>

using namespace std;

// variables used for the current problem
int n, m, h, t;
multiset<int> tickets;

void solve()
{
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
	{
		cin >> h;
		tickets.insert(h);
	}
	for (int i = 0; i < m; ++i)
	{
		cin >> t;
		auto it = tickets.upper_bound(t);
		// first price greater than t
		if (it == tickets.begin())
		{
			// no price is less than t bc the first greatest is the first element
			cout << -1 << "\n";
		}
		else
		{
			cout << *(--it) << "\n";
			// index just before
			tickets.erase(it);
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	solve();
	return 0;
}
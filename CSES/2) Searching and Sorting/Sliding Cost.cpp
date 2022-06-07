
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll mod = 1e9 + 7;

#define int long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()

multiset<int> low, high;

int lowSum = 0;
int highSum = 0;

void insert(int val, int k)
{
    auto it = low.rbegin();
    int curr_median = *it;
    if (val > curr_median)
    {
        // insert val in high.
        highSum += val;
        high.insert(val);
        if ((int)high.size() > k / 2)
        {
            lowSum += *high.begin();
            highSum -= *high.begin();
            low.insert(*high.begin());
            high.erase(high.find(*high.begin()));
        }
    }
    else
    {
        // insert val in low.
        low.insert(val);
        lowSum += val;
        if ((int)low.size() > (k + 1) / 2)
        {
            lowSum -= *low.rbegin();
            highSum += *low.rbegin();
            high.insert(*low.rbegin());
            low.erase(low.find(*low.rbegin()));
        }
    }
}

void erase(int val, int k)
{
    if (high.find(val) != high.end())
    {
        highSum -= val;
        high.erase(high.find(val));
    }
    else
    {
        lowSum -= val;
        low.erase(low.find(val));
    }
    if ((int)low.size() == 0)
    {
        lowSum += (*high.begin());
        highSum -= (*high.begin());
        low.insert(*high.begin());
        high.erase(high.find(*high.begin()));
    }
}

int add(int k)
{
    if (k % 2 == 0)
    {
        return 0;
    }
    return *low.rbegin();
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    if (k == 1)
    {
        for (int i : v)
        {
            cout << 0 << " ";
        }
    }
    else
    {
        low.insert(v[0]);
        lowSum += v[0];
        for (int i = 1; i < k; i++)
        {
            insert(v[i], k);
        }
        cout << highSum - lowSum + add(k) << " ";
        for (int i = k; i < n; i++)
        {
            erase(v[i - k], k);
            insert(v[i], k);
            cout << highSum - lowSum + add(k) << " ";
        }
    }

    return 0;
}
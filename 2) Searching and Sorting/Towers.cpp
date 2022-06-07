#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const long long MAXVAL = 10000000;
long long arr[MAXVAL];

bool is_sorted(vector<int> vec, int n)
{
    for (int i = 1; i < n; i++)
    {
        if (vec[i] > vec[i + 1])
        {
            return false;
        }
    }
    return true;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> vec(n, 0);
    vector<int> other;
    for (int i = 0; i < n; ++i)
    {
        cin >> vec[i];
    }
    other.push_back(vec[0]);
    for (int i = 1; i < n; i++)
    {
        int it = upper_bound(other.begin(), other.end(), vec[i]) - other.begin();
        if (it == other.size())
        {
            other.push_back(vec[i]);
        }
        else
        {
            other[it] = vec[i];
        }
    }
    cout << other.size() << endl;

    return 0;
}
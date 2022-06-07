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

typedef long long ll;
const long long MAXVAL = 10000000;
long long arr[MAXVAL];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin >> n;
    map<ll, int> M;
    for (int i = 0; i < n; i++)
    {
        int k;
        cin >> k;
        M[k]++;
    }
    cout << M.size() << endl;

    return 0;
}
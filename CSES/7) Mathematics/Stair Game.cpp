#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
ll mod = 1e9 + 7;

#define int long long
#define endl '\n'

int fact[22];
int ceiling(int a, int b)
{
    int val = (a / b + ((a % b) != 0));
    return val;
}

int numDivisorsInrange(int M, int N, int i)
{

    return (N / i - ceiling(M, i) + 1);
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // fact[0] = fact[1] = 1;
    // for(int i = 1; i < 22; i++){
    //     fact[i] = (i * fact[i-1]);
    // }
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            ans ^= (i % 2 ? x : 0);
        }
        cout << (ans == 0 ? "second" : "first") << endl;
    }

    return 0;
}
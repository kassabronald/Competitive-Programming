#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const long long MAXVAL = 10000000;
long long arr[MAXVAL];

void solve(int n)
{
    if (n == 1)
    {
        cout << 1 << endl;
        return;
    }
    if (n == 3 || n == 2)
    {
        cout << "NO SOLUTION" << endl;
        return;
    }
    if (n % 2 == 0)
    {
        for (int i = n - 1; i >= 1; i -= 2)
        {
            cout << i << " ";
        }
        for (int i = n; i >= 2; i -= 2)
        {
            cout << i << " ";
        }
    }
    else
    {
        for (int i = n - 1; i >= 2; i -= 2)
        {
            cout << i << " ";
        }
        for (int i = n; i >= 1; i -= 2)
        {
            cout << i << " ";
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    solve(n);

    return 0;
}
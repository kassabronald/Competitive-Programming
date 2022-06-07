#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const long long MAXVAL = 10000000;
long long arr[MAXVAL];
const int mod = 1e9 + 7;

ll power(int a, int b, int Mod)
{
    if (b == 0)
    {
        return 1;
    }
    if (b == 1)
    {
        return a % Mod;
    }
    ll res = power(a, b / 2, Mod);
    if (b % 2)
    {
        return (((res * res) % Mod) * a) % Mod;
    }
    else
    {
        return (res * res) % Mod;
    }
}

// fermat little theorem: let p be a prime number. Then for all a in N, st p doesnt divide a;
// a^(p-1) = 1 mod p.
// proof: consider a,2a,3a,4a...(p-1)a. We claim that if sa = ra mod p then s = r.
// proof: sups sa=ra mod p; then a(s-r) = 0 mod p then p divides s-r but s-r < p so s=r.
// thus a*2a*3a...*(p-1)a = 1*2*3...*p-1 mod p
// a^(p-1) * (p-1)! = (p-1)! mod p---> a^(p-1)=1 mod p.

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin >> n;
    while (n--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        ll res = power(b, c, mod - 1);
        cout << power(a, res, mod) << endl;
    }

    return 0;
}
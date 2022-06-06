#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const long long MAXVAL = 10000000;
long long arr[MAXVAL];
const ll mod = 1e9 + 7;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n, x;
    cin >> n >> x;
    vector<ll> vec(n, 0);
    vector<ll> dp(x + 1, 0);
    for (ll i = 0; i < n; i++)
    {
        cin >> vec[i];
    }
    dp[0] = 1;
    set<ll> s;
    for (ll i = 1; i <= x; i++)
    {
        for (ll j = 0; j < n; j++)
        {
            if (i - vec[j] >= 0)
            {
                dp[i] = (dp[i] + dp[i - vec[j]]) % mod;
            }
        }
    }

    cout << dp[x];
    cout << endl;

    return 0;
}

// #include<iostream>
// #include<stack>
// #include<queue>
// #include<vector>
// #include<map>
// #include<math.h>
// #include<algorithm>
// #include<unordered_map>
// #include<set>
// #include<unordered_set>
// using namespace std;

// typedef long long ll;
// const long long MAXVAL = 10000000;
// long long arr[MAXVAL];
// const ll mod = 1e9+7;

// template<typename T>
// void print_vec(vector<T> vec){
//     int n = vec.size();
//     if(n==0){
//         cout << "[] " << endl;
//         return;
//     }
//     cout << "[";
//     for(int i = 0 ; i < n-1 ; i++){
//         cout << vec[i] << ", ";
//     }
//     cout << vec[n-1] << "]" << endl;
// }

// int main(){
//     ios_base:: sync_with_stdio(0);
//     cin.tie(0);
//     ll n,x;
//     cin >> n>>x;
//     vector<ll> vec(n,0);
//     vector<ll> dp(x+1, 0);
//     for(ll i = 0; i < n; i++){
//         cin >> vec[i];
//     }
// 	dp[0] = 1;
// 	set<ll> s;
// 	map<ll,vector< vector<ll> > >m;
// 	m[0] = {{}};
//     for(ll i = 1; i <= x;i++){
//         for(ll j = 0; j < n; j++){
//             if(i-vec[j] >= 0){
//                 dp[i] = (dp[i]+dp[i-vec[j]])%mod;

//                 if(dp[i-vec[j]]>0){
//                     for(vector<ll> p: m[i-vec[j]]){
//                         p.push_back(vec[j]);
//                         m[i].push_back(p);

//                     }
//                 }
//             }
//         }
//     }
//     for(vector<ll> p : m[x]){
//         print_vec(p);
//     }

//     cout << dp[x];
//     cout << endl;

//     return 0;
// }
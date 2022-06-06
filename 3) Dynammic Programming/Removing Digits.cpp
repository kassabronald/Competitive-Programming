
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const long long MAXVAL = 10000000;
long long arr[MAXVAL];
const ll mod = 1e9 + 7;

template <typename T>
void print_vec(vector<T> vec)
{
    int n = vec.size();
    cout << "[";
    for (int i = 0; i < n - 1; i++)
    {
        cout << vec[i] << ", ";
    }
    cout << vec[n - 1] << "]" << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin >> n;
    string s = to_string(n);
    vector<ll> dp(n + 1, 1e9 + 7);
    for (ll i = 1; i <= 9; i++)
    {
        dp[i] = 1;
    }
    for (ll i = 10; i <= n; i++)
    {
        for (char c : to_string(i))
        {
            ll cc = c - '0';
            dp[i] = min(dp[i], dp[i - cc] + 1);
        }
    }
    cout << dp[n] << endl;

    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;

// typedef long long ll;
// const long long MAXVAL = 10000000;
// long long arr[MAXVAL];

// int solve(int n, string str, vector<int>& dp){
//     if(str.size()==1){
//         dp[n] = 1;
//         return 1;
//     }
//     if(dp[n]!=1e9){
//         return dp[n];
//     }
//     dp[n]= 1e9;
//     for(int i = str.size()-1; i >=0; i--){
//         if(str[i]!='0'){
//             int res = solve(n-(str[i]-'0') , to_string(n-(str[i]-'0')), dp);
//             if(1+res < dp[n]){
//                 dp[n] = 1+res;
//             }
//         }
//     }

//     return dp[n];
// }

// int main(){
//     ios_base:: sync_with_stdio(0);
//     cin.tie(0);
//     int n;
//     cin >> n;
//     string str = to_string(n);
//     vector<int> dp(n+1, 1e9);
//     cout << solve(n,str, dp) << endl;

//     return 0;
// }
#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <map>
#include <math.h>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
using namespace std;

typedef long long ll;
const long long MAXVAL = 10000000;
long long arr[MAXVAL];

int main()
{
    ll n;
    cin >> n;
    vector<pair<ll, ll>> events;
    for (ll i = 0; i < n; i++)
    {
        ll u, v;
        cin >> u >> v;
        events.push_back({u, 1});  // entry
        events.push_back({v, -1}); // exit
    }
    sort(events.begin(), events.end());
    ll curr = 0;
    ll maximum = 0;
    for (pair<ll, ll> p : events)
    {
        curr += p.second;
        maximum = max(curr, maximum);
    }

    cout << maximum << endl;

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
// #include<unordered_set>
// using namespace std;

// typedef long long ll;
// const long long MAXVAL = 10000000;
// long long arr[MAXVAL];

// int main(){
//     ll n;
//     cin >> n;
//     unordered_map<ll, ll> M;
//     unordered_set<ll> s;
//     vector<ll> vec;
//     ll mini = 9999999999;
//     ll maxi = -999999999;
//     for(ll i = 0 ; i < n; i++){
//         ll u, v;
//         cin >> u >> v;
//         if(u < mini){
//             mini = u;
//         }
//         if(v > maxi){
//             maxi = v;
//         }
//         s.insert(v);//store exit times
//         M[u] = v;//store entry times
//         vec.push_back(u);
//         vec.push_back(v);
//     }
//     sort(vec.begin(), vec.end());//iterate through possible times in sorted order
//     ll curr = 0;
//     ll maximum = 1;
//     for(auto it : vec){
//         if(s.find(it)!=s.end()){
//             curr--;//means this is an exit time
//         }
//         if(M[it]!=0){//means it is an entry time
//             curr++;
//         }
//         maximum = max(curr, maximum);
//     }
//     cout << maximum << endl;

//     return 0;
// }

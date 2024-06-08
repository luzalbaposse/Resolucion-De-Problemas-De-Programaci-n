#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

const ll MOD = 1e9+7; // para mod
const int MAXN = 2e6+5; // max tamaño del array

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<ii> dp(MAXN); 
    dp[1] = {1,1};
    // for(int i = 2; i < MAXN; i++) { //  O(n)
    //     dp[i] = {(2*dp[i-1].first + dp[i-1].second) % MOD, (dp[i-1].first + 4*dp[i-1].second) % MOD};
    // }
    for(int i = 2; i < MAXN; i++) { //  O(log n)
        dp[i].first = (2*dp[i-1].first + dp[i-1].second) % MOD;
        dp[i].second = (dp[i-1].first + 4*dp[i-1].second) % MOD;
    }
  
    int t; 
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << (dp[n].first + dp[n].second) % MOD << '\n';
    }
  
    return 0;
}





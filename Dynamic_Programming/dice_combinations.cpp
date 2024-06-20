#include <bits/stdc++.h>
#include <iostream>
#define MOD 1000000007
using namespace std;
typedef vector<int> vi;
typedef long long ll;

int f(int n){
    vi dp(n+1, 0); // dp[i] = number of ways to get sum i
    dp[0] = 1; // base case
    for (int i = 1; i <= n; i++){ // bottom-up
        for (int j = 1; j <= min(6, i); j++){ // 6-sided dice
            dp[i] += dp[i-j];
            dp[i] %= MOD;
        }
    }
    return dp[n];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    cout << f(n) << endl;
}
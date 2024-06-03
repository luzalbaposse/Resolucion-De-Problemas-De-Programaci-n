// https://cses.fi/problemset/task/1140
#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

struct p {
    ll s;
    ll e;
    ll r;
};

bool c(p a, p b){
    return a.e < b.e;
}

ll b_s(vector<p>& ps, ll i) {
    ll l = -1;
    ll r = i;
    while (r - l > 1) {
        ll m = l + (r - l) / 2;
        if (ps[m].e < ps[i].s) {
            l = m;
        } else {
            r = m;
        }
    }
    return l;
}

int main() {
    ll n;
    cin >> n;
    vector<p> ps(n);
    for(ll i = 0; i < n; i++){
        cin >> ps[i].s >> ps[i].e >> ps[i].r;
    }

    sort(ps.begin(), ps.end(), c);

    vector<ll> dp(n);
    dp[0] = ps[0].r;

    for(ll i = 1; i < n; i++){
        ll l = b_s(ps, i);
        ll include = ps[i].r;
        if (l != -1) {
            include += dp[l];
        }
        dp[i] = max(include, dp[i-1]);
    }

    cout << dp[n-1] << endl;
    return 0;
}
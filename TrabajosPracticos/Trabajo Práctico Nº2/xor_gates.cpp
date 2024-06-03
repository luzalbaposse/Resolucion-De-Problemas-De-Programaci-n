#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n, q;
    cin >> n >> q;
    vector<ll> xs(n);
    for(ll i = 0; i < n; i++){
        cin >> xs[i];
    }

    vector<ll> ps(n+1);
    ps[0] = 0;
    for(ll i = 1; i <= n; i++){
        ps[i] = ps[i-1] ^ xs[i-1];
    }

    for(ll i = 0; i < q; i++){
        ll a, b;
        cin >> a >> b;
        cout << (ps[b] ^ ps[a-1]) << endl;
    }

    return 0;
}
#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> ii;

int main() {  
    // // #ifndef LOCAL
    // freopen("tests/1.in", "r", stdin);
    // freopen("1bis.out", "w", stdout);
    // // #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll t;
    cin >> t;
    
  
    for(ll _ = 0; _ < t; _++) { 
        ll y, x;
        cin >> y >> x;
        ll tot = 0;
        tot += (y < x) ? ((x - 1) * (x - 1)) : ((y - 1) * (y - 1));
        
        if (y <= x) {
            if (x % 2 == 0) tot += y;
            else tot += x * x - (x - 1) * (x - 1) + 1 - y;
        }
        
        if (x < y) {
            if (y % 2 == 1) tot += x;
            else tot += y * y - (y - 1) * (y - 1) + 1 - x;
        }
        
        cout << tot << "\n";
    }

    return 0;
}

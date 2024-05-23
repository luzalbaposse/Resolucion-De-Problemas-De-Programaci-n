// https://cses.fi/problemset/task/1071

#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef int i;
int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    i t;
    cin >> t;
    while (t--) {
        ll y, x;
        cin >> y >> x;
        
        ll n = max(y, x);
        ll n2 = n * n;
        ll result;
        
        if (n % 2 == 0) {
            //even
            if (y == n) {
                result = n2 - (x - 1);
            } else {
                result = n2 - (2 * n - 1) + (y - 1);
            }
        } else {
            // odd
            if (x == n) {
                result = n2 - (y - 1);
            } else {
                result = n2 - (2 * n - 1) + (x - 1);
            }
        }
        
        cout << result << '\n';
    }

    return 0;
}


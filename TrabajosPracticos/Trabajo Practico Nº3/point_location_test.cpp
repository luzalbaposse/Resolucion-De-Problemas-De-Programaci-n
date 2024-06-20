#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;

#define ll long long
#define vs vector<string>
#define vvi vector<vector<int>>
#define vi vector<int>
#define s string

vs dp(int t, vvi & v) {
    vs rs;

    for (ll i = 0; i < t; ++i) {
        ll x1 = v[i][0], y1 = v[i][1];
        ll x2 = v[i][2], y2 = v[i][3];
        ll x3 = v[i][4], y3 = v[i][5];

        
        ll v1x = x2 - x1, v1y = y2 - y1;
        ll v2x = x3 - x1, v2y = y3 - y1;

        // cross product
        ll cross_product = v1x * v2y - v1y * v2x;

        if (cross_product > 0) {
            rs.push_back("LEFT");
        } else if (cross_product < 0) {
            rs.push_back("RIGHT");
        } else {
            rs.push_back("TOUCH");
        }
    }

    return rs;
}

int main() {
    ll t;
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    vvi v(t, vi(6));

    for (int i = 0; i < t; ++i) {
        for (int j = 0; j < 6; ++j) {
            cin >> v[i][j];
        }
    }

    vs rs = dp(t, v);
    for (const s& r : rs) {
        cout << r << endl;
    }

    return 0;
}

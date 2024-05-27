/*https://cses.fi/problemset/task/1630
*/
#include <bits/stdc++.h>
using namespace std;
#include <iostream>
typedef long long ll;
typedef vector<pair<int,int>> vii;
typedef pair<int,int> ii;

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vii t(n);

    for(int i = 0; i < n; i++) {
        cin >> t[i].first >> t[i].second; 
    }

    
    sort(t.begin(), t.end(), [](const ii& a, const ii& b) {
        return a.first < b.first;
    });

    ll ct = 0;
    ll tr = 0;
    
    for(const auto& ts : t) {
        ct += ts.first;
        tr += ts.second - ct;
    }

    cout << tr << endl; 
    return 0;
}


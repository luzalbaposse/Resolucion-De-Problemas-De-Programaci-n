/* https://cses.fi/problemset/task/1641v
*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, x;
    cin >> n >> x;
    vector<pair<int, int>> a(n);
    
    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i + 1; // me quedo con el índice original
    }
    
    // busco
    for (int i = 0; i < n; i++) {
        unordered_map<int, int> hash_map;
        for (int j = i + 1; j < n; j++) {
            int remaining = x - a[i].first - a[j].first;
            if (hash_map.find(remaining) != hash_map.end()) {
                // wooo solucion!
                cout << a[i].second << " " << a[j].second << " " << hash_map[remaining] << "\n";
                return 0;
            }
            // guardo el valor y el índice original
            hash_map[a[j].first] = a[j].second;
        }
    }
    
    // woon't solucion't
    cout << "IMPOSSIBLE\n";
    return 0;
}

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void solve() {
    string s;
    cin >> s;
    s += s;  
    int n = s.size();
    int i = 0;
    int ans = 0;

    // lexicographically smallest rotation
    while (i < n / 2) {
        ans = i;
        int k = i, j = i + 1;
        while (j < n && s[j] >= s[k]) {
            if (s[j] == s[k]) 
                k++;
            else if (s[j] > s[k]) 
                k = i;
            j++;
        }
        while (i <= k) 
            i += j - k;
    }

    cout << s.substr(ans, n / 2);  
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    solve();
    cout << '\n';

    return 0;
}

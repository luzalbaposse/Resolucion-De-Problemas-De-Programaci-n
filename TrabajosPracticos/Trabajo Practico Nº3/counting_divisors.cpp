#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define ll long long
#define vi vector<int>

// cambié el enfoque: en lugar de calcular los divisores de cada número, los precalculo

vi precompute_divisors(int max_val) {
    vi divisors(max_val + 1, 1);
    divisors[0] = 0; 

    for (int i = 2; i <= max_val; ++i) {
        for (int j = i; j <= max_val; j += i) {
            divisors[j]++;
        }
    }

    return divisors;
}

int main() {
    ll n;
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    vi v(n);

    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }

    int max_val = *max_element(v.begin(), v.end());
    vi divisors = precompute_divisors(max_val);

    for (int i = 0; i < n; ++i) {
        cout << divisors[v[i]] << endl;
    }

    return 0;
}

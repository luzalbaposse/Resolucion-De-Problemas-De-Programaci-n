#include <iostream>
using namespace std;

void missing_number(int n) {
    int x;
    int sum = 0;
    for(int i = 1; i <= n; i++) {
        sum += i;
    }

    for(int i = 1; i < n; i++) { 
        cin >> x;
        sum -= x;
    }
    
    cout << sum;
}

int main() { 
    int n;
    cin >> n;
    missing_number(n);
    return 0;
}

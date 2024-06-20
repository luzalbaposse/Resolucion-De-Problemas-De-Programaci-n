#include <bits/stdc++.h>
#include <iostream>
using namespace std;
typedef vector<int> vi;
typedef long long ll;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    
    cin >> n;
    vi x(n);
    for (int i = 0; i < n; i++){
        cin >> x[i];
    }
    vi l(n, 1);
    l[0] = 0;
    int mx = 0;
    for (int i = 0; i < n; i++){
        if (l[mx] < x[i]){
            mx += 1;
            l[mx] = x[i];
        }
        else{
            int j = lower_bound(l.begin(), l.begin()+ mx + 1, x[i]) - l.begin(); 
            if (l[j] >= x[i]){
                l[j] = x[i];
            }
        }

    }
    cout << mx << endl;
    
}
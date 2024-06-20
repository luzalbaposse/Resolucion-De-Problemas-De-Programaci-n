#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
typedef long long ll;

int main(){
// Uso tablas aditivas
    ll n, q;
    cin >> n >> q;
    vector<ll> a(n+1); // Esta es la tabla 
    for(ll i = 1; i <= n; i++){ // Lleno la tabla con la suma acumulada de los valores del arreglo
        cin >> a[i];
        a[i] += a[i-1];
    }
    for(int i = 0; i < q; i++){ // Leo los valores de los rangos y hago la resta de la tabla para obtener la suma de los valores en el rango [l,r]
        ll l, r;
        cin >> l >> r;
        cout << a[r] - a[l-1] << endl;
    }
    return 0;
}
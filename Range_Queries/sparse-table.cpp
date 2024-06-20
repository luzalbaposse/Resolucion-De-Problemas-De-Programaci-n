/*
Given an array of n integers, your task is to process q queries of the form: what is the minimum value in range [a,b]?
Input
The first input line has two integers n and q: the number of values and queries.
The second line has n integers x_1,x_2,\dots,x_n: the array values.
Finally, there are q lines describing the queries. Each line has two integers a and b: what is the minimum value in range [a,b]?
Output
Print the result of each query.
*/

// Una tabla n log n implica que se puede hacer una busqueda binaria en log n, es decir que se puede hacer una busqueda binaria en el rango de los valores de la tabla
// Para hacer esto se necesita que la operacion sea asociativa, es decir que se pueda hacer la operacion en cualquier orden y el resultado sea el mismo


#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
typedef long long ll;
typedef vector<vector<ll>> vvl;

int main(){
    ll n, q;
    cin >> n >> q;
    vector<ll> a(n); // tabla
    for(ll i = 0; i < n; i++){ // Lleno la tabla con los valores del arreglo
        cin >> a[i];
    }
    vvl st(n, vector<ll>(20)); // Creo la tabla sparse -> st[i][j] = minimo valor en el rango [i,i+2^j-1]
    for(ll i = 0; i < n; i++){ // Lleno la tabla sparse con los valores del arreglo
        st[i][0] = a[i];
    }
    for(ll j = 1; j < 20; j++){ // Lleno la tabla sparse con los valores minimos de los rangos de 2^j -> st[i][j] = min(st[i][j-1], st[i+2^(j-1)][j-1])
        for(ll i = 0; i + (1 << j) <= n; i++){
            st[i][j] = min(st[i][j-1], st[i + (1 << (j-1))][j-1]);
        }
    }
    for(int i = 0; i < q; i++){ // Leo los valores de los rangos y hago la busqueda binaria en la tabla sparse para obtener el minimo valor en el rango [l,r]
        ll l, r;
        cin >> l >> r;
        ll ans = 1e18;
        for(ll j = 19; j >= 0; j--){
            if((1 << j) <= r - l + 1){
                ans = min(ans, st[l][j]);
                l += 1 << j;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
/*
8 4
3 2 4 5 1 1 5 3
2 4
5 6
1 8
3 3

output:
2
1
1
4
*/
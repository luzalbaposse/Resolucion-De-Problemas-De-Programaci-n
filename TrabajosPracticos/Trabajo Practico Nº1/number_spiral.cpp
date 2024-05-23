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

/*Notas:
    -> tengo una espiral q empieza en 1 y va incrementando como un reloj. Si me fijo, los ns en la diagonal son cuadrados perfectos. Entonces, si dado un (x,y) quiero saber el valor de ese n, puedo calcular la diagonal en la que se encuentra y sacar el valor del q me interesa. entonces:
        - si la diagonal es par, n está en la diagonal superior o en la diagonal derecha.
        - si la diagonal es impar, n está en la diagonal inferior o en la diagonal izquierda.
*/


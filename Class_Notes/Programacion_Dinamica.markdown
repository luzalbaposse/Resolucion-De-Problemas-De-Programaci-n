# Clase 2: Programación Dinámica
Table of contents
=================
- [Clase 2: Programación Dinámica](#clase-2-programación-dinámica)
- [Table of contents](#table-of-contents)
- [Programación Dinámica](#programación-dinámica)
  - [Receta para resolver un problema de programación dinámica](#receta-para-resolver-un-problema-de-programación-dinámica)
  - [Problemas](#problemas)
- [El problema de la mochila](#el-problema-de-la-mochila)
  - [Anotación](#anotación)


# Programación Dinámica
Si tenemos estados solapados, vamos a querer intentar no calcularlos dos veces. Para eso, vamos a usar programación dinámica. El ejemplo más canónico es el de la secuencia de Fibonacci. Si calculamos la secuencia de Fibonacci de forma recursiva, vamos a tener que calcular el mismo número muchas veces. Por ejemplo, para calcular `fib(5)`, vamos a tener que calcular `fib(3)` y `fib(4)`, y para calcular `fib(4)` vamos a tener que calcular `fib(3)` de nuevo. Si guardamos los valores que ya calculamos, vamos a poder reutilizarlos y no calcularlos de nuevo.

```c++
int fib(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    return fib(n-1) + fib(n-2);
}
```

En este caso, vamos a tener que calcular `fib(3)` dos veces. Si guardamos los valores que ya calculamos, vamos a poder reutilizarlos y no calcularlos de nuevo.

```c++
int fib(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    if (dp[n] != -1) return dp[n];
    return dp[n] = fib(n-1) + fib(n-2);
}
```

En este caso, `dp` es un vector de enteros que inicializamos con `-1`. Si `dp[n]` es distinto de `-1`, significa que ya calculamos `fib(n)` y lo guardamos en `dp[n]`. Si no, lo calculamos y lo guardamos en `dp[n]`. De esta forma, no vamos a calcular `fib(n)` más de una vez.

La idea clave es: vamos a usar un arreglo para guardar las cosas que ya calculamos y no vamos a calcularlas de nuevo.
Hay varias formas de hacer esto. La más común es la de arriba, que se llama *top-down*. 

```c++
int fib(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    if (dp[n] != -1) return dp[n];
    return dp[n] = fib(n-1) + fib(n-2);
}
```

> Podría pasar que no sepas apriori cuánto espacio necesitas, en ese caso podés usar un `unordered_map` o un `map` para guardar los valores que ya calculaste.

Pensemos el problema con una tabla de seguimiento, supongamos que hacemos:

```c++
    int dp[123456];
    memset(dp, 0, sizeof(dp));
```

i | 0 | 1 | 2 | 3 | 4 | 5 |
--|---|---|---|---|---|---|
dp| 1 | 1 | 0 | 0 | 0 | 0 |

Quiero calcular fibo(5), entonces ahora mi tabla va a quedar así:

i | 0 | 1 | 2 | 3 | 4 | 5 |
--|---|---|---|---|---|---|
dp| 1 | 1 | 0 | 0 | 0 | 0 |
dp | 1 | 1 | 2 | 3 | 5 | 8 |

Y así sucesivamente. De esta forma, vamos a poder calcular `fibo(n)` en `O(n)`.

También podemos hacerlo de forma *bottom-up*. En este caso, vamos a empezar desde los casos base y vamos a ir calculando los valores de forma iterativa.

```c++
int fib(int n) {
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}
```
Lo que tiene esta versión es que se va construyendo, se dejan los cimientos y se va calculando los distintos resultados. Es parecido porque vamos a tener un arreglo pero en este caso vamos a ir llenando de a poco. Como accedemos a posiciones de memoria que son contiguas, es rápido acceder. Una **contra** es que a veces vamos a tener que calcular cosas que no necesitamos, pero es más rápido que la versión de arriba.

Nos da una ventaja más que es que permite **ahorrar memoria**, el hecho de que podamos saber qué tan abajo tenemos que ver, usamos solamente la cantidad de memoria necesaria para calcular el resultado.

Por ejemplo:

```c++
int dp[3];
dp[0] = 1;
dp[1] = 1;
for (int i = 2; i < 3; i++) {
    dp[i%3] = dp[(i-1) % 3] + dp[(i-2)%3]; // Accede a las posiciones 0, 1 y 2
}
```

Con los modulos ganas ahorro de memoria, porque antes tenías 123456 posiciones de memoria y ahora tenes 3. 10^8 es computable, es chico, es casi instantáneo. Ahora, si vos quisieras alocar 10^8 posiciones de memoria, no te va a alcanzar la memoria de la computadora.

Tendríamos algo como:
0 | 1 | 2
--|---|---
1 | 1 | 2

Ahora, 
Posicion | dp[x] | Resultado
---------|-------|----------
i = 2 | dp[2]= dp[1] + dp[0] = 1 + 1 = 2 | 2
i = 3 | dp[0]= dp[2] + dp[1] = 2 + 1 = 3 | 3
i = 4 | dp[1]= dp[0] + dp[2] = 3 + 2 = 5 | 5
i = 5 | dp[2]= dp[1] + dp[0] = 5 + 3 = 8 | 8

Y nuestra tabla inicial de memoria sería ahora:
0 | 1 | 2
--|---|---
3 | 5 | 8

> Si podemos no ahorrarnos memoria, es mejor hacerlo de forma top-down, porque es más fácil de pensar. Si no, es mejor hacerlo de forma bottom-up.

Ahora, **usando una matriz fibonacci**, podemos utilizar exponenciación de matrices para reducir la complejidad de lineal a logarítmica.

$$
\begin{bmatrix}
0 & 1 \\
1 & 1
\end{bmatrix}
$$

Entonces, si quiero calcular el i-ésimo número de fibonacci, podría hacerlo asi con matrices:

$$
\begin{bmatrix}
0 & 1 \\
1 & 1
\end{bmatrix}^i \times \begin{bmatrix} 1 \\ 1 \end{bmatrix}
$$

Una multiplicación de esta matriz avanza un paso en la secuencia de fibonacci. Entonces, si quiero calcular el i-ésimo número de fibonacci, puedo hacerlo en logarítmico.

```c++
vector<vector<int>> multiply(vector<vector<int>> a, vector<vector<int>> b) {
    vector<vector<int>> c(2, vector<int>(2, 0));
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    return c;
}
```

¿Por qué es logarítmico? Veamos otro ejemplo para entenderlo, si quiero calcular 
$$ a^n $$ 
nos va a quedar que:
$$ a^n = a^n-1 \times a $$

Pero lo podemos mejorar aún más, si n es par entonces:
$$ a^n = a^{n/2} \times a^{n/2} $$
Si n es impar entonces:
$$ a^n = a^{n/2} \times a^{n/2} \times a $$

Se aplica algo similar a la exponenciación de matrices, si n es par entonces:
$$ \begin{bmatrix} 0 & 1 \\ 1 & 1 \end{bmatrix}^n = (\begin{bmatrix} 0 & 1 \\ 1 & 1 \end{bmatrix}^{n/2})^2 $$
Si n es impar entonces:
$$ \begin{bmatrix} 0 & 1 \\ 1 & 1 \end{bmatrix}^n = (\begin{bmatrix} 0 & 1 \\ 1 & 1 \end{bmatrix}^{n/2})^2 \times \begin{bmatrix} 0 & 1 \\ 1 & 1 \end{bmatrix} $$

Cuando queremos resolver este tipo de problemas, donde necesito k números anteriores, siempre vamos a tener una matriz del estilo:
$$
\begin{bmatrix}
0 & 1 & 0 & 0 & 0 & 0 & 0 & 0 & 0 & 0 \\
0 & 0 & 1 & 0 & 0 & 0 & 0 & 0 & 0 & 0 \\
0 & 0 & 0 & 1 & 0 & 0 & 0 & 0 & 0 & 0 \\
0 & 0 & 0 & 0 & 1 & 0 & 0 & 0 & 0 & 0 \\
0 & 0 & 0 & 0 & 0 & 1 & 0 & 0 & 0 & 0 \\
0 & 0 & 0 & 0 & 0 & 0 & 1 & 0 & 0 & 0 \\
0 & 0 & 0 & 0 & 0 & 0 & 0 & 1 & 0 & 0 \\
0 & 0 & 0 & 0 & 0 & 0 & 0 & 0 & 1 & 0 \\
0 & 0 & 0 & 0 & 0 & 0 & 0 & 0 & 0 & 1 \\
\end{bmatrix}
$$

## Receta para resolver un problema de programación dinámica
- Probar algunos casos, notar estructura
- Definir función recursiva, escribir semántica
- Revisar solución, casos base y casos recursivos
- Escribir algoritmo top-down
- Opcionales: iterativo, ahorro de memoria, construcción de la solución

> En general usamos programación dinámica en probabilidad. Requiere prácticar notas cuál es la estructura que se está solapando. 

## Problemas
- [Dice Combinations](https://cses.fi/problemset/task/1633)

La cantidad de formas de sumar n se define como:
$$ f(n) = \sum_{i=1}^{min(6,n)} f(n-i) $$
Con casos bases:
$$ f(0) = 1 $$
$$ f(1) = 1 $$

Pero a partir de ahí, se puede hacer de forma recursiva. Si queremos hacerlo de forma iterativa, podemos hacerlo de la siguiente forma:

$$ f(2) = f(1) + f(0) = 1 + 1 = 2 $$
$$ f(3) = f(2) + f(1) + f(0) = 2 + 1 + 1 = 4 $$

Entonces, en c++ sería:
    
```c++
int f(n){
    vector<int> dp(n+1, 0);
    dp[0] = 1;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= min(6, i); j++){
            dp[i] += dp[i-j];
            dp[i] %= MOD;
        }
    }
    return dp[n];
}

int main(){
    int n;
    cin >> n;
    cout << f(n) << endl;
}
```

- [Increasing Subsequences](https://cses.fi/problemset/task/1145)

En términos de fórmula, va a ser:
$$ f(i) = max(f(j) + 1) $$
Donde j es menor a i y a[j] <= a[i]. 

# El problema de la mochila
El problema de la mochila es un problema de optimización combinatoria, es decir, que busca la mejor solución entre un conjunto finito de posibles soluciones a un problema. En este caso, se busca maximizar el valor de los objetos que se pueden llevar en una mochila, sin superar el peso máximo que puede llevar la mochila. 

## Anotación
-> Book shop
$$ f(i,j) = max(f(i-1,j), f(i-1,j-w[i]) + v[i]) $$

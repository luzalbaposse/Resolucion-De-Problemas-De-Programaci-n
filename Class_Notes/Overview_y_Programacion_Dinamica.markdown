# Clase 1: Overview y Programación Dinámica
Table of Contents
=================

- [Clase 1: Overview y Programación Dinámica](#clase-1-overview-y-programación-dinámica)
- [Table of Contents](#table-of-contents)
- [Overview de la materia](#overview-de-la-materia)
  - [Por qué practicar resolver problemas?](#por-qué-practicar-resolver-problemas)
  - [Objetivos](#objetivos)
  - [Temario](#temario)
  - [Bibliografía](#bibliografía)
  - [Ejercicios](#ejercicios)
  - [Evaluación](#evaluación)
  - [Competencias](#competencias)
  - [Lenguajes](#lenguajes)
- [Repaso C++](#repaso-c)
- [Repaso Números Binarios](#repaso-números-binarios)
- [Repaso Representación de Conjuntos](#repaso-representación-de-conjuntos)
- [Complejidad Algoritmica](#complejidad-algoritmica)
  - [Complejidad temporal y espacial](#complejidad-temporal-y-espacial)
  - [C++ STL](#c-stl)
  - [Búsqueda Binaria](#búsqueda-binaria)
  - [Búsqueda ternaria](#búsqueda-ternaria)
  - [Resolviendo problemas - Desafíos](#resolviendo-problemas---desafíos)

====================

# Overview de la materia
## Por qué practicar resolver problemas?
- Practicar abstracción y modelado
- Algoritmos y estructuras de datos
- Ejercitar implementación 
- Oportunidades laborales

## Objetivos
- Aprender algoritmos
- Abstraer: Convertir enunciados en modelos
- Metodología: Cómo encarar un conjunto de problemas

## Temario
- Técnicas algorítmicas
- Estructuras de búsqueda de información
- Problemas de strings
- Teoría de números
- Álgebra lineal
- Geometría
- Grafos

## Bibliografía
- Guide to Competitive Programming
- Competitive Programming books

## Ejercicios
- CSES -> Los TP son de acá
- Codeforces
- AtCoder
- TopCoder
- HackerRank
- Codechef

## Evaluación
- 4 TPs en grupo, cada uno con 4 ejercicios
- Examen final múltiple choice -> teórico
- Nota final 50% de la nota y cada TP aporta 12,5%

## Competencias
- ICPC
  - Torneo Argentino
  - Latam
  - Campeonato Latinoamericano
  - Mundial
- Codeforces
- Meta Hacker Cup
- Topcoder Open

## Lenguajes
- C++

# Repaso C++
Vamos a usar C++11. 

Esto se usa para que la entrada y salida sea más rápida:

```c++
ios::sync_with_stdio(false);
cin.tie(0);
```

Para setear la precisión de los decimales:

```c++
cout << fixed << setprecision(10);
```

Para leer una línea:
    
```c++
    string s;
    getline(cin, s);
```

Tamaño de enteros:

```c++
    int a = 1e9;
    long long b = 1e18;
```

**Ojo con hacer comparaciones de enteros con doubles porque puede haber errores de precisión**. Por ejemplo:
    
```c++
 if (a == b) {
    cout << "Son iguales" << endl;
}
```
Podemos hacer typedef para escribir más cortito:

```c++
typedef long long ll;
```

Observacion: si tengo un entero por un entero y lo guardo en un long, el resultado va a estar mal porque vamos a haber guardado algo de 32 bits en un registro de 64 bits. Para solucionarlo, conviene hacer una multiplicación por 1 de un 1 que esté en un registro de 64 bits. Por ejemplo:
    
```c++
    long long a = 1;
    a *= 1e9;
```

Podemos usar macros para escribir más cortito también:
```c++
#define forn(i, n) for(int i = 0; i < n; i++)
#define forsn(i, s, n) for(int i = s; i < n; i++)
``` 

Para abrir archivos:

```c++
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
```

# Repaso Números Binarios

Todos los números tienen una representación en nuestro espacio de memoria y son binarios. Hay algunas funciones que son útiles, como por ejemplo leadingZeros, trailingZeros o setBits. Nos sirve para hacer operaciones con binario y armar bitmaps para hacer operaciones de conjuntos. Por ejemplo:

```c++
int main(){
    int num = 5328;
    int leadingZeros = __builtin_clz(num); // 19
    int trailingZeros = __builtin_ctz(num); // 4
    int setBits = __builtin_popcount(num); // 5
    
    for (int i = 31; i>=0; i--){
        if(num & (1 << i)){
            cout << i << endl;
        }
    }
return 0;
}
```
# Repaso Representación de Conjuntos

| Operación | Símbolo Matemático | Operación |
|-----------|---------|-----------|
| Unión     | a U b     | (a  | b)   |
| Intersección | a U al revez b | a & b |
| Diferencia | \ | a & ~b |
| Complemento | | | ~a |


# Complejidad Algoritmica

En general, nos interesa el **peor caso**. 
Amortizados: Puede pasar que la complejidad de un algoritmo sea O(n) pero en realidad sea O(n) amortizado. Por ejemplo, si tengo un vector y lo tengo que agrandar, la complejidad es O(n) pero si lo hago n veces, la complejidad es O(n) amortizado. 

No vamos a pedir complejidad, pero hay ejercicios que tienen que entrar en cierto tiempo.

## Complejidad temporal y espacial
- **Temporal**: Cuánto tiempo tarda en ejecutarse un algoritmo
- **Espacial**: Cuánta memoria ocupa un algoritmo

A veces es difícil, alcanza una buena estimación. Recordemos las complejidades de las estructuras de datos más comunes:

| O(*) | Nombre | Ejemplo |
|------|--------|---------|
| O(1) | Constante | Acceder a un elemento de un vector |
| O(log n) | Logarítmica | Búsqueda binaria |
| O(n) | Lineal | Recorrer un vector |
| O(n log n) | n log n | Merge Sort |
| O(n^2) | Cuadrática | Bubble Sort |
| O(n^3) | Cúbica | Floyd-Warshall |
| O(2^n) | Exponencial | Recursión de Fibonacci |
| O(n!) | Factorial | Permutaciones |

Segun entrada:

| Input size | Tiempo de complejidad esperado |
|------------|---------------------------------|
| n <= 10 | O(n!) |
| n <= 20 | O(2^n) |
| n <= 100 | O(n^3) |
| n <= 500 | O(n^2) |
| n <= 10^6 | O(n log n) |
| n is large | O(1) or O(log n) |


## C++ STL

- **Queue**: Cola
- **Stack**: Pila
- **Priority Queue**: Cola de prioridad
- **Deque**: Doble cola
- **Bitset**: Conjunto de bits
- **sort**: Ordena un vector
- **reverse**: Invierte un vector
- **find**: Busca un elemento en un vector
- **count**: Cuenta cuántas veces aparece un elemento en un vector
- **max_element**: Devuelve el máximo elemento de un vector

## Búsqueda Binaria
Nos permite buscar un elemento en un vector ordenado. Además, lo que hace es buscar algo que cumpla una condición. Si tenes algo que es monotono, podés hacer búsqueda binaria. 

```c++
int binarySearch(vector<int> &v, int x){
    int l = 0, r = v.size()-1;
    while (l < r){
        int m = (l+r)/2;
        if (v[m] < x){
            l = m+1;
        } else {
            r = m;
        }
    }
    return l;
}
```

## Búsqueda ternaria
Es una generalización de la búsqueda binaria. Se usa cuando la función es convexa o cóncava. 

```c++
double ternarySearch(double l, double r){
    for (int i = 0; i < 200; i++){
        double m1 = l + (r-l)/3;
        double m2 = r - (r-l)/3;
        if (f(m1) < f(m2)){
            l = m1;
        } else {
            r = m2;
        }
    }
    return f(l);
}
```

## Resolviendo problemas - Desafíos
- Leer y entender el enunciado
  - La trampa está en los casos borde, así que hay que pensar en ellos y ver los ejemplos
- Pensar en un modelo
  - Escribir en papel, de forma matemática qué nos están pidiendo
- Idea 
  - Una vez q modelamos el problema, vemos como lo resolvemos 
- Código 
  - Codear la idea y testearla




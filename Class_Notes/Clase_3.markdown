# Clase 3: Estructuras de Datos

Table of contents
=================
- [Clase 3: Estructuras de Datos](#clase-3-estructuras-de-datos)
- [Table of contents](#table-of-contents)
- [STL - Estructuras Básicas](#stl---estructuras-básicas)
  - [Vector](#vector)
  - [Array](#array)
  - [Pair](#pair)
  - [Tuple](#tuple)
  - [Filas y Pilas](#filas-y-pilas)
    - [Grafos](#grafos)
  - [Conjuntos](#conjuntos)
    - [Map y Set](#map-y-set)

# STL - Estructuras Básicas

## Vector

```cpp
#include <vector>
#include <iostream>

int main() {
    std::vector<int> v = {1, 2, 3, 4, 5};
    v.push_back(6); // O(1)
    v.pop_back(); // O(1)
    v.insert(v.begin() + 2, 10);
    v.erase(v.begin() + 3);
    for (int i = 0; i < v.size(); i++) { // O(n)
        std::cout << v[i] << " ";
    }
    return 0;
}
```

## Array
    
```cpp
    #include <array>
    #include <iostream>

    int main() {
        std::array<int, 5> a = {1, 2, 3, 4, 5}; // O(1) -> El array es más rápido que el vector
        for (int i = 0; i < a.size(); i++) {
            std::cout << a[i] << " ";
        }
        return 0;
    }
```

## Pair
    
```cpp
    #include <iostream>
    #include <utility>

    int main() {
        std::pair<int, int> p = {1, 2};
        std::cout << p.first << " " << p.second << std::endl;
        return 0;
    }
```

## Tuple
        
```cpp
        #include <iostream>
        #include <tuple>
    
        int main() {
            std::tuple<int, int, int> t = {1, 2, 3};
            std::cout << std::get<0>(t) << " " << std::get<1>(t) << " " << std::get<2>(t) << std::endl;
            return 0;
        }
```

Para hacer sort(), conviene usar tuplas o pairs porque se ordenan de acuerdo a su primer elemento.

## Filas y Pilas

```cpp
    #include <queue>
    #include <stack>
    #include <iostream>

    int main() {
        std::queue<int> q;
        q.push(1);
        q.push(2);
        q.push(3);
        while (!q.empty()) {
            std::cout << q.front() << " ";
            q.pop();
        }
        std::cout << std::endl;

        std::stack<int> s;
        s.push(1);
        s.push(2);
        s.push(3);
        while (!s.empty()) {
            std::cout << s.top() << " ";
            s.pop();
        }
        std::cout << std::endl;
        return 0;
    }
```

Las filas son como las del banco, el primero que llega es el primero que se va. Se utilizan para BFS (Breadth-First Search). Las pilas son como las de platos, el último que llega es el primero que se va. Se utilizan para DFS (Depth First Search). 

Los vamos a usar en problemas como:
- BFS: recorrer un grafo en anchura
- DFS: recorrer un grafo en profundidad
- Dijkstra: recorrer un grafo con pesos

### Grafos
Son un conjunto de nodos y aristas que los conectan. Los nodos son los vértices y las aristas son las líneas que los unen. Se van a representar como una matriz de adyacencia o una lista de adyacencia.

## Conjuntos
    
```cpp
        #include <set>
        #include <iostream>
    
        int main() {
            std::set<int> s;
            s.insert(1);
            s.insert(2);
            s.insert(3);
            s.insert(1);
            for (auto x : s) {
                std::cout << x << " ";
            }
            std::cout << std::endl;
            return 0;
        }
 ```

### Map y Set
- Map: es un conjunto de pares clave-valor. Se puede buscar un valor a partir de una clave.
- Set: es un conjunto de valores únicos. Se puede buscar un valor en O(log n). Está ordenado. Usa red black trees -> un árbol binario balanceado.

```cpp
        #include <map>
        #include <iostream>
    
        int main() {
            std::map<int, int> m;
            m[1] = 2;
            m[2] = 3;
            m[3] = 4;
            m[1] = 5;
            for (auto x : m) {
                std::cout << x.first << " " << x.second << std::endl; // O(n)
            }
            return 0;
        }
```
- Unordered set: es un conjunto de valores únicos. Se puede buscar un valor en O(1). No está ordenado. Usa hash tables.
- Unordered map: es un conjunto de pares clave-valor. Se puede buscar un valor a partir de una clave en O(1). No está ordenado. Usa hash tables.

```cpp
        #include <unordered_map>
        #include <iostream>
    
        int main() {
            std::unordered_map<int, int> m;
            m[1] = 2;
            m[2] = 3;
            m[3] = 4;
            m[1] = 5;
            for (auto x : m) {
                std::cout << x.first << " " << x.second << std::endl; // O(n)
            }
            return 0;
        }
```

- Hash Tables: es una estructura de datos que permite almacenar y buscar elementos en O(1). Se usa para buscar elementos en un conjunto. Ejemplo:

```cpp
        #include <unordered_set>
        #include <iostream>
    
        int main() {
            std::unordered_set<int> s;
            s.insert(1);
            s.insert(2);
            s.insert(3);
            s.insert(1);
            for (auto x : s) {
                std::cout << x << " ";
            }
            std::cout << std::endl;
            return 0;
        }
```

- Bitset: es un conjunto de bits. Se usa para almacenar bits. Se puede hacer operaciones de bits en O(1). Ejemplo:

```cpp
        #include <bitset>
        #include <iostream>
    
        int main() {
            std::bitset<10> b;
            b[0] = 1;
            b[1] = 0;
            b[2] = 1;
            b[3] = 0;
            std::cout << b << std::endl;
            return 0;
        }
```

## Heap

Es una estructura de datos que permite insertar y eliminar elementos en O(log n). Se puede hacer un heap de mínimo o de máximo. Se usa para encontrar el mínimo o el máximo de un conjunto de elementos. Ejemplo:

```cpp
        #include <queue>
        #include <iostream>
    
        int main() {
            std::priority_queue<int> pq;
            pq.push(1);
            pq.push(2);
            pq.push(3);
            while (!pq.empty()) {
                std::cout << pq.top() << " ";
                pq.pop();
            }
            std::cout << std::endl;
            return 0;
        }
```

## Tabla Aditiva


 

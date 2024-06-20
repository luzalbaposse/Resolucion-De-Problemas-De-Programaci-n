#include <bits/stdc++.h>
#include <iostream>
using namespace std;
typedef vector<int> vi;
typedef long long ll;

/*
You are in a book shop which sells n different books. You know the price and number of pages of each book.
You have decided that the total price of your purchases will be at most x. What is the maximum number of pages you can buy? You can buy each book at most once.
Input
The first input line contains two integers n and x: the number of books and the maximum total price.
The next line contains n integers h_1,h_2,\ldots,h_n: the price of each book.
The last line contains n integers s_1,s_2,\ldots,s_n: the number of pages of each book.
Output
Print one integer: the maximum number of pages

tengo por ejemplo:
libro 1 libro 2 libro 3 libro 4
4$         8$     5$     3$
5 pag   12 pag  8 pag  1 pag

el output sería 13 (lirbo 1 y 3)

entonces el algoritmo puede ser:
1. crear un vector de n+1 elementos, donde n es el número de libros
2. el vector dp[i] será el máximo número de páginas que puedo comprar con i dinero
3. dp[0] = 0
4. para cada libro, para cada i de 1 a x, si el precio del libro es menor o igual a i, entonces dp[i] = max(dp[i], dp[i-precio del libro] + páginas del libro)
el ooutputp va a ser dp[x]

La pregunta clave es: con esta cantidad de plata  ¿cuántas páginas puedo comprar? y ¿cuál es el máximo número de páginas que puedo comprar con esta cantidad de plata?
*/
int main (){
    
}


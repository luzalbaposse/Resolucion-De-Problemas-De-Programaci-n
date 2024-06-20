#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;

int main(){
    //* Lo hago con un trie 
    struct TrieNode {
        unordered_map<char, TrieNode*> children;
        bool isEndOfWord;
        TrieNode() : isEndOfWord(false) {}
    };

    TrieNode* root = new TrieNode();

    string s;
    cin >> s;
    int n = s.size();
    int k;
    cin >> k;
    vector<string> words(k);

    for(int i = 0; i < k; i++) {
        cin >> words[i];
        TrieNode* current = root;
        for(char c : words[i]) {
            if(current->children.find(c) == current->children.end()) {
                current->children[c] = new TrieNode();
            }
            current = current->children[c];
        }
        current->isEndOfWord = true;
    }

    vector<int> dp(n + 1);
    dp[0] = 1;
    for(int i = 0; i < n; i++) {
        TrieNode* current = root;
        for(int j = i; j < n; j++) {
            if(current->children.find(s[j]) == current->children.end()) {
                break;
            }
            current = current->children[s[j]];
            if(current->isEndOfWord) {
                dp[j + 1] = (dp[j + 1] + dp[i]) % 1000000007;
            }
        }
    }

    cout << dp[n] << endl;
    return 0;
}

//? O(nk)
//? lo que hice fue crear un trie con las palabras del diccionario, luego recorro la palabra s y voy viendo si puedo formar una palabra con las palabras del diccionario. Si puedo formar una palabra, entonces sumo la cantidad de formas que tengo de formar la palabra en la posicion j. Navego el diccionario con un puntero current que se va moviendo a traves de las palabras del diccionario.
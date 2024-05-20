/*
Time limit: 1.00 s
Memory limit: 512 MB

You are given a DNA sequence: a string consisting of characters A, C, G, and T. Your task is to find the longest repetition in the sequence. This is a maximum-length substring containing only one type of character.
Input
The only input line contains a string of n characters.
Output
Print one integer: the length of the longest repetition.
Constraints

1 \le n \le 10^6

Example
Input:
ATTCGGGA

Output:
3
*/

#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

void repetitions(string input){
    int i = 0;
    vector<int> max_count(4,0);
    vector<int> current_count(4,0);
    while (i < input.size()){
        if(i == 0 || input[i] != input[i-1]) {  
            current_count = vector<int>(4,0);
        }

        if(input[i] == 'A'){
            current_count[0]++;
            max_count[0] = max(max_count[0], current_count[0]);
        }
        else if(input[i] == 'C'){
            current_count[1]++;
            max_count[1] = max(max_count[1], current_count[1]);
        }
        else if(input[i] == 'G'){
            current_count[2]++;
            max_count[2] = max(max_count[2], current_count[2]);
        }
        else if(input[i] == 'T'){
            current_count[3]++;
            max_count[3] = max(max_count[3], current_count[3]);
        }
    i++;
    }
    int max = *max_element(max_count.begin(), max_count.end());
    cout << max<< endl;
    
}

int main(){
    string entrada;
    cin >> entrada;
    // auto start = std::chrono::high_resolution_clock::now();
    repetitions(entrada);
    // auto stop = std::chrono::high_resolution_clock::now();
    // auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    // cout << "Time taken by function: " << duration.count() << " microseconds" << endl;
    return 0;
}
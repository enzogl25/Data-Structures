#include <iostream>
#include <vector>
using namespace std;

// (PT) Definindo um alias 'type' como 'int' para facilitar mudanças futuras
// (EN) Defining an alias 'type' as 'int' for easier future modifications
using type = int;

// (PT) Implementação da função para calcular o array LPS (Longest Prefix Suffix)
// (EN) Implementation of the function to compute the LPS (Longest Prefix Suffix) array
// (PT) Complexidade do algoritmo: O(m), onde m é o tamanho da string de entrada
// (EN) Algorithm complexity: O(m), where m is the length of the input string
vector<type> LPS(const string &pattern) {
    int m = pattern.size();
    vector<type> lps(m, 0); // (PT) Vetor para armazenar os valores LPS
                             // (EN) Vector to store LPS values
    int len = 0; // (PT) Comprimento do prefixo que também é sufixo
                 // (EN) Length of the prefix which is also a suffix
    int i = 1;

    // (PT) Construindo o array LPS
    // (EN) Constructing the LPS array
    while (i < m) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

// (PT) Função principal para testar o cálculo do array LPS
// (EN) Main function to test the LPS array computation
int main() {
    string pattern;
    cout << "Enter the pattern: ";
    cin >> pattern;
    
    // (PT) Calculando o array LPS
    // (EN) Computing the LPS array
    vector<type> lps = LPS(pattern);
    
    // (PT) Exibindo o array LPS
    // (EN) Displaying the LPS array
    cout << "LPS array: ";
    for (type value : lps) {
        cout << value << " ";
    }
    cout << endl;
    
    return 0;
}

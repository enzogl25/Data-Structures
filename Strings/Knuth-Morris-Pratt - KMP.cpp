#include <iostream>
#include <vector>
using namespace std;

// (PT) Definindo um alias 'type' como 'int' para facilitar mudanças futuras
// (EN) Defining an alias 'type' as 'int' for easier future modifications
using type = int;

// (PT) Implementação da função para calcular o array LPS (Longest Prefix Suffix)
// (EN) Implementation of the function to compute the LPS (Longest Prefix Suffix) array
//
// (PT) Complexidade do algoritmo: O(m), onde m é o tamanho do padrão
// (EN) Algorithm complexity: O(m), where m is the length of the pattern
vector<type> LPS(const string &pattern) {
    int m = pattern.size();
    vector<type> lps(m, 0);
    int len = 0;
    int i = 1;
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

// (PT) Implementação do algoritmo de busca KMP (Knuth-Morris-Pratt)
// (EN) Implementation of the KMP (Knuth-Morris-Pratt) search algorithm
//
// (PT) Complexidade do algoritmo: O(n + m), onde n é o tamanho do texto e m é o tamanho do padrão
// (EN) Algorithm complexity: O(n + m), where n is the length of the text and m is the length of the pattern
vector<type> KMP(const string &text, const string &pattern) {
    int n = text.size();
    int m = pattern.size();
    vector<type> lps = LPS(pattern);
    vector<type> occurrences;
    int i = 0, j = 0;
    while (i < n) {
        if (text[i] == pattern[j]) {
            i++; 
            j++;
        }
        if (j == m) {
            occurrences.push_back(i - j);
            j = lps[j - 1];
        } else if (i < n && text[i] != pattern[j]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }
    return occurrences;
}

// (PT) Função principal para testar o algoritmo KMP
// (EN) Main function to test the KMP algorithm
int main() {
    // (PT) Definição do texto e do padrão | (EN) Definition of the text and pattern
    string text, pattern;
    cout << "Enter the text: ";
    cin >> text;
    cout << "Enter the pattern: ";
    cin >> pattern;
    
    // (PT) Executa a busca usando o algoritmo KMP | (EN) Performs search using KMP algorithm
    vector<type> occurrences = KMP(text, pattern);
    
    // (PT) Exibe os índices das ocorrências | (EN) Displays the indices of occurrences
    cout << "Pattern found at indices: ";
    for (auto index : occurrences) cout << index << " ";
    cout << endl;
    
    return 0;
}
#include <iostream>
#include <vector>
using namespace std;

// (PT) Definição do tipo de dados usado para o vetor
// (EN) Definition of the data type used for the vector
using type = int;

// (PT) Implementação do algoritmo Selection Sort
// (EN) Implementation of the Selection Sort algorithm
//
// (PT) Complexidade de tempo:
// - Melhor caso: O(n^2)
// - Caso médio: O(n^2)
// - Pior caso: O(n^2)
//
// (EN) Time complexity:
// - Best case: O(n^2)
// - Average case: O(n^2)
// - Worst case: O(n^2)
vector<type> selection_sort(vector<type> &v){
    int n = (int)v.size(); // (PT) Obtém o tamanho do vetor | (EN) Gets the vector size

    for(int i = 0; i < n-1; i++){
        int MIN = i; // (PT) Índice do menor elemento encontrado | (EN) Index of the smallest found element
        
        for(int j = i+1; j < n; j++){
            if(v[j] < v[MIN]){
                MIN = j;
            }
        }
        
        if(MIN != i){
            swap(v[i], v[MIN]); // (PT) Troca os elementos | (EN) Swaps the elements
        }
    }
    return v;
}

// (PT) Função principal para testar o Selection Sort
// (EN) Main function to test Selection Sort
int main() {
    // (PT) Definição do vetor de entrada | (EN) Definition of the input vector
    vector<type> v = {1, 3, 5, 8, 14, 0, 4};
    
    // (PT) Ordena o vetor usando Selection Sort | (EN) Sorts the vector using Selection Sort
    vector<type> sorted_v = selection_sort(v);
    
    // (PT) Exibe os elementos ordenados | (EN) Displays sorted elements
    for (auto u : sorted_v) cout << u << " ";
    cout << endl;
    
    return 0;
}
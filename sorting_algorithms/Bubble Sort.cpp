#include <iostream>
#include <vector>
using namespace std;

// (PT) Definição do tipo de dados usado para o vetor
// (EN) Definition of the data type used for the vector
using type = int;

// (PT) Implementação do algoritmo Bubble Sort otimizado
// (EN) Implementation of the optimized Bubble Sort algorithm
//
// (PT) Complexidade de tempo:
// - Melhor caso: O(n) (quando o vetor já está ordenado e nenhuma troca ocorre)
// - Caso médio: O(n²)
// - Pior caso: O(n²) (quando o vetor está ordenado na ordem inversa)
//
// (EN) Time complexity:
// - Best case: O(n) (when the array is already sorted and no swaps occur)
// - Average case: O(n²)
// - Worst case: O(n²) (when the array is sorted in reverse order)
// (EN) Implementation of the optimized Bubble Sort algorithm
vector<type> bubble_sort(vector<type> &v) {
    int n = v.size(); // (PT) Obtém o tamanho do vetor | (EN) Gets the vector size
    bool swapped;

    for (int i = 0; i < n - 1; i++) {
        swapped = false; // (PT) Flag para verificar se houve troca | (EN) Flag to check if a swap occurred
        
        for (int j = 0; j < n - i - 1; j++) { // (PT) Loop reduzido a cada iteração | (EN) Reduced loop per iteration
            if (v[j] > v[j + 1]) {
                swap(v[j], v[j + 1]);
                swapped = true; // (PT) Indica que houve troca | (EN) Indicates that a swap occurred
            }
        }
        
        if (!swapped) break; // (PT) Se nenhuma troca ocorreu, já está ordenado | (EN) If no swap occurred, it's already sorted
    }
    return v;
}

// (PT) Função principal para testar o Bubble Sort
// (EN) Main function to test Bubble Sort
int main() {
    // (PT) Definição do vetor de entrada | (EN) Definition of the input vector
    vector<type> v = {1, 3, 5, 8, 14, 0, 4};
    
    // (PT) Ordena o vetor usando Bubble Sort otimizado | (EN) Sorts the vector using optimized Bubble Sort
    vector<type> sorted_v = bubble_sort(v);
    
    // (PT) Exibe os elementos ordenados | (EN) Displays sorted elements
    for (auto u : sorted_v) cout << u << " ";
    cout << endl;
    
    return 0;
}

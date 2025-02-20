#include <iostream>
#include <vector>
using namespace std;

// (PT) Definição do tipo de dados usado para o vetor
// (EN) Definition of the data type used for the vector
using type = int;

// (PT) Implementação do algoritmo Insertion Sort
// (EN) Implementation of the Insertion Sort algorithm
//
// (PT) Complexidade de tempo:
// - Melhor caso: O(n) (quando o vetor já está ordenado)
// - Caso médio: O(n^2)
// - Pior caso: O(n^2) (quando o vetor está em ordem inversa)
//
// (EN) Time complexity:
// - Best case: O(n) (when the array is already sorted)
// - Average case: O(n^2)
// - Worst case: O(n^2) (when the array is sorted in reverse order)
vector<type> insertion_sort(vector<type> &v){
    int n = (int)v.size(); // (PT) Obtém o tamanho do vetor | (EN) Gets the vector size

    for(int i = 1; i < n; i++) { // (PT) Itera sobre o vetor a partir do segundo elemento | (EN) Iterates over the array from the second element
        int j = i;
        while(j > 0 && v[j-1] > v[j]) { // (PT) Move o elemento para a posição correta | (EN) Moves the element to the correct position
            swap(v[j], v[j-1]); // (PT) Troca os elementos | (EN) Swaps the elements
            j--;
        }
    }
    return v;
}

// (PT) Função principal para testar o Insertion Sort
// (EN) Main function to test Insertion Sort
int main() {
    // (PT) Definição do vetor de entrada | (EN) Definition of the input vector
    vector<type> v = {1, 3, 5, 8, 14, 0, 4};
    
    // (PT) Ordena o vetor usando Insertion Sort | (EN) Sorts the vector using Insertion Sort
    vector<type> sorted_v = insertion_sort(v);
    
    // (PT) Exibe os elementos ordenados | (EN) Displays sorted elements
    for (auto u : sorted_v) cout << u << " ";
    cout << endl;
    
    return 0;
}
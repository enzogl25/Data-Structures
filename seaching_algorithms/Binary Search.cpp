#include <iostream>     // (PT) Para entrada e saída
                       // (EN) For input and output
#include <vector>       // (PT) Para usar std::vector
                       // (EN) For using std::vector
#include <algorithm>    // (PT) Para std::lower_bound e std::upper_bound
                       // (EN) For std::lower_bound and std::upper_bound

using namespace std;

/**
 * (PT)
 * Realiza uma busca binária no vetor ordenado 'v' para encontrar o índice de 'target'.
 * Se encontrado, retorna o índice; caso contrário, retorna -1.
 * Complexidade de tempo: O(log n)
 *
 * (EN)
 * Performs a binary search on the sorted vector 'v' to find the index of 'target'.
 * If found, returns the index; otherwise, returns -1.
 * Time complexity: O(log n)
 *
 * @param v (PT) Vetor ordenado (const ref para não modificá-lo).
 *           (EN) Sorted vector (const ref so as not to modify it).
 * @param target (PT) Valor que queremos encontrar no vetor.
 *                (EN) The value we want to find in the vector.
 * @return (PT) Índice onde 'target' aparece em 'v', ou -1 se não for encontrado.
 *         (EN) Index where 'target' appears in 'v', or -1 if not found.
 */
int binarySearchFunction(const vector<int> &v, int target) {
    int left = 0;
    int right = static_cast<int>(v.size()) - 1;

    while (left <= right) {
        // (PT) Cálculo "seguro" do meio para evitar overflow
        // (EN) "Safe" calculation of mid to avoid overflow
        int mid = left + (right - left) / 2;

        if (v[mid] == target) {
            return mid; // (PT) Encontrou o valor
                        // (EN) Found the value
        } else if (v[mid] < target) {
            // (PT) Se v[mid] < target, move o ponteiro left para mid + 1
            // (EN) If v[mid] < target, move the left pointer to mid + 1
            left = mid + 1;
        } else {
            // (PT) Se v[mid] > target, move o ponteiro right para mid - 1
            // (EN) If v[mid] > target, move the right pointer to mid - 1
            right = mid - 1;
        }
    }

    // (PT) Se sair do loop, não encontrou o elemento
    // (EN) If the loop ends, the element was not found
    return -1;
}

int main() {
    // (PT) Exemplo de vetor ordenado
    // (EN) Example of a sorted vector
    vector<int> v = {1, 2, 3, 4, 5, 5, 5, 8};

    // (PT) Exemplo de uso da busca binária implementada manualmente
    // (EN) Example of using the manually implemented binary search
    cout << "The index position of 4 is "
         << binarySearchFunction(v, 4) << endl;

    // (PT) Exemplo de uso de lower_bound e upper_bound do C++
    // (EN) Example of using C++ lower_bound and upper_bound
    int value = 5;
    auto lb = lower_bound(v.begin(), v.end(), value);
    auto ub = upper_bound(v.begin(), v.end(), value);

    // (PT) lower_bound -> primeiro elemento que não é menor que 'value' (>=)
    // (EN) lower_bound -> first element not less than 'value' (>=)
    cout << "Lower bound of " << value << " is "
         << (lb - v.begin()) << endl;

    // (PT) upper_bound -> primeiro elemento maior que 'value'
    // (EN) upper_bound -> first element greater than 'value'
    cout << "Upper bound of " << value << " is "
         << (ub - v.begin()) << endl;

    // (PT) Quantas vezes 'value' aparece no vetor
    // (EN) How many times 'value' appears in the vector
    cout << "The value " << value << " appears "
         << (ub - lb) << " times in the vector" << endl;

    return 0;
}

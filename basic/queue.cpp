#include <iostream>
#include <vector>
using namespace std;

// (PT) Definindo um alias 'type' como 'int' para facilitar mudanças futuras
// (EN) Defining an alias 'type' as 'int' for easier future modifications
using type = int;

// (PT) Implementação da classe Queue (Fila) usando um vetor
// (EN) Implementation of the Queue class using a vector
class Queue {
private:
    vector<type> elements; // (PT) Vetor para armazenar os elementos
                          // (EN) Vector to store the elements

public:
    // (PT) Adiciona um elemento ao final da fila (Enqueue)
    // (EN) Adds an element to the end of the queue (Enqueue)
    void push(type value) {
        elements.push_back(value);
        cout << "Enqueued " << value << " into the queue." << endl;
    }

    // (PT) Remove o elemento do início da fila (Dequeue)
    // (EN) Removes the element from the front of the queue (Dequeue)
    void pop() {
        if (elements.empty()) {
            cout << "Queue is empty. Cannot dequeue." << endl;
            return;
        }
        cout << "Dequeued " << elements.front() << " from the queue." << endl;
        elements.erase(elements.begin()); // Remove o primeiro elemento
    }

    // (PT) Retorna o elemento do início da fila sem removê-lo
    // (EN) Returns the front element without removing it
    type front() {
        if (elements.empty()) {
            cout << "Queue is empty. No front element." << endl;
            return -1; // Retorna -1 se estiver vazia
        }
        return elements.front();
    }

    // (PT) Retorna o elemento do final da fila sem removê-lo
    // (EN) Returns the back element without removing it
    type back() {
        if (elements.empty()) {
            cout << "Queue is empty. No back element." << endl;
            return -1; // Retorna -1 se estiver vazia
        }
        return elements.back();
    }

    // (PT) Verifica se a fila está vazia
    // (EN) Checks if the queue is empty
    bool empty() {
        return elements.empty();
    }

    // (PT) Retorna o número de elementos da fila
    // (EN) Returns the number of elements in the queue
    int size() {
        return elements.size();
    }

    // (PT) Exibe todos os elementos da fila
    // (EN) Displays all elements in the queue
    void display() {
        if (elements.empty()) {
            cout << "No elements to display." << endl;
            return;
        }

        cout << "Queue (front to back): ";
        for (size_t i = 0; i < elements.size(); i++) {
            cout << elements[i];
            if (i != elements.size() - 1) cout << " -> ";
        }
        cout << endl;
    }
};

// (PT) Função principal para testar a fila
// (EN) Main function to test the queue
int main() {
    Queue queue;

    // (PT) Testando enqueue (push)
    // (EN) Testing enqueue (push)
    queue.push(10);
    queue.push(20);
    queue.push(30);

    // (PT) Exibindo os elementos
    // (EN) Displaying elements
    queue.display();

    // (PT) Mostrando o elemento da frente
    // (EN) Showing the front element
    cout << "Front element: " << queue.front() << endl;

    // (PT) Mostrando o elemento de trás
    // (EN) Showing the back element
    cout << "Back element: " << queue.back() << endl;

    // (PT) Testando dequeue (pop)
    // (EN) Testing dequeue (pop)
    queue.pop(); // Remove 10
    queue.display();

    // (PT) Mostrando o tamanho da fila
    // (EN) Showing the queue size
    cout << "Queue size: " << queue.size() << endl;

    // (PT) Removendo todos os elementos
    // (EN) Removing all elements
    queue.pop(); // Remove 20
    queue.pop(); // Remove 30
    queue.pop(); // Tentativa de remoção com fila vazia

    return 0;
}

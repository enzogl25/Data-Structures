#include <iostream>
#include <vector>
using namespace std;

// (PT) Definindo um alias 'type' como 'int' para facilitar mudanças futuras
// (EN) Defining an alias 'type' as 'int' for easier future modifications
using type = int;

// (PT) Implementação da classe Stack (Pilha) usando um vetor
// (EN) Implementation of the Stack class using a vector
class Stack {
private:
    vector<type> elements; // (PT) Vetor para armazenar os elementos
                          // (EN) Vector to store the elements

public:
    // (PT) Adiciona um elemento ao topo da pilha
    // (EN) Adds an element to the top of the stack
    void push(type value) {
        elements.push_back(value);
        cout << "Pushed " << value << " Into the stack." << endl;
    }

    // (PT) Remove o elemento do topo da pilha
    // (EN) Removes the element from the top of the stack
    void pop() {
        if (elements.empty()) {
            cout << "Stack is empty. Cannot pop." << endl;
            return;
        }
        cout << "Popped " << elements.back() << " from the stack." << endl;
        elements.pop_back();
    }

    // (PT) Retorna o elemento do topo sem removê-lo
    // (EN) Returns the top element without removing it
    type top() {
        if (elements.empty()) {
            cout << "Stack is empty. No top element." << endl;
            return -1; // Retorna -1 se estiver vazia (pode ser melhor usar std::optional)
        }
        return elements.back();
    }

    // (PT) Retorna o número de elementos da pilha
    // (EN) Returns the number of elements in the stack
    int size() {
        return elements.size();
    }

    // (PT) Verifica se a pilha está vazia
    // (EN) Checks if the stack is empty
    bool empty() {
        return elements.empty();
    }

    // (PT) Exibe todos os elementos da pilha
    // (EN) Displays all elements in the stack
    void display() {
        if (elements.empty()) {
            cout << "No elements to display" << endl;
            return;
        }

        cout << "Stack (top to bottom): ";
        for (int i = elements.size() - 1; i >= 0; i--) {
            cout << elements[i];
            if (i != 0) cout << " -> ";
        }
        cout << endl;
    }
};

// (PT) Função principal para testar a pilha
// (EN) Main function to test the stack
int main() {
    Stack stack;

    // (PT) Testando push
    // (EN) Testing push
    stack.push(10);
    stack.push(20);
    stack.push(30);

    // (PT) Testando pop
    // (EN) Testing pop
    stack.pop(); // Remove 30

    // (PT) Exibindo os elementos
    // (EN) Displaying elements
    stack.display();

    // (PT) Mostrando o elemento do topo
    // (EN) Showing the top element
    cout << "Top element: " << stack.top() << endl;

    // (PT) Mostrando o tamanho
    // (EN) Showing the size
    cout << "Stack size: " << stack.size() << endl;

    // (PT) Removendo todos os elementos
    // (EN) Removing all elements
    stack.pop(); // Remove 20
    stack.pop(); // Remove 10
    stack.pop(); // Pilha vazia, erro tratado

    return 0;
}

#include <iostream>
#include <vector>
using namespace std;

using namespace std;

using type = int;

class Stack{
    private:
    vector<type> elements;

    public:
    void push(type value){
        elements.push_back(value);
    }
    void pop(){
        if (elements.empty()) {
            cout << "Stack is empty. Cannot pop." << endl;
            return;
        }
        elements.pop_back();
    }
    int top(){
        if(elements.empty()){
            return -1;
        }
        else{
            return elements.back();
        }
    }
    int size(){
        return elements.size();
    }
    bool empty(){
        return elements.empty();
    }

    void display(){
        if(elements.empty()){
            cout << "No elements to display" << endl;
        }
        else{
            for(int i = elements.size() - 1; i >= 0; i--){
                cout << elements[i];
                if(i != 0)cout << " ";
                else cout << endl;
            }
        }
        
    }
};

int main() {
    Stack stack;
    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.pop();

    stack.display();

    cout << "Top element: " << stack.top() << endl;

    cout << "Stack size: " << stack.size() << endl;

    stack.pop();
    stack.pop();
    stack.pop(); 
    return 0;
}
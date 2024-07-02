#include <iostream>
#include "PriorityQueue.h"

using namespace std;

int main() {
    PriorityQueue pq;

    //Testar a função push com 4 elementos
    pq.push(1, 0);
    pq.push(2, 0);
    pq.push(30, 1);
    pq.push(40, 2);


    cout << "" << endl;
    //Printar o get
    for (int i = 0; i < pq.size(); ++i) {
        cout << "Elemento " << i << ": ";
        cout << pq.get(i) << std::endl;
    }

    cout << "" << endl;
    //Printar o pop
    for (int i = 0; i < 4; ++i) {
        cout << "Elemento removido: ";
        cout << pq.pop() << std::endl;
    }

    cout << "" << endl;
    //Printar o get
    for (int i = 0; i < pq.size(); ++i) {
        cout << "Elemento " << i << ": ";
        cout << pq.get(i) << endl;
    }

    //Printar o size
    cout << "" << endl;
    cout << "Tamanho da fila: ";
    cout << pq.size() << std::endl;

    //Printar se a fila está vazia
    cout << "" << endl;
    cout << "Fila vazia? ";
    cout << pq.empty() << std::endl;

    pq.~PriorityQueue();
}

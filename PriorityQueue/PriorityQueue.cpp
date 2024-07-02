#include "PriorityQueue.h"
#include "iostream"

using namespace std;

// Construtor da classe Node
Node::Node(int data, int priority) {
    this->data = data;
    this->priority = priority;
    this->next = nullptr;
    this->prev = nullptr;
}

// Inicializa a fila com tamanho 0 e os ponteiros head e tail como nullptr
PriorityQueue::PriorityQueue() {
    this->sizeQueue = 0;
    this->head = nullptr;
    this->tail = nullptr;
    for (int i = 0; i < NUM_PRIORITIES; i++) {
            this->priority[i].Priority = i;
            this->priority[i].headPriority = nullptr;
            this->priority[i].tailPriority = nullptr;
            this->priority[i].sizePriority = 0;
        }
}

// Adiciona um elemento na fila de acordo com a prioridade
void PriorityQueue::push(int data, int priority) {
    if (priority < 0 || priority >= NUM_PRIORITIES) {
        std::cout << "Prioridade invalida. Deve estar no intervalo [0, " << (NUM_PRIORITIES - 1) << "]" << std::endl;
        exit(1);
    }

    Node* newNode = new Node(data, priority);
    setPointerPriority(newNode);

    // Se a fila estiver vazia, o novo nó é o head e o tail
    if (newNode->prev == nullptr) {
        updateHeadTail();
    }

    this->sizeQueue++;

    // Atualiza os ponteiros next e prev da lista de prioridades
    linkSublistNodes();
}



int PriorityQueue::pop() {
    if (this->sizeQueue == 0) {
        std::cout << "Fila vazia" << std::endl;
        return 0;
    }

    Node* node = this->head;
    int data = node->data;

    // Se a fila tiver apenas um elemento, o head e o tail são nullptr
    if (node->next == nullptr) {
        priority[node->priority].headPriority = nullptr;
        priority[node->priority].sizePriority--;
        head = nullptr;
    } else {
        priority[node->priority].headPriority = node->next;
        priority[node->priority].sizePriority--;
        head = node->next;
    }

    sizeQueue--;
    delete node;
    return data;
}

int PriorityQueue::size() {
    return this->sizeQueue;
}

bool PriorityQueue::empty() {
    return this->sizeQueue == 0;
}

// Retorna o elemento da fila de acordo com o índice, se for maior que sizeQueue/2, a busca é feita a partir do tail
int PriorityQueue::get(int index) {
    if (this->sizeQueue == 0) {
        return 0;
    }

    if (index < this->sizeQueue / 2) {
        int aux = 0;
        Node* current = this->head;

        while (current != nullptr) {
            if (aux == index) {
                return current->data;
            }
            current = current->next;
            aux++;
    }
    } else {
        int numberCase = sizeQueue - index - 1;
        int aux = 0;
        Node* current = this->tail;

        while (current != nullptr) {
            if (aux == numberCase) {
                return current->data;
            }
            current = current->prev;
            aux++;
        }
    }
}

// Adiciona um nó na lista de prioridades, de acordo com a prioridade
void PriorityQueue::setPointerPriority(Node *node) {
    int priorityLevel = node->priority;

    // Se a lista de prioridades estiver vazia, o nó é o primeiro e o último
    if (priority[priorityLevel].sizePriority == 0) {
        priority[priorityLevel].headPriority = node;
        priority[priorityLevel].tailPriority = node;
        priority[priorityLevel].sizePriority++;
    } else {
        node->prev = priority[priorityLevel].tailPriority;
        priority[priorityLevel].tailPriority->next = node;
        priority[priorityLevel].tailPriority = node;
        priority[priorityLevel].sizePriority++;
    }
}

// Atualiza os ponteiros head e tail da fila geral
void PriorityQueue::updateHeadTail() {
    if (this->sizeQueue == 0) {
        this->head = nullptr;
        this->tail = nullptr;
        return;
    }

    int greaterPriority = 0;
    int smallerPriority = 0;

    // Encontra a maior e a menor prioridade
    for (int i = NUM_PRIORITIES - 1; i >= 0; i--) {
        if (priority[i].sizePriority > 0) {
            greaterPriority = i;
            break;
        }
    }
    for (int i = 0; i < NUM_PRIORITIES; i++) {
        if (priority[i].sizePriority > 0) {
            smallerPriority = i;
            break;
        }
    }

    // Atualiza os ponteiros head e tail
    this->head = priority[greaterPriority].headPriority;
    this->tail = priority[smallerPriority].tailPriority;
}

// Atualiza os ponteiros next e prev da lista de prioridades
void PriorityQueue::linkSublistNodes() {
    Node* currentTail = nullptr;

    for (int i = NUM_PRIORITIES - 1; i >= 0; i--) {
        if (priority[i].sizePriority > 0) {
            if (currentTail != nullptr) {
                currentTail->next = priority[i].headPriority;
                priority[i].headPriority->prev = currentTail;
            }

            currentTail = priority[i].tailPriority;
        }
    }

    updateHeadTail();
}

// Destrutor da classe PriorityQueue
PriorityQueue::~PriorityQueue() {
    Node* current = this->head;
    Node* next = nullptr;

    while (current != nullptr) {
        next = current->next;
        delete current;
        current = next;
    }
}





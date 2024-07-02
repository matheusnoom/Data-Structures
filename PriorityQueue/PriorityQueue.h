#ifndef PRIORITYQUEUE_PRIORITYQUEUE_H
#define PRIORITYQUEUE_PRIORITYQUEUE_H
#define NUM_PRIORITIES 3

class Node {
public:
    Node(int data, int priority);
    int data;
    int priority;
    Node* next;
    Node* prev;
};

class Priority {
public:
    int Priority;
    int sizePriority;
    Node* headPriority;
    Node* tailPriority;
};

class PriorityQueue {
public:
    int sizeQueue;
    Node* head;
    Node* tail;
    Priority priority[NUM_PRIORITIES];
    PriorityQueue();
    ~PriorityQueue();
    void push(int data, int priority);
    int pop();
    int get(int index);
    int size();
    bool empty();

private:
    void setPointerPriority(Node* node);
    void updateHeadTail();
    void linkSublistNodes();
};

#endif //PRIORITYQUEUE_PRIORITYQUEUE_H

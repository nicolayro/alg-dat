#include <iostream>
 
class Node {
public:
    int number;
    Node *next;

    Node(int num) {
        number = num;
        next = NULL;
    }

    void print() {
        std::cout << number << " ";
    }
};

class Queue {
private:
    Node *head, *tail;
public:
    Queue() {
        head = NULL;
        tail = NULL;
        std::cout << "Created Queue" << std::endl;
    }

    void enqueue(int number) {
        Node *node = new Node(number);
        if (isEmpty()) {
            head = node;
            tail = node;
            return;
        }
        tail->next = node;
        tail = node;
    }

    Node dequeue() {
        Node *temp = head;
        head = head->next;
        return *temp;
    }

    Node peek() {
        return *head;
    }

    bool isEmpty() {
        return tail == NULL && head == NULL;
    }

    void print() {
        if(isEmpty()) {
            std::cout << "Queue is empty" << std::endl;
        }

        for(Node *n = head; n != NULL; n = n->next) {
            n->print();
        }
        std::cout << std::endl;
    }

};
int main() {
    Queue queue;

    bool done = false;
    int number;
    while(!done) {
        std::cout << "Please enter a number: ";
        std::cin >> number; 
        if (number < 0) {
            done = true;
        }
        queue.enqueue(number);
        std::cout << std::endl << "Queue: "; 
        queue.print();
    }

    return 0;
}

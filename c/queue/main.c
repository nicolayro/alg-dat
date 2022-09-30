#include <stdio.h>
#include <stdlib.h>

struct Node {
    struct Node* next;
    int number;
};

struct Queue {
    struct Node* head;
    struct Node* tail;
};

void enqueue(struct Node* n, struct Queue* queue) {
    printf("enqueing %d (%p)\n", n->number, &n->number);
    if (!queue->head) {
        // If queue is empty, set the node as the head and tail
        (*queue).head = n; // Method 1
        queue->tail = n; // Method 2
    } else {
        queue->tail->next = n; 
        queue->tail = n;
    }
};

struct Node* dequeue(struct Queue* queue) {
    if (queue->head == NULL) {
        printf("queue underflow");
        exit(-1);
    }
    if (queue->head == queue->tail) {
        struct Node* head = queue->head;
        queue->head = NULL;
        queue->tail = NULL;
        return head;
    }
    struct Node* head = queue->head;
    queue->head = head->next;
    return head;
}

struct Node* peek(struct Queue* queue) {
    return queue->head;
}

void print_queue(struct Queue* queue) {
    printf("Queue: ");
    for (struct Node* n = queue->head; n != queue->tail; n = n->next) {
        printf("%d ", n->number);
    }
    printf("\n");
};

int main(int argc, char** argv) {
    struct Queue queue = {
        .head = NULL,
        .tail = NULL
    };

    // Some nodes to fill the queue with

    int num_nodes = 4;
    struct Node nodes[num_nodes];
    struct Node n = { .next = NULL, .number = 0};
    struct Node a = { .next = NULL, .number = 1 };
    struct Node b = { .next = NULL, .number = 2 };
    struct Node c = { .next = NULL, .number = 3 };
    printf("Nodes initialized\n");
    nodes[0] = n;
    nodes[1] = a;
    nodes[2] = b;
    nodes[3] = c;

    // Populating Queue
    for (int i = 0; i < num_nodes; i++) {
        enqueue(&nodes[i], &queue);
    }
    printf("Queue populated\n");
    
    struct Node* look = peek(&queue);
    printf("Peek: %d (%p)\n", look->number, &look->number);

    print_queue(&queue);

    struct Node* first = dequeue(&queue);
    printf("Dequeue: %d (%p)\n", first->number, &(first->number));

    first = dequeue(&queue);
    printf("Dequeue: %d (%p)\n", first->number, &(first->number));

    first = dequeue(&queue);
    printf("Dequeue: %d (%p)\n", first->number, &(first->number));

    first = dequeue(&queue);
    printf("Dequeue: %d (%p)\n", first->number, &(first->number));

    first = dequeue(&queue);
    printf("Dequeue: %d (%p)\n", first->number, &(first->number));

    print_queue(&queue);
    return 0;
};

class myDeque {
public:

    struct Node {
        int data;
        Node* prev;
        Node* next;

        Node(int x) {
            data = x;
            prev = nullptr;
            next = nullptr;
        }
    };

    Node* front;
    Node* rear;

    myDeque() {
        front = nullptr;
        rear = nullptr;
    }

    void insertFront(int x) {
        Node* newNode = new Node(x);

        if (front == nullptr) {
            front = rear = newNode;
        }
        else {
            newNode->next = front;
            front->prev = newNode;
            front = newNode;
        }
    }

    void insertRear(int x) {
        Node* newNode = new Node(x);

        if (rear == nullptr) {
            front = rear = newNode;
        }
        else {
            newNode->prev = rear;
            rear->next = newNode;
            rear = newNode;
        }
    }

    void deleteFront() {
        if (front == nullptr)
            return;

        Node* temp = front;

        if (front == rear) {
            front = rear = nullptr;
        }
        else {
            front = front->next;
            front->prev = nullptr;
        }

        delete temp;
    }

    void deleteRear() {
        if (rear == nullptr)
            return;

        Node* temp = rear;

        if (front == rear) {
            front = rear = nullptr;
        }
        else {
            rear = rear->prev;
            rear->next = nullptr;
        }

        delete temp;
    }

    int getFront() {
        if (front == nullptr)
            return -1;

        return front->data;
    }

    int getRear() {
        if (rear == nullptr)
            return -1;

        return rear->data;
    }
};
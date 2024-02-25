#include <iostream>
#include <string>
using namespace std;
class Node {
    friend class Queue;
private:
    string data;
    Node* next;
    // Конструктор узла
    Node(string data) : data(data), next(nullptr) {}
};
class Queue {
private:
    Node* front;
    Node* rear;
    int size;
public:
    // Конструктор очереди
    Queue() : front(nullptr), rear(nullptr), size(0) {}
    // Добавление элемента в очередь (enqueue)
    void enqueue(string data) {
        Node* new_node = new Node(data);
        if (rear == nullptr) {
            front = new_node;
            rear = new_node;
        } else {
            rear->next = new_node;
            rear = new_node;
        }
        size++;
    }
    // Удаление элемента из очереди (dequeue)
    string dequeue() {
        if (front == nullptr) {
            return "";
        }
        string data = front->data;
        Node* temp = front;
        front = front->next;
        if (front == nullptr) {
            rear = nullptr;
        }
        delete temp;
        size--;
        return data;
    }
    // Печать содержимого очереди
    void printQueue() {
        Node* current = front;
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
    // Подсчет количества строк, начинающихся с букв «f» или «t»
    int countStringsStartingWithFT() {
        int count = 0;
        Node* current = front;
        while (current) {
            if (current->data[0] == 'f' || current->data[0] == 't') {
                count++;
            }
            current = current->next;
        }
        return count;
    }
};
int main() {
    Queue queue;
    queue.enqueue("one");
    queue.enqueue("two");
    queue.enqueue("three");
    queue.enqueue("four");
    queue.enqueue("five");
    queue.enqueue("six");
    cout << "Содержимое очереди:" << endl;
    queue.printQueue();
    queue.dequeue();
    queue.dequeue();
    queue.enqueue("seven");
    cout << "Содержимое очереди после операций:" << endl;
    queue.printQueue();
    int count = queue.countStringsStartingWithFT();
    cout << "Количество строк, начинающихся с 'f' или 't': " << count << endl;
    return 0;
}

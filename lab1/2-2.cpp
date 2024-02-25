#include <iostream>
#include <string>
using namespace std;
class Node {
    friend class Queue;
private:
    string data;
    Node* next;
    // ����������� ����
    Node(string data) : data(data), next(nullptr) {}
};
class Queue {
private:
    Node* front;
    Node* rear;
    int size;
public:
    // ����������� �������
    Queue() : front(nullptr), rear(nullptr), size(0) {}
    // ���������� �������� � ������� (enqueue)
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
    // �������� �������� �� ������� (dequeue)
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
    // ������ ����������� �������
    void printQueue() {
        Node* current = front;
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
    // ������� ���������� �����, ������������ � ���� �f� ��� �t�
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
    cout << "���������� �������:" << endl;
    queue.printQueue();
    queue.dequeue();
    queue.dequeue();
    queue.enqueue("seven");
    cout << "���������� ������� ����� ��������:" << endl;
    queue.printQueue();
    int count = queue.countStringsStartingWithFT();
    cout << "���������� �����, ������������ � 'f' ��� 't': " << count << endl;
    return 0;
}

#include <iostream>
struct Node {
    int data;
    Node* prev;
    Node* next;
    Node(int val) : data(val), prev(nullptr), next(nullptr) {}
};
class DoublyLinkedList {
private:
    Node* head;
    Node* tail;
public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}
    void append(int data) {
        Node* new_node = new Node(data);
        if (!head) {
            head = new_node;
            tail = new_node;
        } else {
            new_node->prev = tail;
            new_node->next = head;
            tail->next = new_node;
            tail = new_node;
            head->prev = tail;
        }
    }
    void del15() {
        Node* current = tail;
        while (current->data >= 15) {
            current = current->prev;
            if (current == tail) {
                return;
            }
        }
        if (current == head) {
            head = current->next;
        }
        current->prev->next = current->next;
        current->next->prev = current->prev;
        delete current;
    }
    void print_list() {
        Node* current = head;
        do {
            std::cout << current->data << " ";
            current = current->next;
        } while (current != head);
        std::cout << std::endl;
    }
};
int main() {
    DoublyLinkedList dll;
    int num;
    char choice;
    do {
        std::cout << "Введите целое число: ";
        std::cin >> num;
        dll.append(num);
        std::cout << "Продолжить ввод чисел? (y/n): ";
        std::cin >> choice;
    } while (choice == 'y');
    std::cout << "Исходный список:" << std::endl;
    dll.print_list();
    dll.del15();
    std::cout << "Список после обработки:" << std::endl;
    dll.print_list();
    return 0;
}

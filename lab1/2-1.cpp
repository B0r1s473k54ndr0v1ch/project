#include <iostream>
#include <string>
using namespace std;
class Node {
    friend class Stack;
private:
    string data;
    Node* next;
    // ����������� ����
    Node(string data) : data(data), next(nullptr) {}
};
class Stack {
private:
    Node* top;
    int size;
public:
    // ����������� �����
    Stack() : top(nullptr), size(0) {}
    // ���������� �������� � ����
    void push(string data) {
        Node* new_node = new Node(data);
        new_node->next = top;
        top = new_node;
        size++;
    }
    // �������� �������� �� �����
    string pop() {
        if (top == nullptr) {
            return "";
        }
        string data = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        size--;
        return data;
    }
    // ����� ����������� �����
    void printStack() {
        Node* current = top;
        while (current) {
            cout << current->data << endl;
            current = current->next;
        }
    }
    // ������� ���������� ����� ������������ ����� � �����
    int countStringsWithLength(int length) {
        int count = 0;
        Node* current = top;
        while (current) {
            if (current->data.length() == length) {
                count++;
            }
            current = current->next;
        }
        return count;
    }
};
int main() {
    Stack stack;
    stack.push("abc");
    stack.push("fx");
    stack.push("glc");
    stack.push("hi");
    stack.push("gogo");
    cout << "���������� �����:" << endl;
    stack.printStack();
    stack.pop();
    stack.push("the end");
    stack.printStack();
    int count = stack.countStringsWithLength(2);
    cout << "\n���������� ����� � �����, ��������� �� 2 ��������: " << count << endl;
    return 0;
}

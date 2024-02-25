#include <iostream>
#include <queue>
using namespace std;
int main() {
    queue<char> Q;
    char ch;
    cout << "Введите символы: (0 для завершения)" << endl;
    // Добавление символов в очередь
    while (true) {
        cin >> ch;
        if (ch == '0') {
            break;
        }
        Q.push(ch);
    }
    queue<char> updQ;
    // Удаление элемента после каждого символа '&'
    while (!Q.empty()) {
        char frontChar = Q.front();
        Q.pop();
        updQ.push(frontChar);
        if (frontChar == '&') {
            if (!Q.empty()) {
                Q.pop(); // Удаляем следующий элемент после символа '&'
            }
        }
    }
    cout << "Содержимое очереди после удаления элементов после символов '&' :" << endl;
    while (!updQ.empty()) {
        cout << updQ.front() << " ";
        updQ.pop();
    }
    cout << endl;
    return 0;
}

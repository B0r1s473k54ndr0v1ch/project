#include <iostream>
#include <queue>
using namespace std;
int main() {
    queue<int> Q;
    int num;
    cout << "Введите целые числа: (-1 для завершения):" << endl;
    // Добавление чисел в очередь
    while (true) {
        cin >> num;
        if (num == -1) {
            break;
        }
        Q.push(num);
    }
    queue<int> updQ;
    // Удаление двух элементов после каждого элемента с нечетным значением
    while (!Q.empty()) {
        int frontNum = Q.front();
        Q.pop();
        updQ.push(frontNum);
        if (frontNum % 2 != 0) {
            for (int i = 0; i < 2 && !Q.empty(); i++) {
                Q.pop();
            }
        }
    }
    cout << "Содержимое очереди после удаления двух элементов после каждого нечетного числа:" << endl;
    while (!updQ.empty()) {
        cout << updQ.front() << " ";
        updQ.pop();
    }
    cout << endl;
    return 0;
}

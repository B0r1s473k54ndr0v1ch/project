#include <iostream>
#include <queue>
using namespace std;
int main() {
    queue<double> Q;
    double num;
    cout << "¬ведите вещественные числа: (0 дл€ завершени€):" << endl;
    // ƒобавление чисел в очередь
    while (true) {
        cin >> num;
        if (num == 0) {
            break;
        }
        Q.push(num);
    }
    queue<double> updQ;
    // ¬ставка числа 1.5 после каждого элемента с отрицательным значением
    while (!Q.empty()) {
        double frontNum = Q.front();
        Q.pop();
        updQ.push(frontNum);
        if (frontNum < 0) {
            updQ.push(1.5);
        }
    }
    cout << "—одержимое очереди после вставки числа 1.5 после каждого отрицательного числа:" << endl;
    while (!updQ.empty()) {
        cout << updQ.front() << " ";
        updQ.pop();
    }
    cout << endl;
    return 0;
}

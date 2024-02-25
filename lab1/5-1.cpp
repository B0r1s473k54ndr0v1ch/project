#include <iostream>
#include <queue>
using namespace std;
int main() {
    queue<double> Q;
    double num;
    cout << "������� ������������ �����: (0 ��� ����������):" << endl;
    // ���������� ����� � �������
    while (true) {
        cin >> num;
        if (num == 0) {
            break;
        }
        Q.push(num);
    }
    queue<double> updQ;
    // ������� ����� 1.5 ����� ������� �������� � ������������� ���������
    while (!Q.empty()) {
        double frontNum = Q.front();
        Q.pop();
        updQ.push(frontNum);
        if (frontNum < 0) {
            updQ.push(1.5);
        }
    }
    cout << "���������� ������� ����� ������� ����� 1.5 ����� ������� �������������� �����:" << endl;
    while (!updQ.empty()) {
        cout << updQ.front() << " ";
        updQ.pop();
    }
    cout << endl;
    return 0;
}

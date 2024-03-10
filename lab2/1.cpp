#include <iostream>
#include <fstream>
using namespace std;
int main() {
    ifstream file("a.txt");
    if (!file.is_open()) {
        cerr << "Opening error" << endl;
        return 1;
    }
    double num;
    int nol = 0;
    double minus = 0;
    while (file >> num) {
        if (num == 0) {
            nol++;
        } else if (num < 0) {
            minus += num;
        }
    }
    file.close();
    cout << "Zeros: " << nol << endl;
    cout << "Minuses: " << minus << endl;
    return 0;
}

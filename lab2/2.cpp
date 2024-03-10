#include <iostream>
#include <fstream>
using namespace std;
int nolCount(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Opening error" << filename << endl;
        return -1;
    }
    double num;
    int nol = 0;
    while (file >> num) {
        if (num == 0) {
            nol++;
        }
    }
    file.close();
    return nol;
}
int main() {
    int nol1 = nolCount("a1.txt");
    int nol2 = nolCount("a2.txt");
    if (nol1 == -1 || nol2 == -1) {
        return 1;
    }
    cout << "Zeros in a1.txt: " << nol1 << endl;
    cout << "Zeros in a2.txt: " << nol2 << endl;
    return 0;
}

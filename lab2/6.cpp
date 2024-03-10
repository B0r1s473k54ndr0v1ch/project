#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
int main() {
  ifstream file_f("f.txt");
  if (!file_f.is_open()) {
    cout << "Opening error (f.txt)" << endl;
    return 1;
  }
  ofstream file_g("g.txt");
  if (!file_g.is_open()) {
    cout << "Opening error (g.txt)" << endl;
    return 1;
  }
  int num;
  while (file_f >> num) {
    int sqrt_num = sqrt(num);
    if (sqrt_num * sqrt_num == num) {
      file_g << num << " ";
    }
  }
  file_f.close();
  file_g.close();
  cout << "Operation successful" << endl;
  return 0;
}

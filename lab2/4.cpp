#include <iostream>
#include <fstream>
using namespace std;
int main() {
  ifstream file("file4.txt");
  if (!file.is_open()) {
    cout << "Opening error" << endl;
    return 1;
  }
  int max_element = INT_MIN;
  int num;
  int count = 0;

  while (file >> num) {
    if (count % 3 == 0) {
      max_element = max(max_element, num);
    }
    count++;
  }
  file.close();
  if (max_element == INT_MIN) {
    cout << " No multiples of three" << endl;
  } else {
    cout << "Max: " << max_element << endl;
  }
  return 0;
}

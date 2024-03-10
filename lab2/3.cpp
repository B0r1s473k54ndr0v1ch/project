#include <iostream>
#include <fstream>
using namespace std;
int main() {
  // Запросить старый и новый символы у пользователя
  char old_char, new_char;
  cout << "Input old: ";
  cin >> old_char;
  cout << "Input new: ";
  cin >> new_char;
  // Открыть исходный текстовый файл
  ifstream input_file("file3.txt");
  if (!input_file.is_open()) {
    cerr << "Opening error" << endl;
    return 1;
  }
  // Создать новый файл для обработанного текста
  ofstream output_file("file3_1.txt");
  if (!output_file.is_open()) {
    cerr << "Creating error" << endl;
    input_file.close();
    return 1;
  }
  // Считывать символы из исходного файла и заменять старый символ на новый
  char c;
  while (input_file.get(c)) {
    if (c == old_char) {
      c = new_char;
    }
    output_file << c;
  }
  // Закрыть файлы
  input_file.close();
  output_file.close();
  cout << "Operation successful" << endl;
  return 0;
}

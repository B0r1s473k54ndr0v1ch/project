#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
int main() {
  // Ввод символов в Memo или StringGrid
  vector<char> symbols;
  cout << "Input:" << endl;
  char symbol;
  while (cin >> symbol) {
    symbols.push_back(symbol);
  }
  // Запись символов в бинарный файл file9.txt
  ofstream file("file9.txt", ios::binary);
  for (char s : symbols) {
    file.write((char *)&s, sizeof(s));
  }
  file.close();
  // Вывод символов до изменения данных в файле
  cout << "Before processing:" << endl;
  for (char s : symbols) {
    cout << s << " ";
  }
  cout << endl;
  // Перезапись бинарного файла с заглавными буквами
  ifstream inFile("file9.txt", ios::binary);
  ofstream outFile("file9_upper.txt", ios::binary);
  while (inFile.read((char *)&symbol, sizeof(symbol))) {
    symbol = toupper(symbol);
    outFile.write((char *)&symbol, sizeof(symbol));
  }
  inFile.close();
  outFile.close();
  // Вывод символов после изменения данных в файле
  cout << "After processing:" << endl;
  ifstream inFile2("file9_upper.txt", ios::binary);
  while (inFile2.read((char *)&symbol, sizeof(symbol))) {
    cout << symbol << " ";
  }
  inFile2.close();
  cout << endl;

  return 0;
}

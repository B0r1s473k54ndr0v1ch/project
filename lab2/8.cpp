#include <iostream>
#include <fstream>
#include <string>
using namespace std;
struct Item {
    string name;
    double price;
    string unit;
};
int main() {
    // Создать бинарный файл
    ofstream outFile("file8.bin", ios::binary);
    // Получить данные о товарах от пользователя
    int numItems;
    cout << "Введите количество товаров: ";
    cin >> numItems;
    Item items[numItems];
    for (int i = 0; i < numItems; i++) {
        cout << "Введите название товара " << i + 1 << ": ";
        cin >> items[i].name;
        cout << "Введите стоимость товара " << i + 1 << ": ";
        cin >> items[i].price;
        cout << "Введите единицу измерения товара " << i + 1 << ": ";
        cin >> items[i].unit;
    }
    // Записать данные о товарах в файл
    outFile.write((char *)items, sizeof(items));
    outFile.close();
    // Определить самый дорогой товар
    ifstream inFile("file8.bin", ios::binary);
    Item mostExpensiveItem;
    double maxPrice = 0;
    while (inFile.read((char *)&items, sizeof(items))) {
        for (int i = 0; i < numItems; i++) {
            if (items[i].price > maxPrice) {
                maxPrice = items[i].price;
                mostExpensiveItem = items[i];
            }
        }
    }
    inFile.close();
    // Вывести сведения о самом дорогом товаре
    cout << "Most expensive:" << endl;
    cout << "Name: " << mostExpensiveItem.name << endl;
    cout << "Price: " << mostExpensiveItem.price << endl;
    cout << "Unit: " << mostExpensiveItem.unit << endl;
    return 0;
}

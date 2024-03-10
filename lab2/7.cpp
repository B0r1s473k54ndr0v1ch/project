#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
// Функция для умножения матриц
vector<vector<int>> matrixMultiplication(const vector<vector<int>>& matrix1, const vector<vector<int>>& matrix2) {
    int m = matrix1.size();
    int n = matrix2[0].size();
    int p = matrix2.size();
    vector<vector<int>> result(m, vector<int>(n, 0));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < p; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
    return result;
}

int main() {
    with open('file7.txt', 'r') as file:
        k = int(file.readline())
        m = int(file.readline())
        n = int(file.readline())
    ofstream outFile("output.txt");
    for (int i = 0; i < k; i++) {
        // Создание и заполнение матриц
        vector<vector<int>> matrix1(m, vector<int>(n, i+1));
        vector<vector<int>> matrix2(m, vector<int>(n, i+2));
        // Вычисление произведения матриц
        vector<std::vector<int>> result = matrixMultiplication(matrix1, matrix2);
        // Запись результата в файл
        for (const auto& row : result) {
            for (int element : row) {
                outFile << element << " ";
            }
            outFile << "\n";
        }
    }
    outFile.close();
    // Вывод содержимого первого файла
    ifstream inFile1("output.txt");
    string line;
    cout << "Output1:" << std::endl;
    while (getline(inFile1, line)) {
        cout << line << endl;
    }
    inFile1.close();
    // Вывод содержимого второго файла
    ifstream inFile2("output.txt");
    cout << "Output2:" << endl;
    while (getline(inFile2, line)) {
        cout << line << endl;
    }
    inFile2.close();
    return 0;
}

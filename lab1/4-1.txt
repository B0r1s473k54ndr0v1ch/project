#include <iostream>
#include <queue>
using namespace std;
int main()
{
    queue <int> nums;
    int n, c, ten;
    ten = 10;
    c = 0;
    cout << "¬ведите размер списка N: " ;
    cin >> n;
    cout << "¬ведите элементы списка: " ;
    for (int i = 0; i < n; i++){
        int k;
        cin >> k;
        nums.push(k);
        if (k < 0){
            c += 1;
        }
        if (k < 0 & c == 1){
            nums.push(ten);
        }
    }
    cout << "Ёлементы списка после обработки: " ;
    for (int i = 0; i <= n; i++){
        cout << nums.front() << " ";
        if (nums.size() != 0){
            nums.pop();
        }
    }
    return 0;
}

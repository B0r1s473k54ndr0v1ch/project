#include <iostream>
#include <deque>
using namespace std;
int main()
{
    deque <float> nums;
    int n;
    int c = 0;
    cout << "Введите размер очереди N: " ;
    cin >> n;
    for (int i = 0; i < n; i++){
        float k;
        cout << "N[" << i << "] = " ;
        cin >> k ;
        if (k < 0){
            c += 1;
        }
        nums.push_back(k);
    }
    cout << "Количество отрицательных элементов очереди: " << c  << endl;
    cout << "N = [ " ;
    for (int i = 0; i < n; i++){
        cout << nums[i] << " ";
    }
    cout << "]" ;
    return 0;
}

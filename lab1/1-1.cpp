#include <iostream>
#include <stack>
using namespace std;
int main()
{
    stack <int> nums;
    int n;
    cout << "������� ������ ����� N: " ;
    cin >> n;
    for (int i = 0; i < n; i++){
        int k;
        cout << "N[" << i << "] = " ;
        cin >> k ;
        nums.push(k);
    }
    cout << "������� �����: " << nums.top() ;
    return 0;
}

#include <iostream>
using namespace std;
class Goods
{
public:
    int price;
    int number;
    void print()
    {
        cout << "Total cost: " << price * number;
    }
};
int main()
{
    Goods item;
    item.price;
    item.number;
    cout << "Price: ";
    cin >> item.price;
    cout << "Quantity: ";
    cin >> item.number;
    item.print();
}
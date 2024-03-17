#include <iostream>
using namespace std;
class Date
{
public:
    int day;
    int month;
    int year;
    void coincidence()
    {
        if (day == month) {
            cout << "Day and month ARE the same number." << endl;
        } else {
            cout << "Day and mont ARE NOT the same number." << endl;
        }
    }
    void print()
    {
        if ((day <= 31) and (month <= 12))
        {
            cout << "Your processed date: " << day << "." << month + 1 << "." << year;
        }
        else
        {
            cout << "Wrong date";
        }
    }
};
int main()
{
    Date date;
    date.day;
    date.month;
    date.year;
    cout << "Your day: ";
    cin >> date.day;
    cout << "Your month: ";
    cin >> date.month;
    cout << "Your year: ";
    cin >> date.year;
    date.coincidence();
    date.print();
}
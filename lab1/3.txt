#include <iostream>
#include <stack>
#include <string>
using namespace std;
string s;
int n;
int main() {
    int cnt = 0;
    cin >> s;
    n = (int)s.size();
    stack <char> st;
    for (int i = 0; i < n; i++) {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
            st.push(s[i]);
        } else {
            if (st.size() == 0) {
                cout << "Неверная последовательность";
                return 0;
            }
            if (s[i] == ')' && st.top() == '(') {
                st.pop();
            } else if (s[i] == '}' && st.top() == '{') {
                st.pop();
            } else if (s[i] == ']' && st.top() == '[') {
                st.pop();
            } else {
                cout << "Неверная последовательность";
                return 0;
            }
        }
    }
    if ((int)st.size() == 0) {
        cout << "Верная последовательность";
    } else {
        cout << "Неверная последовательность";
    }
    return 0;
}

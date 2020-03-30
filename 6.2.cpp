#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;
stack<char> st;
int main() {
    string str;
    cin >> str;
    for(int i = 0; i < str.size(); i++) {
        if(st.empty() && (str[i] == ')' || str[i] == ']')) {
            cout << "No";
            return 0;
        }
        if(str[i] == '(' || str[i] == '[') {
            st.push(str[i]);
        }
        else {
            if(str[i] == ']') {
                if(st.top() == '[') {
                    st.pop();
                }
                else {
                    cout << "No";
                    return 0;
                }
            }
            if(str[i] == ')') {
                if(st.top() == '(') {
                    st.pop();
                }
                else {
                    cout << "No";
                    return 0;
                }
            }
        }
    }
    cout << "Yes";
}

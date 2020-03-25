#include <iostream>
#include <stack>
using namespace std;
int judge(char x) {
    switch (x) {
        case '+': return 1;
        case '-': return 1;
        case '*': return 2;
        case '/': return 2;
        case '^': return 3;
    }
}
int main() {
    stack<char> st;
    string a;
    cin >> a;
    for(int i = 0; i < a.size(); i++) {
        if(a[i] >= '0' && a[i] <= '9') {
            cout << a[i];
        }
        else {
            if(a[i] == ')') {
                while(st.top() != '(') {
                    cout << st.top();
                    st.pop();
                }
                st.pop();
            }
            else if(a[i] == '(') {
                st.push(a[i]);
            }
            else {
                while(!st.empty() && judge(st.top()) >= judge(a[i]) && st.top()!='(') {
                    cout << st.top();
                    st.pop();
                }
                st.push(a[i]);
            }
        }
    }
    while(!st.empty()) {
        cout << st.top();
        st.pop();
    }
}

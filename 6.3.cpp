#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;
stack<char> st;
int main() {
    int n,count = 0;
    cin >> n;
    string str;
    cin >> str;
    for(int i = 0; i < n; i++) {
        if(!st.empty() && str[i] == ')' && st.top() == '(') {
            st.pop();
        }
        else if(!st.empty() && str[i] == '(' && st.top() == ')') {
            count += 2;
            st.pop();
        }
        else {
            st.push(str[i]);
        }
    }
    if(st.empty()) {
    	cout << count;
	}
	else {
		cout << "-1";
	}
}


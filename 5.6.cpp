#include <iostream>
#include <stack>
#include <cmath>
using namespace std;
long long int StringToNum(string x) {
    long long int ans = 0;
    long long int temp = 1;
    if(x[0] == '-') {
        for(int i = x.size() - 1; i >= 1; i--) {
            ans += temp*(x[i]-'0');
            temp *= 10;
        }
        return (-1)*ans;
    }
    else {
        for(int i = x.size() - 1; i >= 0; i--) {
            ans += temp * (x[i] - '0');
            temp *= 10;
        }
        return ans;
    }
}
int main() {
    stack<long long int> st;
    int n;
    cin >> n;
    string a;
    cin >> a;
    a = a + ',';
    for(int i = 0; i <= a.size(); i++) {
        if(a[i] == ',') {
            continue;
        }
        if((a[i] == '-' && a[i + 1] >= '0' && a[i + 1] <= '9') || (a[i] >= '0' && a[i] <= '9')) {
            int j=0;
            while(a[i + j] != ',') {
                j++;
            }
            string temp(a, i, j);
            i = i + j - 1;
            st.push(StringToNum(temp));
        }
        else {
            if(a[i] == '+') {
                long long int sign = st.top();
                st.pop();
                sign += st.top();
                st.pop();
                st.push(sign);
            }
            if(a[i] == '-') {
                long long int sign = st.top();
                st.pop();
                sign = st.top() - sign;
                st.pop();
                st.push(sign);
            }
            if(a[i] == '*') {
                long long int sign = st.top();
                st.pop();
                sign *= st.top();
                st.pop();
                st.push(sign);
            }
            if(a[i] == '/') {
                long long int sign = st.top();
                st.pop();
                sign = st.top() / sign;
                st.pop();
                st.push(sign);
            }
            if(a[i] == '^') {
                long long int sign = st.top();
                st.pop();
                sign = pow(st.top(), sign);
                st.pop();
                st.push(sign);
            }
        }
    }
    cout << st.top();
}

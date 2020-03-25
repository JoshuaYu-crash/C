#include <iostream>
using namespace std;
int a[100005] = {0};
int main() {
    int n,top = 0;
    cin >> n;
    for(int i = 0; i < n; i++) {
        if(top == 0) {
            cin >> a[top];
            top++;
        }
        else {
            int temp;
            cin >> temp;
            while(a[top] < temp) {
                if(top == 0) {
                    top--;
                    break;
                }
                a[top] = 0;
                top--;
            }
            top++;
            a[top++] = temp;
        }
    }
    for(int i = 0; i < top; i++) {
        cout << a[i] << endl;
    }
}

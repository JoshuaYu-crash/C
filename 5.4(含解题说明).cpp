#include <iostream>
using namespace std;
int a[1000005];
int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < n; i++) {
        int temp = 0;
        for(int j = i + 1; j < n; j++) {
            if(a[j] > a[i]) {
                temp = j + 1;
                break;
            }
        }
        a[i] = temp;
    }
    for(int i = 0; i < n; i++) {
        cout << a[i] << ' ';
    }
}

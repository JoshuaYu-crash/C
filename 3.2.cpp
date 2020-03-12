#include <iostream>
using namespace std;
int a[10005];
int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < n; i++) {
        int sum = 0;
        while(a[i] > 9) {
            sum += a[i] - (a[i] % 10);
            a[i] = (a[i] % 10) + (a[i] / 10);
        }
        sum += a[i];
        a[i] = sum;
    }
    for(int i = 0; i < n; i++) {
        cout << a[i] << endl;
    }
}

#include <iostream>
#include<algorithm>
using namespace std;
int a[130], b[10005], ans[1000];
int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    cout << a[n - 1] << ' ';
    if(a[n - 1] == a[n - 2]) {
        cout << a[n - 2];
        return 0;
    }
    for(int i = n - 2; i >= 0; i--) {
        if(a[n - 1] % a[i] == 0) {
            if(a[i] == a[i - 1]) {
                cout << a[i];
                return 0;
            }
        }
        else {
            cout << a[i];
            return 0;
        }
    }
}


#include <iostream>
#include <algorithm>
using namespace std;
int a[300005];
int main() {
	int n, sign = 1;
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for(int i = 1; i <= (n - 1) / 2; i++) {
        if(n % 2 == 0 && i == (n - 1) / 2) {
            if((a[i] < i && a[n - i - 1] < i + 1) || (a[i] < i + 1 && a[n - i - 1] < i)) {
                cout << "No";
                return 0;
                sign = 0;
            }
        }
        if(a[i] < i || a[n - i - 1] < i) {
            cout << "No";
            return 0;
            sign = 0;
        }
    }
    if(sign) {
        cout << "Yes";
    }
}

#include <iostream>
using namespace std;
int a[300005];
int main() {
	int n, sign = 0;
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> a[n];
	}
	for(int i = 1; i <= n; i++) {
		if(a[i] < i && a[i] <= n - i) {
			cout << "No";
			return 0;
		}
	}
	cout << "Yes";
}

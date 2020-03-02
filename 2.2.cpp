#include <iostream>
#include <algorithm>
using namespace std;
int a[1005];
int main() {
	int n, max, sign = 0;
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);
	max = 1;
	for(int i = 1; i < n; i++) {
		if(a[i] - a[i-1] == 1) {
			sign = 1;
		}
	}
	if(sign) {
		cout << '2';
	}
	else {
		cout << '1';
	}
}

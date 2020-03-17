#include <iostream>
using namespace std;
int main() {
	int count = 0, n, m;
	cin >> n >> m;
	int a[n];
	for(int i = 0; i < n; i++) {
		a[i] = i + 1;
	}
	int temp = 0, i = 0;
	while(1) {
		if(i == n){
			i = 0;
		}
		if(a[i] == 0) {
			i++;
			continue;
		}
		temp++;
		if(temp == m) {
			temp = 0;
			count++;
			if(count == n) {
				cout << a[i] << endl;
				return 0;
			}
			else {
				a[i] = 0;
			}
		}
		i++;
	}
}

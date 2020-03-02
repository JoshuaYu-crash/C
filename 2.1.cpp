#include <iostream>
#include <algorithm>
using namespace std;
int a[50005][2];
int main() {
	int n, count = 0;
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> a[i][0] >> a[i][1];
	}
	for(int i = 0; i < n - 1; i++) {
		for(int j = i + 1; j < n; j++) {
			if(a[i][0] == a[j][0]) {
				count++;
			}
			else if (a[i][1] == a[j][1]){
				count++;
			}
		}
	}
	cout << count;
}

#include <iostream>
#include <algorithm>
using namespace std;
int a[3][6], check[1001];
int main() {
	int n;
	cin >> n;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < 6; j++) {
			cin >> a[i][j];
		}
	}
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < 6; j++) {
			check[a[i][j]]++;
		}	
	}
	if(n>1) {
		for(int i = 0; i < 6; i++) {
			for(int j = 0; j < 6; j++) {
				check[a[0][i] * 10 + a[1][j]]++;
				check[a[1][i] * 10 + a[0][j]]++;
				check[a[0][i] * 10 + a[2][j]]++;
				check[a[2][i] * 10 + a[0][j]]++;
				check[a[1][i] * 10 + a[2][j]]++;
				check[a[2][i] * 10 + a[1][j]]++;
			}
		}
	}
	if(n>2) {
		for(int i = 0; i < 6; i++) {
			for(int j = 0; j < 6; j++) {
				for(int k = 0; k < 6; k++) {
					check[a[0][i] * 100 + a[1][j] * 10 + a[2][k]]++;
					check[a[0][i] * 100 + a[2][j] * 10 + a[1][k]]++;
					check[a[1][i] * 100 + a[0][j] * 10 + a[2][k]]++;
					check[a[1][i] * 100 + a[2][j] * 10 + a[0][k]]++;
					check[a[2][i] * 100 + a[0][j] * 10 + a[1][k]]++;
					check[a[2][i] * 100 + a[1][j] * 10 + a[0][k]]++;
				}
			}
		}
	}
	int i;
	for(i = 1; check[i] != 0; i++) {
		;
	}
	cout << i-1;
}

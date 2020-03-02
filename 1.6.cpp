#include <iostream>
#include <algorithm>
using namespace std;
int gcd(int a, int b) {
	return b==0 ? a : gcd(b, a % b);
}
struct S{
	int fz;
	int fm;
	double num;
}s[100000];
int cmp(S a,S b) {
	return a.num<b.num;
}
int main() {
	int n, k = 0;
	cin >> n;
	for(int i = 1; i <= n; i++) {
		for(int j = i + 1; j <= n; j++) {
			if(gcd(i, j) == 1) {
				s[k].fm = j;
				s[k].fz = i;
				s[k++].num = (i * 1.0) / (j * 1.0);
			}
		}
	}
	sort(s, s + k, cmp);
	cout << "0/1" << endl;
	for(int i = 0; i < k; i++) {
		cout << s[i].fz << "/" << s[i].fm << endl;
	}
	cout << "1/1";
}

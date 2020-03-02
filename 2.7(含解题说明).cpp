#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int A[1000005],C[1000005],sum[1000005];
int main() {
	long long int n, aver = 0, ans = 0, Cmid;
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> A[i];
		sum[i] = sum[i-1] + A[i];
		aver += A[i];
	}
	aver /= n;
	for(int i = 1; i <= n - 1; i++) {
		C[i] = sum[i] - i * aver;
	}
	C[n] = 0;
	sort(C + 1, C + n + 1);
	Cmid = C[n / 2];
	for(int i = 1; i <= n; i++) {
		ans += abs(Cmid - C[i]);
	}
	cout << ans;
}

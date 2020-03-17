#include<iostream>
#include<algorithm>
using namespace std;
long long gcd(long long a, long long b) {
	return b == 0 ? a : gcd(b, a % b);
}
long long eular(long long n) { 
	long long res = n, a = n;
	for (long long i = 2; i * i <= a; i++) {
		if (a % i == 0) {
			res = res / i * (i - 1);
			while (a % i == 0) {
                a /= i;
            }
		}
	}
	if (a > 1) {
        res = res / a * (a - 1);
    }
	return res;
}
int main() {
    int n;
    cin >> n;
    for(int i=0;i<n;i++) {
        long long int a, m, count = 0, temp;
        cin >> a >> m;
        temp=gcd(a, m);
        cout << eular(m / temp) << endl;
    }
}

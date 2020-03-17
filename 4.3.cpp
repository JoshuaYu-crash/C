#include<iostream>
#include<algorithm>
using namespace std;
int a[100005], b[100005];
int main() {
    int n, k;
    cin >> n >> k;
    k--;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    int sum = a[n - 1] + 1 - a[0];
    for(int i = 1; i < n; i++) {
        b[i - 1] = a[i] - (a[i - 1] + 1);
    }
    sort(b, b + n - 1);
    int sign = n - 2;
    while(k--) {
        sum -= b[sign--];
    }
    cout << sum;
}

#include <iostream>
#include <algorithm>
using namespace std;
int s[100000];
int x[100000];
int main() {
    int n, a, b, k, count=0;
    cin >> n >> a >> b >> k;
    for(int i = 0; i < n; i++) {
        cin >> s[i];
    }
    for(int i = 0; i < n; i++) {
        if(s[i] % (a + b) == 0) {
            if((a + b) % a == 0) {
                x[i] = (a + b) / a - 1;
            }
            else {
                x[i] = (a + b) / a;
            }
        }
        else {
            if((s[i] % (a + b)) % a == 0) {
                x[i] = (s[i] % (a + b)) / a - 1;
            }
            else {
                x[i] = (s[i] % (a + b)) / a;
            }
        }
    }
    sort(x, x + n);
    for(int i = 0; i < n; i++) {
        if(k - x[i] >= 0) {
            k -= x[i];
            count++;
        }
    }
    cout << count;
}

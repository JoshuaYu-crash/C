#include <iostream>
using namespace std;
int a[1000];
int main() {
    int n, m, ans;
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    while(1) {
        int change = 0;
        for(int i = 0; i < n; i++) {
            if(a[i] > 0) {
                a[i] -= m;
                change = 1;
                ans = i + 1;
            }
        }
        if(change == 0) {
            break;
        } 
    }
    cout << ans;
}

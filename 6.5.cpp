#include <iostream>
using namespace std;
int scr[1005][1005];
int temp[5] = {0};
int main() {
    int n, m, sign = 0, t = 0;
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        int sum = 0;
        for(int j = 0; j < m; j++) {
            cin >> scr[i][j];
            sum += scr[i][j];
        }
        if(sum != 0 && sum != t) {
            temp[sign++] = sum;
            t = sum;
        }
    }
    if(temp[1] == 0) {
        cout << '1';
    }
    else if(temp[1] == temp[3]) {
        cout << '8';
    }
    else {
        cout << '6';
    }
}

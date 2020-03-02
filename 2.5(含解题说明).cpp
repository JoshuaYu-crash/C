#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
char a[505],b[505];
int Calculate(char* a, char* b, int k) {
    int pos = 0;
    while((a[pos] != 0) && (b[pos] != 0) && k != 0) {
        if(a[pos] == b[pos]) {
            pos++;
        }
        else {
            k--;
            pos++;
        }
    }
    return pos;
}
int main() {
    int k, alen, blen, temp, ans=0;
    cin >> k;
    cin >> a >> b;
    alen = strlen(a);
    blen = strlen(b);
    for(int i = 0; i < alen; i++) {
        for(int j = 0; j < blen; j++) {
            temp = Calculate(a + i, b + j, k);
            if(temp > ans) {
                ans = temp;
            }
        }
    }
    cout << ans;
}


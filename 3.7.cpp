#include <iostream>
#include <cstring>
using namespace std;
const int N=10000;
int sub(int a[], int b[], int lena, int lenb) {
    if(lena < lenb) {
        return -1;
    }
    if(lena == lenb) {
        for(int i = lena - 1; i >= 0; i--) {
            if(a[i] > b[i]) {
                break;
            }
            else if(a[i] < b[i]){
                return -1;
            }
        }
    }
    for(int i = 0; i < lena; i++) {
        a[i] -= b[i];
        if(a[i] < 0) {
            a[i] += 10;
            a[i + 1]--;
        }
    }
    for(int i = lena - 1; i >= 0; i--) {
        if(a[i]) {
            return i + 1;
        }
    }
    return 0;
}
string div(string a, string b) {
    string ans;
    int an[N] = {0}, bn[N] = {0}, ansn[N] = {0}, lena = a.size(), lenb = b.size(), i;
    for(i = lena - 1; i >= 0; i--) {
        an[lena - 1 - i] = a[i] - '0';
    }
    for(i = lenb - 1; i >= 0; i--) {
        bn[lenb - 1 - i] = b[i] - '0';
    }
    if(lena < lenb || (lena == lenb && a < b)) {
        return "0";
    }
    int t = lena - lenb;
    for(int i = lena - 1; i >= 0; i--) {
        if(i >= t) {
            bn[i] = bn[i - t];
        }
        else {
            bn[i] = 0;
        }
    }    
    lenb = lena;
    for(int j = 0; j <= t; j++) {
        int temp;
        while((temp = sub(an, bn + j, lena, lenb - j)) >= 0) {
            lena = temp;
            ansn[t - j]++;
        }
    }
    for(i = 0; i < N - 10; i++) {
        ansn[i+1] += ansn[i] / 10;
        ansn[i] %= 10;
    }
    while(!ansn[i]) {
        i--;
    }
    while(i >= 0) {
        ans += ansn[i--] + '0';
    }
    return ans;
}
int main() {
    string a,b;
    cin >> a >> b;
    cout << div(a, b) << endl;
}

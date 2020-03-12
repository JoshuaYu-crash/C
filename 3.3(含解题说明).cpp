#include<iostream>
#include<algorithm>
using namespace std;
struct S{
    int before;
    int after;
    int m;
} s[200005];
bool cmp(S a, S b) {
    return a.m > b.m;
}
int main() {
    int n, k, sum = 0;
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        cin >> s[i].before;
    }
    for(int i = 0; i < n; i++) {
        cin >> s[i].after;
        s[i].m = s[i].after - s[i].before;
    }
    sort(s, s+n, cmp);
    for(int i = 0; i < k; i++) {
        sum += s[i].before;
    }
    for(int i = k; i < n; i++) {
        if(s[i].m > 0) {
            sum += s[i].before;
        }
        else {
            sum += s[i].after;
        }
    }
    cout << sum;
}

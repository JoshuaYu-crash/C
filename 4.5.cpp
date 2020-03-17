#include <iostream>
using namespace std;
int a[1000005],zl[2005] = {0};
int main() {
    int n,m;
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int tempnum = 0, left = 0, right = 0;
    while(tempnum != m) {
        if(zl[a[right]] == 0) {
            tempnum++;
        }
        zl[a[right]]++;
        right++;
    }
    while(zl[a[left]] > 1) {
        zl[a[left]]--;
        left++;
    }
    int signleft = left, signright = right;
    while(right < n) {
        zl[a[right]]++;
        right++;
        while(zl[a[left]] > 1) {
            zl[a[left++]]--; 
        }
        if(signright - signleft > right - left) {
            signleft = left;
            signright = right;
        }
    }
    cout << signleft + 1 << ' ' << signright;
}

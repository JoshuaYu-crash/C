#include <iostream>
#include <string>
using namespace std;
int a[1005] = {0};
int ans[1005];
int main() {
    int n, an = 0;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < n; i++) {
        if(i == -1) {
            continue;
        }
        if(i % 2 == 0) {
            ans[an++] = a[i];
            a[i] = -1;
        }
        else {
            a[n++] = a[i];
            a[i] = -1;
        }
    }
    for(int i = 0; i < an; i++) {
        cout << ans[i] << ' ';
    }
}
/*
#include <iostream>
#include <queue>
using namespace std;
queue<int> que;
queue<int> ans;
int main() {
    
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        que.push(temp);
    }
    int sign = 1;
    while(!que.empty()) {
        if(sign == 1) {
            sign = 0;
            ans.push(que.front());
            que.pop();
        }
        else {
            sign = 1;
            que.push(que.front());
            que.pop();
        }
    }
    while(!ans.empty()) {
        cout << ans.front() << ' ';
        ans.pop();
    }
}
*/


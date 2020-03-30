#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;
queue<int> q;
int k[205];
int sign[205]={0};
int n,a,b,ans=205;
void dfs(int floor, int count) {
    if(sign[floor]) {
        return ;
    }
    else {
        sign[floor] = 1;
    }
    if(floor == b && ans > count) {
        ans = count;
    }
    if(floor + k[floor] <= n) {
        dfs(floor + k[floor], count + 1);
    }
    if(floor - k[floor] >= 0) {
        dfs(floor - k[floor], count + 1);
    }
}
int main() {
    cin >> n >> a >> b;
    for(int i = 1; i <= n; i++) {
        cin >> k[i];
    }
    dfs(a, 0);
    if(ans != 205) {
        cout << ans;
    }
    else {
        cout << "-1";
    }
}

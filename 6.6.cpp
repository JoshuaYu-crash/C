#include <iostream>
#include <algorithm>
#include <stack>
#include <cstring>
using namespace std;
int n,m,a,b;
long long int x;
int map[1005][1005];
int sign[1005][1005];
int ans=0;
void dfs(int nown,int nowm,long long int count) {
    if(count > x || nown > n || nowm > m || nown < 0 || nowm < 0 || map[nown][nowm] == -1) {
        return;
    }
    if(sign[nown][nowm] == 0) {
        sign[nown][nowm] = 1;
    }
    else {
        return;
    }
    if(map[nown][nowm] > ans) {
        ans = map[nown][nowm];
    }
    dfs(nown + 1, nowm, count + 1);
    dfs(nown, nowm + 1, count + 1);
    dfs(nown - 1, nowm, count + 1);
    dfs(nown, nowm - 1, count + 1);
}
int main() {
    cin >> n >> m >> a >> b >> x;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> map[i][j];
        }
    }
    memset(sign, 0, sizeof(sign));
    dfs(a, b, 0);
    cout << ans;
}

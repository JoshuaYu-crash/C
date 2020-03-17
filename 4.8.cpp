#include <iostream>
#include <cstring>
using namespace std;
char temp[1005][1005];
int map[1005][1005], ans[100005];
int n, m;
void Find(int x, int y, int from, int id) {
    if(x < 0 || x >= n || y < 0 || y >= n || temp[x][y] - '0' != from || map[x][y] != -1) {
        return;
    }
    ans[id]++;
    map[x][y] = id;
    Find(x - 1, y, !from, id);
    Find(x + 1, y, !from, id);
    Find(x, y-1, !from, id);
    Find(x, y+1, !from, id);
}
int main() {
    
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> temp[i];
    }
    memset(map, -1, sizeof(map));
    for(int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        if(map[x-1][y-1] == -1) {
            Find(x - 1, y - 1,temp[x - 1][y - 1] - '0', i);
        }
        else {
            ans[i] = ans[map[x - 1][y - 1]];
        }
    }
    for(int i = 0; i < m; i++) {
        cout << ans[i] << endl;
    }
}

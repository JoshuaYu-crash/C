#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;
int n,m;
char map[1005][1005];
int sign[1005][1005];
struct Pos {
    int x;
    int y;
    int count;
}P,W,B;
queue<Pos> q;
void bfs(Pos Target) {
    memset(sign, -1, sizeof(sign));
    sign[Target.x][Target.y] = Target.count;
    q.push(Target);
    while(!q.empty()) {
        Pos temp = q.front();
        q.pop();
        if(map[temp.x + 1][temp.y] != '#' && sign[temp.x + 1][temp.y] == -1 && temp.x + 1 >= 0 && temp.x + 1 < n) {
            Pos t;
            t.x = temp.x+1;
            t.y = temp.y;
            t.count = temp.count+1;
            sign[t.x][t.y] = t.count;
            q.push(t);
        }
        if(map[temp.x - 1][temp.y] != '#' && sign[temp.x - 1][temp.y] == -1 && temp.x - 1 >= 0 && temp.x - 1 < n) {
            Pos t;
            t.x = temp.x - 1;
            t.y = temp.y;
            t.count = temp.count + 1;
            sign[t.x][t.y] = t.count;
            q.push(t);
        }
        if(map[temp.x][temp.y + 1] != '#' && sign[temp.x][temp.y + 1] == -1 && temp.y + 1 >= 0 && temp.y + 1 < m) {
            Pos t;
            t.x = temp.x;
            t.y = temp.y+1;
            t.count = temp.count + 1;
            sign[t.x][t.y] = t.count;
            q.push(t);
        }
        if(map[temp.x][temp.y - 1] != '#' && sign[temp.x][temp.y - 1] == -1 && temp.y - 1 >= 0 && temp.y - 1 < m) {
            Pos t;
            t.x = temp.x;
            t.y = temp.y-1;
            t.count = temp.count + 1;
            sign[t.x][t.y] = t.count;
            q.push(t);
        }
    }
}
int main() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> map[i];
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(map[i][j] == 'P') {
                P.x = i;
                P.y = j;
            }
            if(map[i][j] == 'W') {
                W.x = i;
                W.y = j;
            }
            if(map[i][j] == 'B') {
                B.x = i;
                B.y = j;
                B.count = 0;
            }
        }
    }
    bfs(B);
    if(sign[P.x][P.y] == -1 || sign[W.x][W.y] == -1) {
        cout << -1;
    }
    else {
        cout << max(sign[P.x][P.y], sign[W.x][W.y]);
    }
}

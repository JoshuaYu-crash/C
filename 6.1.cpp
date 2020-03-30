#include <iostream>
#include <algorithm>
using namespace std;
struct Pos{
    int id;
    int now;
    int wide;
}w[205];
bool cmp(Pos a, Pos b) {
    return a.wide < b.wide;
}
int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        w[i].id = i + 1;
        cin >> w[i].wide;
        w[i].now = 0;
    }
    sort(w, w + n, cmp);
    string str;
    cin >> str;
    for(int i = 0; i < 2 * n; i++) {
        int temp = str[i] - '0';
        if(temp == 0) {
            for(int j = 0; j < n; j++) {
                if(w[j].now == 0) {
                    w[j].now++;
                    cout << w[j].id << ' ';
                    break;
                }
            }
        }
        else {
            for(int j = n - 1; j >= 0; j--) {
                if(w[j].now == 1) {
                    w[j].now++;
                    cout << w[j].id << ' ';
                    break;
                }
            }
        }
    }
}

#include <bits/stdc++.h>
using namespace std;
char sixt[20] = "0123456789ABCDEF";
int judge(string a) {
    string b = a;
    reverse(b.begin(),b.end());
    if(a == b) {
        return 1;
    }
    else {
        return 0;
    }
}
string super_add(int k, string b) { //�߾��ȼӷ����̣��ƹ㵽 k ����
    string a = b;
    reverse(a.begin(), a.end());
    int numa[101], numb[101], numc[101];
    int len = a.length(), lenc = 1;
    string ans;
    for (int i = 0; i < len; i++) {
        if (isdigit(a[i])) numa[len - i] = a[i] - '0'; //����ʮ�����Ƶ����У���������ּ�ȥ 0 ����ͬ
        else numa[len - i] = a[i] - 'A' + 10; //����������ּ�ȥ A �ټ��� 10
        if (isdigit(b[i])) numb[len - i] = b[i] - '0';
        else numb[len - i] = b[i] - 'A' + 10;
    }
    int x = 0;
    while (lenc <= len) {
        numc[lenc] = numa[lenc] + numb[lenc] + x;
        x = numc[lenc] / k; //���� k��x�ǽ�λ����
        numc[lenc] %= k; //k ȡģ�����������λ����
        lenc++;
    }
    numc[lenc] = x;
    while (numc[lenc] == 0) lenc--;
    for (int i = lenc; i >= 1; i--) ans += sixt[numc[i]];
    return ans;
}
int main() {
    int n;
    string m;
    cin >> n;
    cin >> m;
    for(int i = 0; i <= 30; i++) {
        if(judge(m)) {
            cout << "STEP=" << i;
            return 0;
        }
        else {
            m=super_add(n, m);
        }
    }
    cout << "NO";
}

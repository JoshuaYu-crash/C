#include <bits/stdc++.h>
using namespace std;
bool compare(string a, string b) {//??a,b???
    int lena = a.length(), lenb = b.length();
    if(lena < lenb) {
        return false;
    }
    else if(lena > lenb) {
        return true;
    }
    else {
        for(int i = 0; i < lena; i++) {
            if(a[i] < b[i]) {
                return false;
            }
            else if(a[i] > b[i]){
                return true;
            }
        }
        return true;
    }
}
string eraser(string a) {
    int check = 0;
    string ans;
    for(int i = 0; i < a.length() - 1; i++) {
        if(a[i] == '0' && check == 0) {
            continue;
        }
        check = 1;
        ans = ans + a[i];
    }
    ans = ans + a[a.length() - 1];
    return ans;
}
string sub(string a, string b)//?????
{
    string ans;
    int check = 0;
    if(!compare(a, b)) {
        swap(a, b);
        check = 1;//??b??a???
    }
    int lena = a.length(), lenb = b.length();
    for(int i = 1; i <= lena - lenb; i++) {
        b = '0' + b;
    }
    int carry = 0, temp;
	for(int i = lena - 1; i >= 0; i--) {
		temp = (a[i] - '0') - (b[i] - '0') - carry;//??
		if(temp < 0) {//?????
			carry = 1;//???
			temp += 10;//?????
		}
        else {
            carry = 0;//???0,????
        }
		ans = char(temp + '0') + ans;//???????
	}
    ans = eraser(ans);
    if(check) {
        return '-' + ans;
    }
    else {
        return ans;
    }
}
int main() {
    string a,b;
    cin >> a >> b;
	cout << sub(a, b);
}

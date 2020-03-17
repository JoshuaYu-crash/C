#include <iostream>
#include <sstream>
using namespace std;
string change(int count) {
    stringstream str;
    str << count;
    return str.str();
}
int main() {
    string str;
    cin >> str;
    while(1) {
        int i = 1, markleft, markright, count, check = 0;
        while(str[i]) {
            if(str[i] == str[i - 1] && str[i] > 'a' && str[i] < 'z') {
                check = 1;
                markright = markleft = i;
                count = 1;
                while(str[markright] == str[markleft]) {
                    count++;
                    markright++;
                }
                string strleft(str, 0, markleft - 1);
                string strright(str, markright);
                string num = change(count);
                str = strright + char(str[markleft] - 32) + num + strleft;
                i += count;
                break;
            }
            i++;
        }
        if(check == 0) {
            cout << str;
            return 0;
        }
    }
}

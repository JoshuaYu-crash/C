#include <iostream>
#include <algorithm>
using namespace std;
struct Player {
	string name;
	int card[5];
	int c1, c2, c3, c4;
}player[100005];
bool cmp1(int a, int b) {
	return a > b;
}
bool cmp2(Player a, Player b) {
	if(a.c1 == b.c1) {
		if(a.c2 == b.c2) {
			if (a.c3 == b.c3) {
				if(a.c4 == b.c4) {
					return a.name < b.name;
				}
				return a.c4 > b.c4;
			}
			return a.c3 > b.c3;
		}
		return a.c2 > b.c2;
	}
	return a.c1 > b.c1;
}
int judge_1(int a[]) { //�ʼ�ͬ��˳
	if(a[0] == 13 && a[1] == 12 && a[2] == 11 && a[3] == 10 && a[4] == 1) { 
		return 1;
	}
	else {
		return 0;
	}
}
int judge_2(int a[]) { //˳��
	for(int i = 1; i < 5; i++) {
		if(a[i-1] - a[i] != 1) {
			return 0;
		}
	}
	return 1;
}
int main() {
	int n;
	cin >> n;
	for(int i = 0 ; i < n; i++) {  //�������ַ�ת�������ִ���card[5]��
		char ca[12];
		int j = 0;
		cin >> player[i].name >> ca;
		int k = 0;
		while(ca[j] != 0) {
			if(ca[j] == 'A') {
				player[i].card[k++] = 1;
			}
			else if(ca[j] == 'J') {
				player[i].card[k++] = 11;
			}
			else if(ca[j] == 'Q') {
				player[i].card[k++] = 12;
			}
			else if(ca[j] == 'K') {
				player[i].card[k++] = 13;
			}
			else if(ca[j] == '1' && ca[j+1] == '0') {
				player[i].card[k++] = 10;
				j++;
			}
			else {
				player[i].card[k++] = ca[j] - '0';
			}
			j++;
		}
		sort(player[i].card, player[i].card+5, cmp1);
	}
	for(int i = 0; i < n; i++) {
		player[i].c1 = 0;
		player[i].c2 = 0;
		player[i].c3 = 0;
		player[i].c4 = 0;    //����
		if(judge_1(player[i].card)) {
			player[i].c1 = 8;
			continue;
		}
		if(judge_2(player[i].card)) {
			player[i].c1 = 7;
			player[i].c2 = player[i].card[0];
			continue;
		}
		int temp[14], t1[5], t2[2], t3[1], t4[1], tt1 = 0,tt2 = 0,tt3 = 0, tt4 = 0;
		for(int j = 1; j < 14; j++) {
			temp[j] = 0;
		}
		for(int j = 0; j < 5; j++) {
			t1[j] = 0;
		}
		t2[0] = 0; t2[1] = 0; t3[0] = 0; t4[0] = 0;  //��߸���һ�£��������ʼ�����������������ֲ���ʼ���Ļ��������治����0���͸�������ط��͹����ĸ���
		for(int j = 0; j < 5; j++) {
			temp[player[i].card[j]]++; //����temp[14]������ͬ���ֳ��ִ���
		}
		for(int k = 1; k < 14; k++) { //�ֱ����ĸ�������³��ִ����ֱ�Ϊ1��2��3��4�ε�����������Щ��Ĭ���Ǵ�С�����
			if(temp[k] >= 4) {
				t4[tt4++] = k;
			}
			else if(temp[k] == 3) {
				t3[tt3++] = k;
			}
			else if(temp[k] == 2) {
				t2[tt2++] = k;
			}
			else if(temp[k] == 1) {
				t1[tt1++] = k;
			}
		}
		if(t4[0] != 0) {    //����
			player[i].c1 = 6;
			player[i].c2 = t4[0];
			if(t1[0] != 0) {
				player[i].c3 = t1[0];
			}
			else {
				player[i].c3 = t4[0];
			}
			continue;
		}
		if(t3[0] != 0 && t2[0] != 0) {   //���ú�
			player[i].c1 = 5;
			player[i].c2 = t3[0];
			player[i].c3 = t2[0];
			continue;
		}
		if(t3[0] != 0) {    //����
			player[i].c1 = 4;
			player[i].c2 = t3[0];
			player[i].c3 = t1[0] + t1[1];
			continue;
		}
		if(t2[0] != 0 && t2[1] != 0) {   //����
			player[i].c1 = 3;
			player[i].c2 = t2[1];
			player[i].c3 = t2[0];
			player[i].c4 = t1[0];
			continue;
		}
		if(t2[0] != 0) {      //����
			player[i].c1 = 2;
			player[i].c2 = t2[0];
			player[i].c3 = t1[0]+t1[1]+t1[2];
			continue;
		}
		player[i].c1 = 1;      //����
		player[i].c2 = t1[0] + t1[1] + t1[2] + t1[3] + t1[4];
	}
	sort(player, player + n, cmp2);  //����
	for(int i = 0; i < n; i++) {
		cout << player[i].name << endl;
	}
}

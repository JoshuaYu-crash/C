#include <cstdio>
int main()
{
	int y1,m1,d1,y2,m2,d2,day=0,a,b,c;
	int judge(int x);
	int daycalculate1(int x, int y); 
	int daycalculate2(int x, int y);
	while(scanf("%d%d%d%d%d%d", &y1, &m1, &d1, &y2, &m2, &d2) != EOF) {
		int sign = 0;
		if(y1 > y2) {
			y1 ^= y2 ^= y1 ^= y2;
			m1 ^= m2 ^= m1 ^= m2;
			d1 ^= d2 ^= d1 ^= d2;
			sign = 1;
		}
		else if(y1 == y2) {
			if(m1 > m2) {
				y1 ^= y2 ^= y1 ^= y2;
				m1 ^= m2 ^= m1 ^= m2;
				d1 ^= d2 ^= d1 ^= d2;
				sign = 1;
			}
			else if(m1 == m2) {
				if(d1 > d2) {
					y1 ^= y2 ^= y1 ^= y2;
					m1 ^= m2 ^= m1 ^= m2;
					d1 ^= d2 ^= d1 ^= d2;
					sign = 1;
				}
			}
		}
		if(y1 == y2) {
			if(judge(y1)) {
				a = daycalculate1(m1, d1);
				b = daycalculate1(m2, d2);
				day = b - a; 
			}
			else {
				a = daycalculate2(m1, d1);
				b = daycalculate2(m2, d2);
				day = b - a;
			}
		}
		else {
			if(judge(y1)) {
				a = daycalculate1(m1, d1);
				c = 366 - a;
			}
			else {
				a = daycalculate2(m1, d1);
				c = 365 - a;
			}
			if(judge(y2)) {
				b = daycalculate1(m2, d2);
			}
			else {
				b = daycalculate2(m2, d2);
			}
			for(int i = y1 + 1; i <= y2 - 1; i++) {
				if(judge(i)) {
					day += 366;
				}
				else {
					day += 365;
				}
			}
			day = day + c + b;
		}
		if(sign) {
			printf("%d\n", day);
		}
		else {
			printf("%d\n", -day);
		}
		day=0;
	}
} 
int judge(int x) {
	if((x % 100 == 0 && x % 400 == 0) || (x % 100 != 0 && x % 4 == 0)) {
		return 1;//ÈòÄê 
	}
	else {
		return 0;//Æ½Äê 
	}
}
int daycalculate1(int x, int y) {
	switch(x) {
		case 1: y = y; break;
		case 2: y = y + 31; break;
		case 3: y = y + 60; break;
		case 4: y = y + 91; break;
		case 5: y = y + 121; break;
		case 6: y = y + 152; break;
		case 7: y = y + 182; break;
		case 8: y = y + 213; break;
		case 9: y = y + 244; break;
		case 10: y = y + 274; break;
		case 11: y = y + 305; break;
		case 12: y = y + 335; break;
	}
	return y;

}
int daycalculate2(int x, int y) {
	switch(x) {
		case 1: y = y; break;
		case 2: y = y + 31; break;
		case 3: y = y + 59; break;
		case 4: y = y + 90; break;
		case 5: y = y + 120; break;
		case 6: y = y + 151; break;
		case 7: y = y + 181; break;
		case 8: y = y + 212; break;
		case 9: y = y + 243; break;
		case 10: y = y + 273; break;
		case 11: y = y + 304; break;
		case 12: y = y + 334; break;
	}
	return y;
}


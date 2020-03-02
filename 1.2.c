#include <stdio.h>
char a[100005][6];
int main() {
	int t, x1, y1, x2, y2, i, count = 0;
	scanf("%d", &t);
	scanf("%d%d", &x1, &y1);
	scanf("%d%d", &x2, &y2);
	for(i = 0; i < t; i++) {
		scanf("%s", a[i]);
	}
	for(i = 0; i < t; i++) {
		if(x1 == x2 && y1 == y2) {
			printf("%d", count);
			return 0;
		}
		if(a[i][0] == 'e' && x2 - x1 > 0) {
			x1 += 1;
			count++;
		}
		if(a[i][0] == 'w' && x2 - x1 < 0) {
			x1 -= 1;
			count++;
		}
		if(a[i][0] == 'n' && y2 - y1 > 0) {
			y1 += 1;
			count++;
		}
		if(a[i][0] == 's' && y2 - y1 < 0) {
			 y1 -= 1;
			 count++;
		}
	}
	printf("-1");
	return 0;
}

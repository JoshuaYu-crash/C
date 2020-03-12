#include <stdio.h> 
int main() {
	int n, ans[101], sign = 0, temp = 0, count = 0;
	char c;
	scanf("%d", &n);
	getchar();
	for(int i = 0; i < n; i++) {
		c = getchar();
		if(c == 'B') {
			temp++;
		}
		else {
			if(temp) {
				ans[sign++] = temp;
				count++;
				temp = 0;
			}
			
		}
	}
	if(temp) {
		ans[sign++] = temp;
		count++;
	}
	printf("%d\n", count);
	for(int i = 0; i < sign; i++) {
		printf("%d ", ans[i]);
	}
}

#include <stdio.h>
int a[1005],b[1005];
int main() {
	int n, m, r, i, max, min, num;
	scanf("%d%d%d", &n, &m, &r);
	for(i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	for(i = 0; i < m; i++) {
		scanf("%d", &b[i]);
	}
	min = a[0];
	for(i = 1; i < n; i++) {
		if(a[i] < min) {
			min = a[i];
		}
	}
	num = r / min;
	r -= min * num;
	max = b[0];
	for(i = 1; i < m; i++) {
		if(b[i] > max) {
			max = b[i];
		}
	}
	r += max * num;
	printf("%d", r);
}

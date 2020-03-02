#include <stdio.h>
#include <math.h>
int main() {
	int n, i, a;
	scanf("%d",&n);
	for(i = n; i >= 0; i--) {
		scanf("%d", &a);
		if(a) {
			if(i != n && a > 0) printf("+");
			if(fabs(a) > 1 || i == 0) printf("%d", a);
			if(a == -1 && i) printf("-");
			if(i > 1) printf("x^%d", i);
			if(i == 1) printf("x");
		}
	}
}

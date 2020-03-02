#include <iostream>
#include <algorithm>
using namespace std;
struct Task
{
	int left;
	int right;
} task[1005], sign;
bool cmp (Task a, Task b) {
	if(a.right == b.right) {
		return a.left > b.left;
	}
	return a.right < b.right;
}
int main() {
	int n, count = 1;
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> task[i].left >> task[i].right;
	}
	sort(task,task+n,cmp);
	sign=task[0];
	for(int i = 1; i < n; i++) {
		if(task[i].left >= sign.right) {
			count++;
			sign = task[i];
		}
	}
	cout << count;
}

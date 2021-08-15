#include <stdio.h>
//segmentation fault
#define N 35
int stack[N], pre[N], in[N], post[N];

void solve(int preL, int inL, int postL, int n) {
	if (n == 0)
		return;
	if (n == 1) {
		post[postL] = pre[preL];
		return;
	}
	int root = pre[preL]; //root
	post[postL + n - 1] = root;
	int i = 0; //left
	while (i++ < n) {
		if (in[inL + i] == root) //find root
			break;
	}
	solve(preL + 1, inL, postL, i);							//left
	solve(preL + i + 1, inL + i + 1, postL + i, n - i - 1); //right
}

int main(int argc, char const* argv[]) {
	int n, idx1 = 0, idx2 = 0; //idx point to null
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		pre[i] = i + 1;
	char op[5];
	do {
		scanf("%s", op);
		if (op[1] == 'u') {
			scanf("%d", &stack[idx1]);
			++idx1;
		}
		else {
			--idx1;
			in[idx2] = stack[idx1]; //idx指的元素已被弹出
			++idx2;
		}
	} while (idx2 != n);
	solve(0, 0, 0, n);
	printf("%d", post[0]);
	for (int i = 1; i < n; ++i)
		printf(" %d", post[i]);
	return 0;
}

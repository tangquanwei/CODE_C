#include <stdio.h>
#define MaxTree 10
#define ElementType char
#define Tree int
#define Null -1
struct Node {
	ElementType Data;
	Tree Left;
	Tree Right;
} T1[MaxTree], T2[MaxTree];

Tree buildTree(struct Node T[]) {
	int n;
	scanf("%d", &n);
	if (n) {
		char cl, cr;
		int cheak[n], i;
		for (i = 0; i < n; ++i) {
			cheak[i] = 0;
		}
		for (i = 0; i < n; ++i) {
			scanf("%c %c %c \n", &T[i].Data, &cl, &cr);
			if (cl != '-') {
				T[i].Left = cl - '0';
				cheak[T[i].Left] = 1;
			}
			else
				cheak[T[i].Left] = Null;
			if (cr != '-') {
				T[i].Right = cr - '0';
				cheak[T[i].Right] = 1;
			}
			else
				cheak[T[i].Left] = Null;
		}
		for (i = 0; i < n; ++i) {
			if (!cheak[i])
				break;
		}
		return i;
	}
}
int isOmorphic(Tree R1, Tree R2) {
	if (R1 == Null && R2 == Null)
		return 1;
	if (R1 == Null && R2 != Null || R1 != Null && R2 == Null)
		return 0;
	if (T1[R1].Data != T2[R2].Data)
		return 0;
	if (T1[R1].Left == Null && T2[R2].Left == Null)
		return isOmorphic(T1[R1].Right, T2[R2].Right);
	if (T1[R1].Left != Null && T2[R2].Left != Null && T1[T1[R1].Left].Data == T2[T2[R2].Left].Data)
		return (isOmorphic(T1[R1].Left, T2[R2].Left) && isOmorphic(T1[R1].Right, T2[R2].Right));
	else
		return (isOmorphic(T1[R1].Left, T2[R2].Right) && isOmorphic(T1[R1].Right, T2[R2].Left));
}

int main(int argc, char const* argv[]) {
	Tree R1, R2;
	R1 = buildTree(T1);
	R2 = buildTree(T2);
	if (isOmorphic(R1, R2))
		printf("YES");
	else
		printf("NO");
	return 0;
}

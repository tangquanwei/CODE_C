#include <stdio.h>
#include <stdlib.h>
struct PolyNode {
	int coef;  // 系数
	int expon; //指数
	struct PolyNode* link;
};
typedef struct PolyNode* Polynomail;
// int Cmp(int a, int b) {
// 	return a > b ? 1 : a == b ? 0
// 							  : -1;
// }
// void Attach(int c, int e, Polynomail* pRear) {
// 	// 要改变结尾指针的值,所以传入二级指针
// 	Polynomail p = (Polynomail)malloc(sizeof(struct PolyNode));
// 	p->coef = c;
// 	p->expon = e;
// 	p->link = NULL;
// 	(*pRear)->link = p; // 尾插
// 	*pRear = p;			//后移
// }
// Polynomail polyAdd(Polynomail p1, Polynomail p2) {
// 	p1 = p1->link;
// 	p2 = p2->link;
// 	Polynomail front, rear, temp;
// 	int sum;
// 	rear = (Polynomail)malloc(sizeof(struct PolyNode)); //创建临时结点做表头
// 	front = rear;
// 	while (p1 && p2) {
// 		switch (Cmp(p1->expon, p2->expon)) {
// 		case 1: //p1的指数大
// 			Attach(p1->coef, p1->expon, &rear);
// 			p1 = p1->link; //后移
// 			break;
// 		case -1: //p2的指数大
// 			Attach(p2->coef, p2->expon, &rear);
// 			p2 = p2->link;
// 			break;
// 		case 0: //二者相等
// 			sum = p1->coef + p2->coef;
// 			if (sum) //和不为零才连接
// 				Attach(sum, p1->expon, &rear);
// 			p1 = p1->link;
// 			p2 = p2->link;
// 			break;
// 		}
// 	}
// 	//处理未处理完的多项式
// 	for (; p1; p1 = p1->link)
// 		Attach(p1->coef, p1->expon, &rear);
// 	for (; p2; p2 = p2->link)
// 		Attach(p2->coef, p2->expon, &rear);
// 	rear->link = NULL;
// 	temp = front;
// 	front = front->link;
// 	free(temp); //free掉最开始的表头
// 	return front;
// }
Polynomail polyAdd(Polynomail L1, Polynomail L2) {
	L1 = L1->link;
	L2 = L2->link;
	Polynomail head = (Polynomail)malloc(sizeof(struct PolyNode));
	head->link = NULL;
	Polynomail p = head;
	while (L1 && L2) {
		Polynomail q = (Polynomail)malloc(sizeof(struct PolyNode));
		q->link = NULL;
		if (L1->expon > L2->expon) {
			q->coef = L1->coef;
			q->expon = L1->expon;
			p = p->link = q;
			L1 = L1->link;
		}
		else if (L1->expon < L2->expon) {
			q->coef = L2->coef;
			q->expon = L2->expon;
			p = p->link = q;
			L2 = L2->link;
		}
		else {
			q->coef = L1->coef + L2->coef;
			q->expon = L1->expon;
			if (q->coef == 0)
				free(q);
			else
				p = p->link = q;
			L1 = L1->link;
			L2 = L2->link;
		}
	}
	Polynomail L = L1 ? L1 : L2;
	while (L) {
		p = p->link = L;
		L = L->link;
	}
	return head;
}
Polynomail polyMult(Polynomail L1, Polynomail L2) {
	L1 = L1->link;
	L2 = L2->link;
	Polynomail head = (Polynomail)malloc(sizeof(struct PolyNode)); //求积链表
	head->link = NULL;
	while (L1) { //第一个多项式不为空
		Polynomail headOfL2 = L2;
		while (L2) { //第二个多项式不为空
			Polynomail p = (Polynomail)malloc(sizeof(struct PolyNode));
			p->link = NULL;
			p->coef = L1->coef * L2->coef;
			p->expon = L1->expon + L2->expon;
			Polynomail pre = head; //存放前一个节点的地址
			while (pre->link && pre->link->expon > p->expon) {
				//求积链表中找到那个指数exp比新节点的指数exp小的那个节点
				pre = pre->link;
			}
			if (pre->link == NULL || pre->link->expon < p->expon) { //把新节点的插入到那个指数exp比它小的节点之前
				// pre->link == NULL 新节点的指数比求积链表中的任何一个节点的指数都要小，直接把新节点插入到表尾
				// pre->link->expon < p->expon
				// 找到了比新节点指数小的节点，并得到了该节点的前一个节点的地址，我们就可以把新节点插入到比它指数小的那个节点的前面
				p->link = pre->link;
				pre->link = p;
			}
			else { //pre->link->expon == p->expon
				   // 指数一样，进行系数相加，并对结果加以判断
				pre->link->coef += p->coef;
				if (pre->link->coef == 0) {
					Polynomail temp = pre->link;
					pre->link = temp->link;
					free(temp);
				}
				free(p);
			}
			L2 = L2->link; //后移
		}
		L2 = headOfL2; //归位
		L1 = L1->link; //后移
	}
	return head;
}
Polynomail creatList() {
	int n;
	scanf("%d", &n);
	Polynomail head = (Polynomail)malloc(sizeof(struct PolyNode));
	head->link = NULL;
	Polynomail p = head;

	while (n--) {
		Polynomail q = (Polynomail)malloc(sizeof(struct PolyNode));
		q->link = NULL;
		scanf("%d %d", &q->coef, &q->expon);
		p = p->link = q;
	}
	return head;
}
void printList(Polynomail L) {
	if (L->link == NULL) { // 零多项式应输出0 0
		Polynomail p = (Polynomail)malloc(sizeof(struct PolyNode));
		p->link = NULL;
		p->coef = p->expon = 0;
		L->link = p;
	}
	L = L->link;
	while (L) {
		printf("%d %d", L->coef, L->expon);
		if (L->link)
			putchar(' ');
		else
			putchar('\n');
		L = L->link;
	}
}

int main(int argc, char const* argv[]) {
	Polynomail p1 = creatList();
	Polynomail p2 = creatList();
	printList(polyMult(p1, p2));
	printList(polyAdd(p1, p2));
	return 0;
}

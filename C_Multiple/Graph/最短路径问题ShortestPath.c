/** 
 * 最短路径(Shortes Path): 两个不同顶点之间的所有路径中,边的权值之和最小的那条路径
 * 原点: 第一个顶点
 * 终点: 最后一个顶点
 * 
 * 分类:
 * 1.单源最短路径问题:
 * 从某固定源点出发,求它到所有其他顶点的最短路径
 *     -(有向)无权图
 *     -(无向)有权图
 * 
 * 2.多源最短路径问题:
 * 求任意两顶点间的最短路径
 * 
 */
#include "graph_list.h"
#include "graph_matrix.h"
#include "linked_quene.h"
/* 
    1.1 无权图单源最短路算法
    按照非递减顺序找出各顶点的最短路径
    BFS
 */
/* 邻接表存储 - 无权图的单源最短路算法 */

/* dist[]和path[]全部初始化为-1 */
void Unweighted(LGraph Graph, int dist[], int path[], Vertex S) {
	Queue Q;
	Vertex V;
	PtrToAdjVNode W;

	Q = CreateQueue(Graph->Nv); /* 创建空队列, MaxSize为外部定义的常数 */
	dist[S] = 0;				/* 初始化源点 */
	AddQ(Q, S);

	while (!IsEmpty(Q)) {
		V = DeleteQ(Q);
		for (W = Graph->G[V].FirstEdge; W; W = W->Next) /* 对V的每个邻接点W->AdjV */
			if (dist[W->AdjV] == -1) {					/* 若W->AdjV未被访问过 */
				dist[W->AdjV] = dist[V] + 1;			/* W->AdjV到S的距离更新 */
				path[W->AdjV] = V;						/* 将V记录在S到W->AdjV的路径上 */
				AddQ(Q, W->AdjV);
			}
	} /* while结束*/
}

/* 
    1.2 有权图单源最短路径
    Dijkstra算法
    令 s = { 原点s + 已经确定的最短路径的顶点 v1 }
    按照非递减顺序找出各顶点的最短路径
        -真正的最短路径必须只经过s中的顶点
        -每次从未收录的顶点中选一个dist最小的收录
 */
/* 邻接矩阵存储 - 有权图的单源最短路算法 */

Vertex FindMinDist(MGraph Graph, int dist[], int collected[]) { /* 返回未被收录顶点中dist最小者 */
	Vertex MinV, V;
	int MinDist = INFINITY;

	for (V = 0; V < Graph->Nv; V++) {
		if (collected[V] == false && dist[V] < MinDist) {
			/* 若V未被收录，且dist[V]更小 */
			MinDist = dist[V]; /* 更新最小距离 */
			MinV = V;		   /* 更新对应顶点 */
		}
	}
	if (MinDist < INFINITY) /* 若找到最小dist */
		return MinV;		/* 返回对应的顶点下标 */
	else
		return ERROR; /* 若这样的顶点不存在，返回错误标记 */
}

bool Dijkstra(MGraph Graph, int dist[], int path[], Vertex S) {
	int collected[MaxVertexNum];
	Vertex V, W;

	/* 初始化：此处默认邻接矩阵中不存在的边用INFINITY表示 */
	for (V = 0; V < Graph->Nv; V++) {
		dist[V] = Graph->G[S][V];
		if (dist[V] < INFINITY)
			path[V] = S;
		else
			path[V] = -1;
		collected[V] = false;
	}
	/* 先将起点收入集合 */
	dist[S] = 0;
	collected[S] = true;

	while (1) {
		/* V = 未被收录顶点中dist最小者 */
		V = FindMinDist(Graph, dist, collected);
		if (V == ERROR)					/* 若这样的V不存在 */
			break;						/* 算法结束 */
		collected[V] = true;			/* 收录V */
		for (W = 0; W < Graph->Nv; W++) /* 对图中的每个顶点W */
			/* 若W是V的邻接点并且未被收录 */
			if (collected[W] == false && Graph->G[V][W] < INFINITY) {
				if (Graph->G[V][W] < 0) /* 若有负边 */
					return false;		/* 不能正确解决，返回错误标记 */
				/* 若收录V使得dist[W]变小 */
				if (dist[V] + Graph->G[V][W] < dist[W]) {
					dist[W] = dist[V] + Graph->G[V][W]; /* 更新dist[W] */
					path[W] = V;						/* 更新S到W的路径 */
				}
			}
	}			 /* while结束*/
	return true; /* 算法执行完毕，返回正确标记 */
}

/* 
    多源最短路
    1.直接将单源最短路算法调用v遍(稀疏图)
    2.Floyd算法(稠密图)

 */
/* 邻接矩阵存储 - 有权图的单源最短路算法 */

Vertex FindMinDist(MGraph Graph, int dist[], int collected[]) { /* 返回未被收录顶点中dist最小者 */
	Vertex MinV, V;
	int MinDist = INFINITY;

	for (V = 0; V < Graph->Nv; V++) {
		if (collected[V] == false && dist[V] < MinDist) {
			/* 若V未被收录，且dist[V]更小 */
			MinDist = dist[V]; /* 更新最小距离 */
			MinV = V;		   /* 更新对应顶点 */
		}
	}
	if (MinDist < INFINITY) /* 若找到最小dist */
		return MinV;		/* 返回对应的顶点下标 */
	else
		return ERROR; /* 若这样的顶点不存在，返回错误标记 */
}

bool Dijkstra(MGraph Graph, int dist[], int path[], Vertex S) {
	int collected[MaxVertexNum];
	Vertex V, W;

	/* 初始化：此处默认邻接矩阵中不存在的边用INFINITY表示 */
	for (V = 0; V < Graph->Nv; V++) {
		dist[V] = Graph->G[S][V];
		if (dist[V] < INFINITY)
			path[V] = S;
		else
			path[V] = -1;
		collected[V] = false;
	}
	/* 先将起点收入集合 */
	dist[S] = 0;
	collected[S] = true;

	while (1) {
		/* V = 未被收录顶点中dist最小者 */
		V = FindMinDist(Graph, dist, collected);
		if (V == ERROR)					/* 若这样的V不存在 */
			break;						/* 算法结束 */
		collected[V] = true;			/* 收录V */
		for (W = 0; W < Graph->Nv; W++) /* 对图中的每个顶点W */
			/* 若W是V的邻接点并且未被收录 */
			if (collected[W] == false && Graph->G[V][W] < INFINITY) {
				if (Graph->G[V][W] < 0) /* 若有负边 */
					return false;		/* 不能正确解决，返回错误标记 */
				/* 若收录V使得dist[W]变小 */
				if (dist[V] + Graph->G[V][W] < dist[W]) {
					dist[W] = dist[V] + Graph->G[V][W]; /* 更新dist[W] */
					path[W] = V;						/* 更新S到W的路径 */
				}
			}
	}			 /* while结束*/
	return true; /* 算法执行完毕，返回正确标记 */
}
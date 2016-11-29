#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define lson l,mid,rt<<1
#define rson mid,r,rt<<1|1
#define MAX 105
using namespace std;
struct Node {
	int flag;
	double l, r, h;
}A[MAX << 2];
int cover[MAX << 4];
double num[MAX << 2], tmp[MAX << 2], len[MAX << 4];
//区间树的划分，每个节点表示一个区间。叶子节点的l + 1 = r。
//我犯的错误是总认为叶子节点是l = r。
void init() {
	memset(len, 0, sizeof(len));
	memset(cover, 0, sizeof(cover));
}
bool cmp(Node a, Node b) {
	if (a.h == b.h)
		return a.flag<b.flag;
	return a.h<b.h;
}
void pushup(int l, int r, int rt) {
	if (cover[rt])len[rt] = num[r] - num[l];
	else if (l + 1 == r)len[rt] = 0;
	else len[rt] = len[rt << 1] + len[rt << 1 | 1];
}
void update(int a, int b, int c, int l, int r, int rt) 
{
	if (a == l&&b == r) {
		cover[rt] += c;
		pushup(l, r, rt);
		return;
	}
	int mid = (l + r) >> 1;
	if (mid >= b)update(a, b, c, lson);
	else if (mid <= a)update(a, b, c, rson);
	else {
		update(a, mid, c, lson);
		update(mid, b, c, rson);
	}
	pushup(l, r, rt);
}
int search(double now, int n) {
	int left = 1, right = n, ans;
	while (left <= right) {
		int mid = (left + right) >> 1;
		if (num[mid] >= now) {
			ans = mid;
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}
	return ans;
}
int main()
{
	int n, i, j, k, id, t = 1;
	double x1, y1, x2, y2, ans;
	while (scanf("%d", &n), n) 
	{
		for (id = 0, i = 0; i<n; ++i) 
		{
			scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2);
			A[++id].l = x1; A[id].r = x2; A[id].h = y1; A[id].flag = 1; tmp[id] = x1;
			A[++id].l = x1; A[id].r = x2; A[id].h = y2; A[id].flag = -1; tmp[id] = x2;
		}
		sort(A + 1, A + id + 1, cmp);
		sort(tmp + 1, tmp + id + 1);
		for (id = 0, i = 1; i <= (n << 1); ++i) {
			if (i == 1 || tmp[i] != tmp[i - 1])
				num[++id] = tmp[i];
		}
		init(); ans = 0; A[0].h = A[1].h;
		for (i = 1; i <= (n << 1); ++i) {
			ans += len[1] * (A[i].h - A[i - 1].h);
			int l = search(A[i].l, id);
			int r = search(A[i].r, id);
			update(l, r, A[i].flag, 1, id, 1);
		}
		printf("Test case #%d\n", t++);
		printf("Total explored area: %.2lf\n\n", ans);
	}
	return 0;
}
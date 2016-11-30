#include <stdio.h>
#include <algorithm>
using namespace std;
#define MAX 110
struct Node
{
	double l;
	double r;
	double h;
	bool flag;
	bool operator < (Node &a)
	{
		return h < a.h;
	}
}lines[MAX << 4];

bool cover[MAX << 4];
double Xs[MAX << 4];
double len[MAX << 4];

void pushup(int l, int r, int treeidx)
{
	if (cover[treeidx])
		len[treeidx] = Xs[r] - Xs[l];
	else if (l + 1 == r)
		len[treeidx] = 0;
	else
		len[treeidx] = len[treeidx << 1] + len[treeidx << 1 | 1];
}

void update(int l, int r, bool isin, int leftb, int rightb, int treeidx)
{
	if(l == leftb && r == rightb)
	{
		cover[treeidx] = isin;
		pushup(l, r, treeidx);
		return;
	}
	int m = leftb + (rightb - leftb) / 2;
	if (m >= r)
		update(l, r, isin, leftb, m, treeidx << 1);
	else if (m <= l)
		update(l, r, isin, m, rightb, treeidx << 1 | 1);
	else
	{
		update(l, m, isin, leftb, m, treeidx << 1);
		update(m, r, isin, m, rightb, treeidx << 1 | 1);
	}
	pushup(leftb, rightb, treeidx);
}

int binarysearch(double d, int end)
{
	int s = 1;
	int e = end;
	while(s < e)
	{
		int m = s + ((e - s) >> 1);
		if (Xs[m] == d)
			return m;
		else if (Xs[m] > d)
			e = m - 1;
		else
			s = m + 1;
	}
	return s;
}
int main()
{
	int n;
	int t = 1;
	while(scanf("%d", &n) && n)
	{
		double x1, y1, x2, y2;
		int numx = 1;
		for (int i = 0; i < n; i++)
		{
			scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2);
			Xs[numx] = x1;
			lines[numx].l = x1;
			lines[numx].r = x2;
			lines[numx].h = y1;
			lines[numx++].flag = true;
			
			Xs[numx] = x2;
			lines[numx].l = x1;
			lines[numx].r = x2;
			lines[numx].h = y2;
			lines[numx++].flag = false;			
		}
		sort(Xs + 1, Xs + numx);
		sort(lines + 1, lines + numx);
		numx--;

		int k = 2;
		for (int i = 2; i <= numx; i++)
			if (Xs[i] != Xs[i - 1])
				Xs[k++] = Xs[i];
		k--;
		double ans = 0;
		fill(cover, cover + (MAX << 4), false);
		fill(len, len + (MAX << 4), 0);

		for (int i = 1; i < numx; i++)
		{
			int l = binarysearch(lines[i].l, k);
			int r = binarysearch(lines[i].r, k);
			update(l, r, lines[i].flag, 1, k, 1);
			ans += len[1] * (lines[i + 1].h - lines[i].h);
		}
		printf("Test case #%d\n", t++);
		printf("Total explored area: %.2lf\n\n", ans);
	}
	return 0;
}
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#define MAXV 10
#define INF 0x3fffffff
#define MIN(x, y) ((x) < (y) ? (x) : (y))
int cost[MAXV][MAXV] = { { INF, INF, INF, INF, 1, INF, INF, INF, INF, INF },
						 { INF, INF, INF, INF, INF, INF, 1, 1, INF, INF },
						 { INF, INF, INF, INF, INF, INF, 1, INF, 1, INF },
						 { INF, INF, INF, INF, 1, INF, INF, 1, 1, INF },
						 { 1, INF, INF, 1, INF, INF, INF, INF, INF, INF },
						 { INF, INF, INF, INF, INF, INF, 1, INF, INF, 1 },
						 { INF, 1, 1, INF, INF, 1, INF, INF, INF, INF },
						 { INF, 1, INF, 1, INF, INF, INF, INF, INF, INF },
						 { INF, INF, 1, 1, INF, INF, INF, INF, INF, INF }, 
						 { INF, INF, INF, INF, INF, 1, INF, INF, INF, INF } };
char state[MAXV][15] = { "< >", "<d>", "<c>", "<r>", "<m, r>", "<c, d>", "<m, c, d>", "<m, d, r>", "<m, c, r>", "<m, c, d, r>" };
int d[MAXV];         //从s出发的最短距离
int used[MAXV];		 //确定该定点是否用过
int prev[MAXV];		 //确定该定点是否用过


void dijkstra(int s)
{
	int i;
	for (i = 0; i < MAXV; i++)
	{
		d[i] = INF;
	}
	memset(used, 0, sizeof(used));
	memset(prev, -1, sizeof(prev));
	d[s] = 0;

	while (1)
	{
		int v, u;
		v = -1;
		for (u = 0; u < MAXV; u++)
		{
			if (!used[u] && (v == -1 || d[u] < d[v]))
				v = u;
		}
		if (v == -1)
			break;
		used[v] = 1;
		for (u = 0; u < MAXV; u++)
		{
			if (d[u] >  d[v] + cost[v][u])
			{
				d[u] = d[v] + cost[v][u];
				prev[u] = v;
			}
		}
	}
}

int main()
{
	int path[20] = {0};
	int j, t;
	dijkstra(9);
	t = prev[0];
	for (j = 19; j > 0 && t != 9; j--)
	{
		path[j] = t;
		t = prev[t];
	}
	path[j] = 9;
	for (; j < 20; j++)
	{
		printf("%s -> ", state[path[j]]);
	}
	printf("%s\n", state[0]);

	return 1;
}
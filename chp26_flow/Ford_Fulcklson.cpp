#include <iostream>
#include <stack>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;
struct E
{
	int to;
	int cap;
	int rev;
	E(int a, int b, int c) : to(a), cap(b), rev(c){}
};
vector<E> G[510];
bool used[510];

int dfs(int s, int t, int f)
{
	if (s == t)
		return f;
	used[s] = true;
	for (int i = 0; i < G[s].size(); i++)
	{
		E &e = G[s][i];
		if(!used[e.to] && e.cap)
		{
			int d = dfs(e.to, t, min(f, e.cap));
			if(d > 0)
			{
				e.cap -= d;
				G[e.to][e.rev].cap += d;
				return d;
			}
		}
	}
	return 0;
}

int main()
{
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		G[a].push_back(E(b, c, G[b].size()));
		G[b].push_back(E(a, 0, G[a].size() - 1));
	}

	int ret = 0;
	while (true)
	{
		fill(used + 1, used + N + 1, false);
		int flow = dfs(1, N, 0x7fffffff);
		if (!flow)
			break;
		else
			ret += flow;
	}
	cout << ret << endl;
}
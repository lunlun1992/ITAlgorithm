#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <queue>
using namespace std;
typedef struct P
{
	int first;
	int second;
	int depth;
	P(int a, int b, int c) : first(a), second(b), depth(c){}
}P;
char matrix[1010][1010];
bool visited[1010][1010];
int main()
{
	int N;
	cin >> N;
	while (N--)
	{
		int C, R, ans;
		cin >> C >> R;
		for (int i = 0; i < R; i++)
		{
			scanf("%s", matrix[i]);
		}
		P temp(0, 0, 0);

		for (int i = 0; i < R; i++)
			for (int j = 0; j < C; j++)
				if(matrix[i][j] == '.')
				{
					temp.first = i;
					temp.second = j;
					temp.depth = 0;
					break;
				}


		queue<P> que;
		P qmax(0, 0, 0);
		que.push(temp);
		for (int i = 0; i < R; i++)
			for (int j = 0; j < C; j++)
				visited[i][j] = false;
		while(!que.empty())
		{
			P p = que.front();
			que.pop();

			if (p.first < 0 || p.first >= R || p.second < 0 || p.second >= C || matrix[p.first][p.second] == '#' || visited[p.first][p.second])
				continue;

			que.push(P(p.first, p.second + 1, p.depth + 1));
			que.push(P(p.first, p.second - 1, p.depth + 1));
			que.push(P(p.first + 1, p.second, p.depth + 1));
			que.push(P(p.first - 1, p.second, p.depth + 1));

			if(p.depth > qmax.depth)
			{
				qmax.first = p.first;
				qmax.second = p.second;
				qmax.depth = p.depth;
			}
			visited[p.first][p.second] = true;
		}

		qmax.depth = 0;
		que.push(qmax);
		ans = 0;
		for (int i = 0; i < R; i++)
			for (int j = 0; j < C; j++)
				visited[i][j] = false;
		while (!que.empty())
		{
			P p = que.front();
			que.pop();

			if (p.first < 0 || p.first >= R || p.second < 0 || p.second >= C || matrix[p.first][p.second] == '#' || visited[p.first][p.second])
				continue;

			que.push(P(p.first, p.second + 1, p.depth + 1));
			que.push(P(p.first, p.second - 1, p.depth + 1));
			que.push(P(p.first + 1, p.second, p.depth + 1));
			que.push(P(p.first - 1, p.second, p.depth + 1));

			ans = max(ans, p.depth);
			visited[p.first][p.second] = true;
		}

		cout << "Maximum rope length is " << ans << "." << endl;
	}
}
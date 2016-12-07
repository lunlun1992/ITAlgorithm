//be ware of the multiple edges
#include <iostream>
#include <stack>
#include <string.h>
using namespace std;
int ma[1010][1010];
int N, M;
bool first = true;
stack<int> st;

void dfs(int s)
{
	st.push(s);
	for (int i = 1; i <= N; i++)
	{
		if (ma[s][i])
		{
			ma[s][i]--;
			ma[i][s]--;
			dfs(i);
			break;
		}
	}
}

void fleury(int s)
{
	st.push(s);
	while (!st.empty())
	{
		bool isbridge = true;
		for (int i = 1; i <= N; i++)
		{
			if (ma[st.top()][i])
			{
				isbridge = false;
				break;
			}
		}
		if (isbridge)
		{
			if (first)
			{
				printf("%d", st.top());
				first = false;
			}
			else
				printf(" %d", st.top());
			st.pop();
		}
		else
		{
			int t = st.top();
			st.pop();
			dfs(t);
		}
	}
}

int main()
{
	cin >> N >> M;
	memset(ma, 0, sizeof(ma));
	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		ma[a][b]++;
		ma[b][a]++;
	}

	int odds = 0;
	int ss = 1;
	for (int i = 1; i <= N; i++)
	{
		int deg = 0;
		for (int j = 1; j <= N; j++)
		{
			deg += ma[i][j];
		}
		if (deg % 2 == 1)
		{
			odds++;
			ss = i;
		}
	}
	if (odds == 0 || odds == 2)
		fleury(ss);
	printf("\n");
}
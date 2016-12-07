#include <iostream> 
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <queue>
using namespace std;

int ver[10010];
int main()
{
	int N, M;
	scanf("%d%d", &N, &M);
	for (int i = 0; i < M; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		ver[a]++;
		ver[b]++;
	}
	int odds = 0;
	int bfalse = false;
	for (int i = 1; i <= N; i++)
	{
		if (ver[i] == 0)
			bfalse = true;
		if (ver[i] % 2 == 1)
			odds++;
	}
	if ((odds != 0 && odds != 2) || bfalse)
		printf("Part\n");
	else
		printf("Full\n");
	return 0;
}
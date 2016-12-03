#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <math.h>
using namespace std;
typedef pair<int, int> P;
int ran[1010];
int par[1010];
double dist[1010][1010];
bool isfix[1010];

double inline cal_dist(int i, int j, vector<P> &ps)
{
	return sqrt((double)((ps[i].first - ps[j].first) * (ps[i].first - ps[j].first) +
		(ps[i].second - ps[j].second) * (ps[i].second - ps[j].second)));
}

int find_set(int i)
{
	if (par[i] == i)
		return i;
	return par[i] = find_set(par[i]);
}

void union_set(int i, int j)
{
	int ip = find_set(i);
	int jp = find_set(j);
	if (ip == jp)
		return;
	if (ran[ip] < ran[jp])
		par[ip] = par[jp];
	else
	{
		par[jp] = par[ip];
		if (ran[ip] == ran[jp])
			ran[ip]++;
	}
}

bool check_same(int i, int j)
{
	return find_set(i) == find_set(j);
}


int main()
{
	int N, D;
	vector<P> points;
	cin >> N >> D;
	for (int i = 0; i < N; i++)
	{
		P p;
		cin >> p.first >> p.second;
		points.push_back(p);
		ran[i] = 0;
		par[i] = i;
	}

	for (int i = 0; i < N; i++)
	{
		dist[i][i] = 0;
		for (int j = i + 1; j < N; j++)
		{
			dist[i][j] = cal_dist(i, j, points);
			dist[j][i] = dist[i][j];
		}
	}
	fill(isfix, isfix + N, false);
	char op;
	int idx1, idx2;
	while(cin >> op)
	{
		if(op == 'O')
		{
			cin >> idx1;
			idx1--;
			isfix[idx1] = true;
			for (int i = 0; i < N; i++)
			{
				if (idx1 == i)
					continue;
				if (dist[i][idx1] <= D && isfix[i])
					union_set(i, idx1);
			}
		}
		else
		{
			cin >> idx1 >> idx2;
			if (check_same(idx1 - 1, idx2 - 1))
				cout << "SUCCESS" << endl;
			else
				cout << "FAIL" << endl;
		}
	}
	return 0;
}
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int dp[20][20];

int main()
{
	int n;
	while(cin >> n && n)
	{
		int d;
		cin >> d;
		vector<string> strs(n);
		for (int i = 0; i < n; i++)
			cin >> strs[i];
		sort(strs.begin(), strs.end());
		int counts = 0;
		for (int u = 0; u < n; u++)
		{
			for (int v = u + 1; v < n; v++)
			{
				string &f = strs[u];
				string &s = strs[v];
				memset(dp, 0, sizeof(dp));
				for (int j = 0; j < s.size(); j++)
					dp[0][j + 1] = j + 1;
				for (int i = 0; i < f.size(); i++)
					dp[i + 1][0] = i + 1;
				for (int i = 1; i <= f.size(); i++)
				{
					for (int j = 1; j <= s.size(); j++)
					{
						dp[i][j] = INT_MAX;
						if(f[i - 1] == s[j - 1])
						{
							dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]);
						}
						else
						{
							dp[i][j] = min(dp[i - 1][j - 1] + 1, dp[i][j]);
							dp[i][j] = min(dp[i][j - 1] + 1, dp[i][j]);
							dp[i][j] = min(dp[i - 1][j] + 1, dp[i][j]);
							if (i >= 2 && j >= 2 && f[i - 1] == s[j - 2] && f[i - 2] == s[j - 1])
								dp[i][j] = min(dp[i][j], dp[i - 2][j - 2] + 1);
								
							//要考虑更多情况，交换会引来更多的插入问题。
							if (i >= 2 && j >= 3 && f[i - 1] == s[j - 3] && f[i - 2] == s[j - 1])
								dp[i][j] = min(dp[i][j], dp[i - 2][j - 3] + 2);
							if (i >= 3 && j >= 2 && f[i - 3] == s[j - 1] && f[i - 1] == s[j - 2])
								dp[i][j] = min(dp[i][j], dp[i - 3][j - 2] + 2);
						}
					}
				}

				if(dp[f.size()][s.size()] <= d)
				{
					counts++;
					cout << f << "," << s << endl;
				}
			}
		}
		cout << counts << endl;
	}
}
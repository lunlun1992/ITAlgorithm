#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <math.h>
using namespace std;
typedef pair<int, int> P;
double dist[1000][1000];
int main()
{
    int n;
    while(cin >> n)
    {
        vector<P> vec;
        for(int i = 0; i < n; i++)
        {
            P p;
            cin >> p.first >> p.second;
            vec.push_back(p);
        }

        for(int i = 0; i < n; i++)
        {
            for(int j = i; j < n; j++)
            {
                dist[i][j] = dist[j][i] = sqrt((double)((vec[i].first - vec[j].first) * (vec[i].first - vec[j].first) + (vec[i].second - vec[j].second) * (vec[i].second - vec[j].second)));
            }
        }
        
        if(n < 2)
            printf("0\n");
        else if(n == 2)
            printf("%.2lf", dist[0][1]);
        else
        {
            vector<vector<double>> dp;
            for(int i = 0; i < n; i++)
            {
                vector<double> temp(n, 0);
                dp.push_back(temp);
            }
            dp[1][0] = dist[1][0];
            
            for(int i = 2; i < n; i++)
            {
                dp[i][i - 1] = 10000000000;
                for(int k = 0; k < i - 1; k++)
                    dp[i][i - 1] = min(dp[i][i - 1], dp[i - 1][k] + dist[i][k]);
                for(int j = 0; j < i - 1; j++)
                    dp[i][j] = dp[i - 1][j] + dist[i][i - 1];
            }
            printf("%.2lf\n", dp[n - 1][n - 2] + dist[n - 1][n - 2]);
        }
    }
}
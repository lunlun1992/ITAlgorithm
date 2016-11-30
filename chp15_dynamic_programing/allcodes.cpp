#include <iostream>
#include <vector>
using namespace std;

int cut_rod(vector<int> &rods, vector<int> &prices)
{
    int len = rods.size();
    vector<int> dp(0, len + 1);
    for(int i = 1; i <= len; i++)
    {
        for(int j = 0; j < i; j++)
        {
            dp[i] = max(dp[i], dp[j] + prices[i - j]);
        }
    }
    return dp[len];
}
#define MAXN 10000
int dp[MAXN][MAXN];
int idx[MAXN][MAXN];
int maxmatrix(vector<int> nums)
{
    int len = nums.size();
    int n = len - 1;

    for(int i = 0; i < len; i++)
        for(int j = 0; j < len; j++)
            dp[i][j] = INT_MAX;
    for(int i = 1; i <= n; i++)
        dp[i][i] = 0;
    for(int gap = 1; gap < n; gap++)
    {
        for(int i = 1; i + gap <= n; i++)
        {
            int j = i + gap;
            for(int k = i; k < j; k++)
            {
                int temp = dp[i][k] + dp[k + 1][j] + nums[i - 1] * nums[k] * nums[j];
                if(dp[i][j] > temp)
                {
                    dp[i][j] = temp;
                    idx[i][j] = k;
                }
            }
        }
    }
    return dp[1][n];
}

void print_parens(int i, int j)
{
    if(i == j)
        cout << 'A';
    else
    {
        cout << '(';
        print_parens(i, idx[i][j]);
        print_parens(idx[i][j] + 1, j);
        cout << ')';
    }
}

int save[MAXN][MAXN];
double w[MAXN][MAXN];
double e[MAXN][MAXN];
double optBST(vector<double> p, vector<double> q)
{
    int n = p.size() - 1;
    for(int i = 1; i <= n; i++)
    {
        e[i][i - 1] = q[i - 1];
        w[i][i - 1] = q[i - 1];
    }

    for(int l = 1; l <= n; l++)
    {
        for(int i = 1; i + l <= n + 1; i++)
        {
            int j = i + l - 1;
            e[i][j] = 8000000;
            w[i][j] = w[i][j - 1] + p[j] + q[j];
            for(int k = i; k <= j; k++)
            {
                double temp = e[i][k - 1] + e[k + 1][j] + w[i][j];
                if(temp < e[i][j])
                {
                    e[i][j] = temp;
                    save[i][j] = k;
                }
            }
        }
    }
    return e[1][n];
}

void print_tree(int s, int e, int blk)
{
    if(s > e)
        return;
    for(int i = 0; i < blk; i++)
        printf("\t");
    int r = save[s][e];
    printf("--<%d>\n", r);
    print_tree(s, r - 1, blk + 1);
    print_tree(r + 1, e, blk + 1);
}

int main()
{
    vector<double> p = {0, 0.04, 0.06, 0.08, 0.02, 0.10, 0.12, 0.14};
    vector<double> q = {0.06, 0.06, 0.06, 0.06, 0.05, 0.05, 0.05, 0.05};
    cout << optBST(p, q) << endl;
    print_tree(1, p.size() - 1, 1);
    return 0;
}
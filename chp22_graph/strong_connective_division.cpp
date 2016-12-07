#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#define MAX_V 100010
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int V;
int E;
int numpairs;
vector<int> G[MAX_V];
vector<int> rG[MAX_V];
vector<int> vs;
bool used[MAX_V];
int cmp[MAX_V];
__int64 stairs[MAX_V];

void dfs(int v)
{
     used[v] = true;
     for(int i = 0; i < G[v].size(); i++)
     {
          if(!used[G[v][i]])
               dfs(G[v][i]);
     }
     vs.push_back(v);
}

void rdfs(int v, int k)
{
     used[v] = true;
     cmp[k]++;
     for(int i = 0; i < rG[v].size(); i++)
     {
          if(!used[rG[v][i]])
               rdfs(rG[v][i], k);
     }
}

int main(int argc, char** argv)
{
     int n, m;
     scanf("%d%d", &V, &E);
     for(int i = 0; i < E; i++)
     {
          int a, b;
          scanf("%d%d", &a, &b);
          G[a - 1].push_back(b - 1);
          rG[b - 1].push_back(a - 1);
     }
    
     memset(used, 0, sizeof(used));
     vs.clear();
     for(int v = 0; v < V; v++)
     {
          if(!used[v])
               dfs(v);
     }
    
     memset(used, 0, sizeof(used));
     int k = 0;
     for(int i = vs.size() - 1; i >= 0; i--)
     {
          if(!used[vs[i]])
          {
               rdfs(vs[i], k);              
               k++;
          }
     }
     int max = -1;
     for(int i = 0; i < k; i++)
     {
          max = max > cmp[i] ? max : cmp[i];
     }
     __int64 mul = 1;
     stairs[2] = 1;
     for(int i = 3; i <= max; i++)
     {
          mul = mul * i / (i - 2);
          stairs[i] = mul;
     }
     __int64 sum = 0;
     for(int i = 0; i < k; i++)
     {
          if(cmp[i] > 1)
          {
               sum += stairs[cmp[i]];
          }
     }
     printf("%I64d\n", sum);
     return 0;
}

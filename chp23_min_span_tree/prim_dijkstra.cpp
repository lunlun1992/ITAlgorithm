#include <stdio.h>
#include <stdlib.h>
#define INF 0x7fffffff
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int cost[MAXV][MAXV];
int d[MAXV];
int used[MAXV];
int prev[MAXV];

int main(int argc, char *argv[])
{
     int i;
     int s;
     int V;
     int v;
     memset(d, 0, sizeof(d));
     d[s] = 0;
     memset(used, 0, sizeof(used));
     used[s] = 1;
    
     while(1)
     {    
          v = -1;
          for(i = 0; i < V; i++)
               if(!used[i] && (v == -1 || d[i] < d[v]))
                    v = i;
          if(v == -1)
               break;
          used[v] = 1;
          for(i = 0; i < V; i++)
               if(d[i] > (d[v] + cost[v][i]))
               {
                    d[i] = d[v] + cost[v][i];
                    prev[i] = v;
               }
     }
}

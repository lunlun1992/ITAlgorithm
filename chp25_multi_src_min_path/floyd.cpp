#include <stdio.h>
#include <stdlib.h>
#define INF 0x7fffffff
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int d[MAXV][MAXV]
int after[MAXV][MAXV];

int main(int argc, char *argv[])
{
     int V;
     int i, j, k;
     for(i = 0; i < V; i++)
          for(j = 0; j < V; j++)
          {
               after[i][j] = i;
          }
         
     for(k = 0; k < V; k++)
     {
          for(j = 0; j < V; j++)
          {
               if(k == j)
                    continue;
               for(i = 0; i < V; i++)
               {
                    if(k == i)
                         continue;
                    if(d[i][j] > d[i][k] + d[k][j])
                    {
                         d[i][j] = d[i][k] + d[k][j];
                         after[i][j] = k;
                    }
               }
          }
     }
}

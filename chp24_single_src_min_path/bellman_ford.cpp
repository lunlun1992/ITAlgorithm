#include <stdio.h>
#include <stdlib.h>
#define INF 0x7fffffff

typedef struct edge_t
{
     int from;
     int to;
     int cost;    
}edge;

edge e[MAX_EDGE]
int d[MAX_VEC]
int V, E;


int main(int argc, char *argv[])
{
     int i;
     int s;
     for(i = 0; i < V; i++)
          d[i] = INF;
     d[s] = 0;
     while(1)
     {
          int j;
          int undated = 0;
          for(j = 0; j < E; j++)
          {
               if(d[e[j].from] != INF && d[e[j].to] > d[e[j].from] + e[j].cost)
               {
                    d[e[j].to] = d[e[j].from] + e[j].cost;
                    updated = 1;
               }
          }
          if(!updated)
               break;
     }
     return 0;
}

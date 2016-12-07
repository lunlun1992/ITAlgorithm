#include <stdio.h>
#include <stdlib.h>
#define INF 0x7fffffff
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

typedef struct edge_t
{
     int cost;
     int from;
     int to;
}edge;

edge e[MAXE];

int main(int argc, char *argv[])
{
     int i;
     int V, E;
     qsort(edge, E, sizeof(edge), compare);
     init_union_set(V);
     int res = 0;
     for(i = 0; i < E; i++)
     {
          edge ee = e[i];
          if(!same_union(e.from, e.to))
          {
               union(e.from, e.to);
               res += e.cost;
          }    
     }
     return res;
}

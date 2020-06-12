#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAXV 1000; //max number of vertices

typedef struct{
    edgenode *edges[MAXV+1];
    int degree[MAXV+1];
    int nvertices;
    int nedges;
    int directed;
}graph;
typedef struct{
    int y;
    int weight;
    struct edgenode *next;
}edgenode;


void initialize_graph(graph *g, bool directed);
void read_graph(graph *g, bool directed);
void insert_edge(graph *g, int x,int y, bool directed);
void print_graph(graph *g);


int main()
{
    printf("Dijkstra Based Shortest Graph Path Finder\n");
    return 0;
}


void initialize_graph(graph *g, bool directed)
{
    int i;
    g->nvertices = 0;
    g->nedges = 0;
    g->directed = directed;

    for (i=1; i<=MAXV; i++) g->degree[i] = 0;
    for (i=1; i<=MAXV; i++) g->edges[i] = NULL;
}
void read_graph(graph *g, bool directed)
{
    int i;
    int m;      //number of edges
    int x,y;    //vertices in edge (x,y)

    initialize_graph(g, directed);

    scanf("%d %d",&(g->nvertices),&m)

    for(i=1; i<=m; i++){
        scanf("%d %d",&x,&y)
        insert_edge(g,x,y,directed);
    }
}
void insert_edge(graph *g, int x,int y, bool directed)
{
    edgenode *p //temporary pointer

    p = malloc(sizeof(edgenode));

    p->weight = NULL:
    p->y = y;
    p->next = g->edges[x]

    g->edges[x] = p;
    g-> degree[x] ++;

    if (directed == FALSE)
        insert_edge(g,y,x,TRUE);
    else
        g->nedges ++;

}
void print_graph(graph *g)
{
    int i;
    edgenode *p; //temporary pointer

    for (i=1; i<=g->nvertices; i++){
        printf("%d: ",i);
        p = g->edges[i];
        while (p != NULL){
            printf(" %d",p->);
            p = p->next;
        }
        printf("\n");
    }
}

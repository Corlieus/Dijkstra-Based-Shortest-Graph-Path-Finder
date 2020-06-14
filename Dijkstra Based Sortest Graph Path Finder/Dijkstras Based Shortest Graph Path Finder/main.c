#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAXV 1000 //max number of vertices

typedef struct edgenode{
    int y;
    int weight;
    struct edgenode *next;
}edgenode;

typedef struct{
    edgenode *edges[MAXV+1];
    int degree[MAXV+1];
    int nvertices;
    int nedges;
    int directed;
}graph;



void initialize_graph(graph *g, bool directed,int m);
void build_graph(graph *g);
void insert_edge(graph *g, int x,int y, bool directed);
void print_graph(graph *g);
char filename[20] = "Graph.csv";

int main()
{
    printf("Dijkstra Based Shortest Graph Path Finder\n\n");
    graph *g = malloc(sizeof(graph));
    printf("Begin building graph...\n\n");
    build_graph(g);
    printf("Graph Built\n");
    print_graph(g);


    return 0;
}

void build_graph(graph *g)
{
    int i;
    bool directed;
    int m;      //number of vertices
    int x,y;    //vertices in edge (x,y)

    printf("Reading Graph from %s\n",filename);
    FILE *fp;
    fp = fopen(filename,"r");
    if(fp == NULL){
        printf("File %s not present",filename);
        abort();
    }
    else
    {
        printf("Reading file....\n");
        fscanf(fp,"directed,%d\nnvert,%d\nx,y\n",&directed,&m);
        printf("Directed = %d\nNumber of Vertices = %d\n",directed,m);

        initialize_graph(g,directed,m);

        printf("\n..initialized\n");

        char temp[2];
        while(fscanf(fp,"%s[^\n]",&temp) != EOF){
            x = temp[0]-48;
            y = temp[2]-48;
            printf("inserting:(%d,%d)\n",x,y);
            insert_edge(g,x,y,directed);
        }

        fclose(fp);
        printf("Read Successfully \n\n",m);
    }


}

void initialize_graph(graph *g, bool directed,int m)
{
    int i;
    g->nvertices = m;
    g->nedges = 0;
    g->directed = directed;

    for (i=0; i<=MAXV; i++) g->degree[i] = 0;
    for (i=0; i<=MAXV; i++) g->edges[i] = NULL;
}

void insert_edge(graph *g, int x,int y, bool directed)
{
    edgenode *p; //temporary pointer

    p = malloc(sizeof(edgenode));

    p->weight = NULL;
    p->y = y;
    p->next = g->edges[x];

    g->edges[x] = p;
    g-> degree[x]++;

    if (directed == false)
        insert_edge(g,y,x,true);
    else
        g->nedges ++;

}
void print_graph(graph *g)
{
    int i;
    edgenode *p; //temporary pointer

    for (i=0; i<g->nvertices; i++){
        printf("%d: ",i);
        p = g->edges[i];
        while (p != NULL){
            printf(" %d",p->y);
            p = p->next;
        }
        printf("\n");
    }
}

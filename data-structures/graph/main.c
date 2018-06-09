#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct edge_node {
    int weight;
    int target;
    struct edge_node *next;
} edge_node;

typedef struct graph {
    bool is_directed;
    int num_nodes;
    int num_edges;
    edge_node **edges;
} graph;

graph * create_graph(int num_nodes, bool is_directed) {
    graph *g = (graph *) malloc(sizeof(graph));
    g->num_nodes = num_nodes;
    g->num_edges = 0;
    g->is_directed = is_directed;
    g->edges = (edge_node **) malloc(sizeof(edge_node *) * num_nodes);
    for(int i = 0; i < num_nodes; i++)
        g->edges[i] = NULL;
    return g;
}

void print_graph(graph *g) {
    for(int i = 0; i < g->num_nodes; i++) {
        printf("[%d]: ", i);
        for(edge_node *n = g->edges[i]; n != NULL; n = n->next)
            printf("%d\t", n->target);
        printf("\n");
    }
}

void add_edge(graph *g, int source, int target, int weight) {
    edge_node *node = (edge_node *) malloc(sizeof(edge_node));
    node->weight = weight;
    node->target = target;

    node->next = g->edges[source];
    g->edges[source] = node;
    g->num_edges++;

    if ( !g->is_directed ) {
        edge_node *node2 = (edge_node *) malloc(sizeof(edge_node));
        node2->weight = weight;
        node2->target = source;
        node2->next = g->edges[target];
        g->edges[target] = node2;
        g->num_edges++;
    }
}

int main() {
    graph *g = create_graph(6, true);
    add_edge(g, 0, 1, 5);
    add_edge(g, 0, 2, 1);
    add_edge(g, 5, 3, 1);
    print_graph(g);
    printf("\n");
    graph *g2 = create_graph(6, false);
    add_edge(g2, 0, 1, 5);
    add_edge(g2, 0, 2, 1);
    add_edge(g2, 5, 3, 1);
    print_graph(g2);
    return 0;
}
/*
Final Project part 2
Mico Santiago

2nd attempt at implementing shortest path algorithm, this time uses a weighted graph instead of a matrix. and finds the shortest path.
pseudocode went something like this:
1. make all distances of all vertices infinite.
2. creatte a empty set of (weight, vertex)
3. put source vertex into set and make that distance 0x3f3f3f3f
4. while set not empty
    -return min distance vertex from set
    -loop through all adjacent vertexes and If dist[v] > dist[u] + weight(u, v)
        -update distance of v
        -if v is in set, update distance by removing it first then inserting with new distance.
        -if v is not in set, then insert it in set with new distance.
5. print distance

*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<bits/stdc++.h> 
using namespace std; 
#define INF 0x3f3f3f3f //ascii representation of ????? also, a big number

/* 
This class represents a directed graph using list representation, contains vetices, the nodes of the vertex and weighted pair for every edge.
*/
class graph 
{ 
    int vertices;                 // No. of vertices 
    list< pair<int, int> > *adj; // In a weighted graph, we need to store vertex and weight pair for every edge 

    public: 
        graph(int V);  // construct a graph 
        void add_edge(int u, int v, int w); // function to add an edge to graph
        void shortest_path(int s);  // prints shortest path from s 
}; 
  
/* 
Allocates memory for list 
*/
graph::graph(int V) 
{ 
    this->vertices = V; 
    adj = new list< pair<int, int> >[V]; 
} 
  
void graph::add_edge(int u, int v, int w) 
{ 
    adj[u].push_back(make_pair(v, w)); 
    adj[v].push_back(make_pair(u, w)); 
} 
/*  
Prints shortest paths from src to all other vertices by creating a set to store vetices, creates a vector for distances and makes them infinite.
Inserts source itself in set and makes its distance 0
*/
void graph::shortest_path(int source) 
{ 
    set< pair<int, int> > setds; // Create a set to store vertices
  
    vector<int> dist(vertices, INF); // Create a vector for distances and initialize all distances as infinite (INF) 

    setds.insert(make_pair(0, source)); // Insert source itself in Set and initialize its distance as 0. 
    dist[source] = 0; 
  
    /* Looping till all shortest distance are finalized 
       then setds will become empty */
    while (!setds.empty()) 
    { 
        pair<int, int> tmp = *(setds.begin()); // The first vertex in Set is the minimum distance vertex, extract it from set. 
        setds.erase(setds.begin()); 
  
        // vertex label is stored in second of pair (it 
        // has to be done this way to keep the vertices 
        // sorted distance (distance must be first item 
        // in pair) 
        int u = tmp.second; //

        list< pair<int, int> >::iterator i; // 'i' is used to get all adjacent vertices of a vertex 
        for (i = adj[u].begin(); i != adj[u].end(); ++i) 
        { 
            // Get vertex label and weight of current adjacent 
            // of u. 
            int v = (*i).first; 
            int weight = (*i).second; 
  
            //  If there is shorter path to v through u. 
            if (dist[v] > dist[u] + weight) 
            { 
                /*  If distance of v is not INF then it must be in 
                    our set, so removing it and inserting again 
                    with updated less distance.   
                    Note : We extract only those vertices from Set 
                    for which distance is finalized. So for them,  
                    we would never reach here.  */
                if (dist[v] != INF) 
                    setds.erase(setds.find(make_pair(dist[v], v))); 
  
                // Updating distance of v 
                dist[v] = dist[u] + weight; 
                setds.insert(make_pair(dist[v], v)); 
            } 
        } 
    } 
  
    // Print shortest distances stored in dist[] 
    printf("Vertex   Distance from Source\n"); 
    for (int i = 0; i < vertices; ++i) 
        printf("%d \t\t %d\n", i, dist[i]); 
} 
  
int main() 
{ 
    int vertex = 9; 
    graph my_graph(vertex); 

    my_graph.add_edge(0, 1, 1); 
    my_graph.add_edge(1, 2, 6); 
    my_graph.add_edge(1, 3, 1);
    my_graph.add_edge(1, 4, 5);  
    my_graph.add_edge(2, 3, 5);
    my_graph.add_edge(2, 5, 3);
    my_graph.add_edge(3, 4, 5);
    my_graph.add_edge(3, 5, 6);
    my_graph.add_edge(3, 6, 4);
    my_graph.add_edge(4, 6, 2);
    my_graph.add_edge(5, 5, 6);

  
    my_graph.shortest_path(0); 
  
    return 0; 
} 
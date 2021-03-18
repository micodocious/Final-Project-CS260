/*
Final Project part 1
Mico Santiago 

This is an adjacency matrix, it wastes a lot of space and has a time complexity of O(n) for the add function, O(n*n) for the remove function...
I could not implement shortest path or minimum spanning tree algo in time. Thought it was a good idea because lecture suggested to use a chess 
game maybe... I reused code from another project where I created a chess game in a terminal. 

*/
#include <iostream> 
using namespace std; 


/*
This matrix will be using a 2D array, we will assign the size of the array and each element of that array to zero. 
This is to show that the degree of each vertex in the graph is zero. 

*/
class graph { 
    private: 
        int vertices;   // number of vertices 
        int matrix[10][10]; // matrix 
    
    public: 
        graph(int x) // constructs a graph 
        { 
            vertices = x; 
    
            for (int i = 0; i < vertices; ++i) {            // initializing each element of the adjacency matrix to zero 
                for (int j = 0; j < vertices; ++j) { 
                    matrix[i][j] = 0; 
                } 
            } 
        } 
        /*
        The graph is displayed using an adjacency matrix graph[vertices_x][vertices_y]. The 2D maxtrix is displayed where if there is an edge between two
        vertices (x and y) then it goes to 1 otherwise 0. 

        */
        void display() 
        { 
            cout << "\n\n Adjacency Matrix:"; 
    
            for (int i = 0; i < vertices; ++i) {            // displaying the 2D array 
                cout << "\n"; 
                for (int j = 0; j < vertices; ++j) { 
                    cout << " " << matrix[i][j]; 
                } 
            } 
        } 
        /*
        The matrix adds edges between two existing vertices such as vertex x and y then the elements g[x][y] and g[y][x] of the matrix will be assigned to 1,
        saying that there is an edge there.

        */
        void add_edge(int x, int y) 
        { 
    
            if ((x >= vertices) || (y > vertices)) {        // checks if the vertex exists in the graph 
                cout << "Vertex does not exists!"; 
            } 
    
            if (x == y) {                                   // checks if the vertex is connecting to itself 
                cout << "Vertex is connecting to iteself!"; 
            } 
            else {                                          // connecting the vertices 
                matrix[y][x] = 1; 
                matrix[x][y] = 1; 
            } 
        }
        /*
        We increase the row and column of the matrix then initialize new elements of the vertex to 0. 
        i.e. the new vertex isn't connected to the other vertexes
        */
        void add_vertex() 
        { 
            vertices++;                                     // increasing the number of vertices 
            int i; 
    
            for (i = 0; i < vertices; ++i) {                // initializing the new elements to 0 
                matrix[i][vertices - 1] = 0; 
                matrix[vertices - 1][i] = 0; 
            } 
        } 
        /*
        Check if that vertex exists in the graph or not and if that vertex exists then we need to shift the rows to the left and
        and the columns above the matrix os that the row and column values gets replaed by the values of the next vertex and then
        decrease the number of vertices by 1. 
        */
        void removeVertex(int x) 
        { 
            if (x > vertices) {                             // checking if the vertex is present 
                cout << "\nVertex not present!"; 
                return; 
            } 
            else { 
                int i; 
    
                while (x < vertices) {                      // removing the vertex 
                    for (i = 0; i < vertices; ++i) {        // shifting the rows to left side 
                        matrix[i][x] = matrix[i][x + 1]; 
                    } 
    
                    for (i = 0; i < vertices; ++i) {        // shifting the columns above the matrix 
                        matrix[x][i] = matrix[x + 1][i]; 
                    } 
                    x++; 
                } 
                vertices--;                                 // decreasing the number of vertices 
            } 
        } 
}; 
  
int main() 
{ 
    graph my_graph(4);                       // creating objects of class Graph 
  
    my_graph.add_edge(0, 1);                  // calling methods 
    my_graph.add_edge(1, 2); 
    my_graph.add_edge(2, 3); 
    my_graph.add_edge(3, 4); 
    my_graph.display();       // the adjacency matrix created 

    my_graph.add_vertex();                    // adding a vertex to the graph 
    my_graph.add_edge(4, 3);                  // connecting that verex to other existing vertices 
    my_graph.add_edge(4, 1);  
    my_graph.display();       // the adjacency matrix with a new vertex

    my_graph.removeVertex(1);                // removing an existing vertex in the graph 
    my_graph.display();       // the adjacency matrix after removing a vertex 
  
    return 0; 
} 
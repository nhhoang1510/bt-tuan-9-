#include <iostream>
#include <cstring> 
using namespace std;

#define MAX_VERTICES 100
#define MAX_EDGES 100

class GraphList {
    int V;                              
    int adj[MAX_VERTICES][MAX_EDGES];   
    int degree[MAX_VERTICES];           

public:
    GraphList(int vertices) : V(vertices) {
        memset(adj, -1, sizeof(adj));   
        memset(degree, 0, sizeof(degree));
    }

    void addEdge(int u, int v) {
        adj[u][degree[u]++] = v;
        adj[v][degree[v]++] = u;  
    }

    void BFS(int start) {
        bool visited[MAX_VERTICES] = {false};
        int queue[MAX_VERTICES];
        int front = 0, rear = 0;

        queue[rear++] = start;
        visited[start] = true;

        cout << "BFS Order: ";
        while (front < rear) {
            int node = queue[front++];
            cout << node << " ";

            for (int i = 0; i < degree[node]; i++) {
                int neighbor = adj[node][i];
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    queue[rear++] = neighbor;
                }
            }
        }
        cout << endl;
    }

    void DFSUtil(int node, bool visited[]) {
        visited[node] = true;
        cout << node << " ";

        for (int i = 0; i < degree[node]; i++) {
            int neighbor = adj[node][i];
            if (!visited[neighbor]) {
                DFSUtil(neighbor, visited);
            }
        }
    }

    void DFS(int start) {
        bool visited[MAX_VERTICES] = {false};
        cout << "DFS Order: ";
        DFSUtil(start, visited);
        cout << endl;
    }
};

int main() {
    int V = 13; 
    GraphList g(V);

    g.addEdge(0, 1);  
    g.addEdge(0, 2);  
    g.addEdge(0, 3);  
    g.addEdge(0, 4);  
    g.addEdge(0, 5);  
    g.addEdge(5, 6); 
    g.addEdge(6, 7);  
    g.addEdge(0, 8); 
    g.addEdge(8, 9);  
    g.addEdge(9, 10); 
    g.addEdge(9, 11); 
    g.addEdge(11, 12);
    g.addEdge(0, 12); 

    g.BFS(0); 
    g.DFS(0);  

    return 0;
}


#include <iostream>
#include <list>
#include <vector>
#include <queue>

// This Graph is an UNDIRECTED graph using adjacency list representation.
class Graph{
    int v;
    std::list<int> *l;
    public:
    
    Graph(int _v){
            v = _v;
            // Create an array of lists, size = v
            l = new std::list<int>[v];
        }
        // Add an undirected edge between u and v
        void addEdge(int u,int v){
            l[u].push_back(v);
            l[v].push_back(u);
        }
        // Print adjacency list
        void printAdjList(){
            for (int i = 0; i < v; i++)
            {
                std::cout<<i<<" : ";
                for (int Neighbours : l[i])
                {
                    std::cout<<Neighbours<<" ";
                }
                std::cout<<"\n";
            }
            
        }
        // Uses Queue
        // Visits nodes level-by-level (like tree level order)
        void BFS(){
            std::queue<int> Q;
            std::vector<bool> vis(v,false);
        
            Q.push(0);
            vis[0] = true;
        
        
            while(Q.size() > 0){
                int u = Q.front();
                Q.pop();
        
                std::cout<<u<<" ";
        
                for (int v : l[u])
                {
                    if(!vis[v]){
                        vis[v] = true;
                        Q.push(v);
                    }
                }
            }
            std::cout<<"\n";
        }
        // Performs Depth First Search using recursion
        void dfsHelper(int u, std::vector<bool> &vis){
            std::cout<<u<<" ";
            vis[u] = true;

            for (int v : l[u])
            {
                if (!vis[v])
                {
                    dfsHelper(v,vis);
                }
                
            }
            
        }
        // Calls helper function starting from source node
        void DFS(){
            int src = 0;
            std::vector<bool> vis(v,false);

            dfsHelper(src,vis);
            std::cout<<std::endl;
        }

};


int main(){
    Graph G1(6);

    G1.addEdge(0,1);
    G1.addEdge(1,2);
    G1.addEdge(1,3);
    G1.addEdge(2,4);
    G1.addEdge(2,5);

    //       3
    //       |
    // 0 --- 1 --- 2 --- 4
    //             |
    //             5

    // G1.printAdjList();

    G1.BFS();

    G1.DFS();
    
    
    return 0;
}
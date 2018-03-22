#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

int input(string text) {
    int n;
    cout << text << endl;
    cin >> n;
    return n;
}

void setupGraph(int &edges, int nodes, vector<vector<int>> &graph){
  edges -= nodes - 1;                     //finder overskydende edges
  for(int i = 1; i != nodes; i++){        //opretter nodes
    int con_node = rand()%i;              //randomizer hvilken node der connectes til
    int weight = rand()%9+1;              //randomizer weight
    graph[i][con_node] = weight;          //indsætter nodes
    graph[con_node][i] = weight;
  }
  while(edges > 0) {                      //tilføjer overskydende edges
    int weight = rand()%9+1;
    int ran_node1 = rand()%nodes;     //finder random nodes, og sørger for de ikke er ens
    int ran_node2;
    do {
      ran_node2 = rand()%nodes;
    }
    while (ran_node1 == ran_node2);
    if(!graph[ran_node1][ran_node2]) {    //opretter edge, hvis der ikke er en
      graph[ran_node1][ran_node2] = weight;
      graph[ran_node2][ran_node1] = weight;
      edges--;                            //opdaterer antal overskydende edges
    }
  }
}

/*
int minDistance(int dist[], bool sptSet[])
{
   // Initialize min value
   int min = INT_MAX, min_index;

   for (int v = 0; v < V; v++)
     if (sptSet[v] == false && dist[v] <= min)
         min = dist[v], min_index = v;

   return min_index;
}

int printSolution(int dist[], int n)
{
   printf("Vertex   Distance from Source\n");
   for (int i = 0; i < V; i++)
      printf("%d tt %d\n", i, dist[i]);
}

int distCalc(vector<vector<int>> &graph, int src, int V){
  int dist[V];     // The output array.  dist[i] will hold the shortest
                   // distance from src to i

  bool sptSet[V]; // sptSet[i] will true if vertex i is included in shortest
                  // path tree or shortest distance from src to i is finalized

  // Initialize all distances as INFINITE and stpSet[] as false
  for (int i = 0; i < V; i++)
     dist[i] = INT_MAX, sptSet[i] = false;

  // Distance of source vertex from itself is always 0
  dist[src] = 0;

  // Find shortest path for all vertices
  for (int count = 0; count < V-1; count++)
  {
    // Pick the minimum distance vertex from the set of vertices not
    // yet processed. u is always equal to src in first iteration.
    int u = minDistance(dist, sptSet);

    // Mark the picked vertex as processed
    sptSet[u] = true;

    // Update dist value of the adjacent vertices of the picked vertex.
    for (int v = 0; v < V; v++)

      // Update dist[v] only if is not in sptSet, there is an edge from
      // u to v, and total weight of path from src to  v through u is
      // smaller than current value of dist[v]
      if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX
                                    && dist[u]+graph[u][v] < dist[v])
         dist[v] = dist[u] + graph[u][v];
  }

  // print the constructed distance array
  printSolution(dist, V);
}
*/

int main() {
    srand(45);
    int nodes = input("Antal noder: ");
    int edges = input("Antal kanter: ");
    if (edges<nodes-1) {
        cout << "Error! too many nodes!!! Wtf!!!" << '\n';
        return 0;
    }

    if (edges>(nodes*nodes-nodes)/2) {
        cout << "Error! too many edges!!! Wtf!!!" << '\n';
        return 0;
    }

    vector<vector<int>> graph(nodes,vector<int>(nodes));
    setupGraph(edges,nodes,graph);
    for(auto v = 0; v != graph.size(); v++){
        for(auto v1 = graph[v].begin(); v1 != graph[v].end(); v1++){
            cout << *v1 << " ";
        }
        cout << "\n";
    }
    //distCalc(vector<vector<int>> &graph, int src, int V)
    return 0;
}

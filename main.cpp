#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <chrono>
#include <cstdint>

using namespace std;
const int inf = 1 << 30;

int input(string text)
{
    int n;

    cout << text << endl;
    cin >> n;
    return(n);
}

void setupGraph(int&edges, int nodes, vector <vector <int> >&graph)
{
    edges -= nodes - 1;                    //finder overskydende edges
    for (int i = 1; i != nodes; i++)       //opretter nodes
    {
        int con_node = rand() % i;          //randomizer hvilken node der connectes til
        int weight   = rand() % 9 + 1;      //randomizer weight
        graph[i][con_node] = weight;        //indsætter nodes
        graph[con_node][i] = weight;
    }
    while (edges > 0)                      //tilføjer overskydende edges
    {
        int weight    = rand() % 9 + 1;
        int ran_node1 = rand() % nodes;     //finder random nodes, og sørger for de ikke er ens
        int ran_node2;
        do
        {
            ran_node2 = rand() % nodes;
        } while (ran_node1 == ran_node2);
        if (graph[ran_node1][ran_node2]==inf)   //opretter edge, hvis der ikke er en
        {
            graph[ran_node1][ran_node2] = weight;
            graph[ran_node2][ran_node1] = weight;
            edges--;                         //opdaterer antal overskydende edges
        }
    }
}

int dijk(int A, int B, vector< vector<int> > adj) {
    int n = adj.size();
    vector<int> dist(n);
    vector<bool> vis(n);

    for(int i = 0; i < n; ++i) {
        dist[i] = inf;
    }
    dist[A] = 0;

    for(int i = 0; i < n; ++i) {
        int cur = -1;
        for(int j = 0; j < n; ++j) {
            if (vis[j]) continue;
            if (cur == -1 || dist[j] < dist[cur]) {
                cur = j;
            }
        }

        vis[cur] = true;
        for(int j = 0; j < n; ++j) {
            int path = dist[cur] + adj[cur][j];
            if (path < dist[j]) {
                dist[j] = path;
            }
        }
    }

    return dist[B];
}


int main()
{
    srand(45);
    int nodes = input("Antal noder: ");
    int edges = input("Antal kanter: ");
    int dist , startpoint , endpoint;
    if (edges < nodes - 1)
    {
        cout << "Error! too many nodes!!! Wtf!!!" << '\n';
        return(0);
    }

    if (edges > (nodes * nodes - nodes) / 2)
    {
        cout << "Error! too many edges!!! Wtf!!!" << '\n';
        return(0);
    }

    vector <vector <int> > graph(nodes, vector <int>(nodes, inf));

    auto start = std::chrono::high_resolution_clock::now();
    setupGraph(edges, nodes, graph);

    auto end    = std::chrono::high_resolution_clock::now();
    auto result = std::chrono::duration_cast <std::chrono::microseconds>(end - start);

    for (auto v = 0; v != graph.size(); v++)
    {
        for (auto v1 = graph[v].begin(); v1 != graph[v].end(); v1++)
        {
            if(*v1==inf){
                cout << "0" << " ";
            }
            else{
                cout << *v1 << " ";
            }
        }
        cout << "\n";
    }

    startpoint = input("Afstand fra punkt: ");
    endpoint = input("Til punkt: ");

    auto start2 = std::chrono::high_resolution_clock::now();
    dist=dijk(startpoint-1,endpoint-1,graph);
    cout << "Dist: " << dist << '\n';

    auto end2    = std::chrono::high_resolution_clock::now();
    auto result2 = std::chrono::duration_cast <std::chrono::microseconds>(end2 - start2);
    std::cout << "Graph setup time: " << result.count() << " microseconds" << std::endl;
    std::cout << "Search time: " << result2.count() << " microseconds" << std::endl;

    return(0);
}

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

void setupGraph(int edges, int nodes, vector<vector<int>> &graph){

}

int main() {
    srand(45);
    int nodes = input("Antal noder: ");
    int edges = input("Antal kanter: ");
    if (edges<nodes-1) {
        cout << "Error! too many nodes" << '\n';
        return 0;
    }
    vector<vector<int>> graph(nodes,vector<int>(nodes));

    for(auto v = 0; v != graph.size(); v++){
        for(auto v1 = graph[v].begin(); v1 != graph[v].end(); v1++){
            cout << *v1 << " ";
        }
        cout << "\n";
    }


    return 0;
}

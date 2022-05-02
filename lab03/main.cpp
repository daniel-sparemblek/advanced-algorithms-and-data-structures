#include <iostream>
#include <set>
#include <vector>
#include <queue>
#include <iterator>
using namespace std;

struct Edge {
    char from;
    char to;
    int weight;
    Edge(char f, char t, int w) : from{f}, to{t}, weight{w} {}
    Edge() {}
};

using edges_t = vector<Edge>;
using vertices_t = set<char>;
using graph_t = pair<vertices_t, edges_t>;

graph_t prim(graph_t &graph,char start);
# define INF 0x3f3f3f3f
# define ASCII_A 65
typedef pair<int, int> ver_weight;

void addEdge(vector <pair<int, int> > adjacent[], int vertex1, int vertex2, int weight) {
    adjacent[vertex1].push_back(make_pair(vertex2, weight));
    adjacent[vertex2].push_back(make_pair(vertex1, weight));
}

graph_t prim(graph_t &graph,char start) {
    const int edge_num = graph.second.size();
    vector<ver_weight> adj[edge_num];
    for(auto & i : graph.second)
        addEdge(adj, int(i.to-ASCII_A), int(i.from-ASCII_A),
                i.weight);

    graph_t new_graph;
    vector<Edge> new_vector;
    priority_queue<ver_weight, vector<ver_weight>, greater<>> queue;
    int src = start-ASCII_A;
    vector<int> cost(edge_num, INF);
    vector<int> parent_ver(edge_num, -1);
    vector<bool> in_graph(edge_num, false);
    queue.push(make_pair(0, src));
    cost[src] = 0;
    while (!queue.empty()) {
        int vertex1 = queue.top().second;
        queue.pop();
        in_graph[vertex1] = true;
        for (auto pair : adj[vertex1]) {
            int vertex2 = pair.first;
            int weight = pair.second;
            if (!in_graph[vertex2] && cost[vertex2] > weight) {
                cost[vertex2] = weight;
                queue.push(make_pair(cost[vertex2], vertex2));
                parent_ver[vertex2] = vertex1;
            }
        }
    }
    for (int i = 1; i <= graph.first.size(); i++) {
        int weight;
        for (auto pair : adj[i])
            if(pair.first == parent_ver[i]) {
                weight = pair.second;
                break;
            }
        if (parent_ver[i] + ASCII_A < ASCII_A || parent_ver[i] + ASCII_A > ASCII_A+25) {
            //i++;
            continue;
        }
        Edge *tmp = new Edge(parent_ver[i] + ASCII_A, i + ASCII_A, weight);
        new_vector.push_back(*tmp);
    }
    new_graph.first = graph.first;
    new_graph.second = new_vector;

    return new_graph;
}

int main() {
    vertices_t vertices;
    edges_t edges;

    vertices.insert('A');	vertices.insert('B');
    vertices.insert('C');	vertices.insert('D');
    vertices.insert('E');	vertices.insert('F');
    vertices.insert('G');	vertices.insert('H');
    vertices.insert('I');	vertices.insert('J');
    vertices.insert('K');	vertices.insert('L');
    vertices.insert('M');	vertices.insert('N');
    vertices.insert('O');	vertices.insert('P');
    vertices.insert('R');	vertices.insert('S');
    vertices.insert('T');	vertices.insert('U');
    vertices.insert('V');	vertices.insert('W');
    vertices.insert('X');	vertices.insert('Y');

    edges.push_back(*(new Edge('A', 'B', 2)));
    edges.push_back(*(new Edge('A', 'C', 4)));
    edges.push_back(*(new Edge('B', 'C', 5)));
    edges.push_back(*(new Edge('B', 'D', 2)));
    edges.push_back(*(new Edge('B', 'E', 7)));
    edges.push_back(*(new Edge('C', 'D', 1)));
    edges.push_back(*(new Edge('C', 'H', 3)));
    edges.push_back(*(new Edge('C', 'G', 8)));
    edges.push_back(*(new Edge('D', 'H', 2)));
    edges.push_back(*(new Edge('D', 'G', 7)));
    edges.push_back(*(new Edge('E', 'F', 8)));
    edges.push_back(*(new Edge('E', 'H', 1)));
    edges.push_back(*(new Edge('F', 'J', 2)));
    edges.push_back(*(new Edge('F', 'I', 4)));
    edges.push_back(*(new Edge('F', 'N', 1)));
    edges.push_back(*(new Edge('G', 'H', 4)));
    edges.push_back(*(new Edge('G', 'L', 3)));
    edges.push_back(*(new Edge('G', 'K', 7)));
    edges.push_back(*(new Edge('H', 'I', 3)));
    edges.push_back(*(new Edge('H', 'M', 2)));
    edges.push_back(*(new Edge('H', 'L', 7)));
    edges.push_back(*(new Edge('I', 'N', 6)));
    edges.push_back(*(new Edge('I', 'M', 2)));
    edges.push_back(*(new Edge('J', 'O', 5)));
    edges.push_back(*(new Edge('K', 'P', 14)));
    edges.push_back(*(new Edge('L', 'T', 8)));
    edges.push_back(*(new Edge('L', 'P', 7)));
    edges.push_back(*(new Edge('M', 'N', 9)));
    edges.push_back(*(new Edge('M', 'S', 4)));
    edges.push_back(*(new Edge('M', 'R', 2)));
    edges.push_back(*(new Edge('N', 'O', 9)));
    edges.push_back(*(new Edge('N', 'V', 10)));
    edges.push_back(*(new Edge('N', 'R', 1)));
    edges.push_back(*(new Edge('O', 'V', 3)));
    edges.push_back(*(new Edge('R', 'U', 6)));
    edges.push_back(*(new Edge('R', 'T', 4)));
    edges.push_back(*(new Edge('S', 'V', 2)));
    edges.push_back(*(new Edge('U', 'V', 11)));
    edges.push_back(*(new Edge('U', 'X', 5)));
    edges.push_back(*(new Edge('V', 'W', 4)));
    edges.push_back(*(new Edge('V', 'Y', 8)));
    edges.push_back(*(new Edge('V', 'X', 6)));
    edges.push_back(*(new Edge('W', 'Y', 9)));


    graph_t graph = make_pair(vertices, edges);
    graph_t mstGraph = prim(graph,'A');

    cout << "vertices: " << endl;
    for(auto i : mstGraph.first){
        cout << i << " ";
    }

    cout << "edges: " << endl;
    for(auto i : mstGraph.second){
        cout << i.from << " "<< i.to << " "<< i.weight << endl;
    }
    cout << "its over";
    return 0;
}
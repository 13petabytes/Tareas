#ifndef GRAPH_H_
#define GRAPH_H_

#include <string>
#include <sstream>
#include <fstream>
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <algorithm>

using namespace std;

class Graph {
private:
    int edgesList;
    int edgesMat;
    int nodes;
    vector<int> *adjList;
    int *adjMatrix;

public:
    Graph(int n);
    Graph();
    void addEdgeAdjList(int u, int v);
    void addEdgeAdjMatrix(int u, int v);
    string printAdjList();
    string printAdjMat();
    string printAdjMat_clean();
    string DFS(int start, int goal);
    string depthHelper(int current, int goal, stack<int> &st, list<int> &visited, vector<vector<int>> &paths);
    string BFS(int start, int goal);
    string breadthHelper(int current, int goal, queue<int> &qu, list<int> &visited, vector<vector<int>> &paths);
    string print_visited(list<int> q);
    string print_path(vector<vector<int>> &path, int start, int goal);
    bool contains(list<int> ls, int node);
    void sortAdjList();
    void loadGraphList(string name, int n, int m);
    void loadGraphMat(string name, int n, int m);
};

// Implementaciones

Graph::Graph() : edgesList(0), edgesMat(0), nodes(0), adjList(nullptr), adjMatrix(nullptr) {}

Graph::Graph(int n) : edgesList(0), edgesMat(0), nodes(n) {
    adjList = new vector<int>[nodes];
    adjMatrix = new int[nodes * nodes]();
}

void Graph::addEdgeAdjList(int u, int v) {
    adjList[u].push_back(v);
    adjList[v].push_back(u);
    edgesList++;
}

void Graph::addEdgeAdjMatrix(int u, int v) {
    adjMatrix[u * nodes + v] = 1;
    adjMatrix[v * nodes + u] = 1;
    edgesMat++;
}

string Graph::printAdjList() {
    stringstream aux;
    for (int i = 0; i < nodes; i++) {
        aux << "vertex " << i << " :";
        for (int j : adjList[i]) {
            aux << " " << j;
        }
        aux << " ";
    }
    return aux.str();
}

void Graph::sortAdjList() {
    for (int i = 0; i < nodes; i++) {
        sort(adjList[i].begin(), adjList[i].end());
    }
}

string Graph::printAdjMat() {
    stringstream aux;
    for (int i = 0; i < nodes; i++) {
        for (int j = 0; j < nodes; j++) {
            aux << adjMatrix[i * nodes + j] << " ";
        }
    }
    return aux.str();
}

string Graph::printAdjMat_clean() {
    stringstream aux;
    aux << "\n nodes \t|";
    for (int i = 0; i < nodes; i++) {
        aux << "\t" << i;
    }
    aux << "\n";
    for (int i = 0; i < nodes; i++) {
        aux << "__________";
    }
    aux << "\n";
    for (int i = 0; i < nodes; i++) {
        aux << i << "\t|";
        for (int j = 0; j < nodes; j++) {
            aux << "\t" << adjMatrix[i * nodes + j];
        }
        aux << "\n";
    }
    return aux.str();
}

string Graph::DFS(int start, int goal) {
    stack<int> pila;
    list<int> visitados;
    vector<vector<int>> rutas(nodes, vector<int>(1, -1));

    pila.push(start);

    while (!pila.empty() && pila.top() != goal) {
        int actual = pila.top();
        visitados.push_back(actual);
        pila.pop();

        for (int neighbor : adjList[actual]) {
            if (!contains(visitados, neighbor)) {
                pila.push(neighbor);
                rutas[neighbor][0] = actual;
            }
        }
    }

    if (pila.empty()) {
        return " node not found";
    }

    visitados.push_back(pila.top());
    string result = print_visited(visitados);
    result += print_path(rutas, start, goal);
    return result;
}

string Graph::BFS(int start, int goal) {
    queue<int> fila;
    list<int> visitados;
    vector<vector<int>> rutas(nodes, vector<int>(1, -1));

    fila.push(start);

    while (!fila.empty() && fila.front() != goal) {
        int actual = fila.front();
        visitados.push_back(actual);
        fila.pop();

        for (int neighbor : adjList[actual]) {
            if (!contains(visitados, neighbor)) {
                fila.push(neighbor);
                if (rutas[neighbor][0] == -1) {
                    rutas[neighbor][0] = actual;
                }
            }
        }
    }

    if (fila.empty()) {
        return " node not found";
    }

    visitados.push_back(fila.front());
    string ans = print_visited(visitados);
    ans += print_path(rutas, start, goal);
    return ans;
}

bool Graph::contains(list<int> ls, int node) {
    return find(ls.begin(), ls.end(), node) != ls.end();
}

string Graph::print_visited(list<int> q) {
    stringstream aux;
    aux << "visited: ";
    for (int node : q) {
        aux << node << " ";
    }
    return aux.str();
}

string Graph::print_path(vector<vector<int>> &path, int start, int goal) {
    int node = path[goal][0];
    stack<int> reverse;
    reverse.push(goal);

    stringstream aux;
    aux << "path:";
    while (node != start) {
        reverse.push(node);
        node = path[node][0];
    }
    reverse.push(start);

    while (!reverse.empty()) {
        aux << " " << reverse.top();
        reverse.pop();
    }
    return aux.str();
}

void Graph::loadGraphList(string name, int a, int b){
	adjList = new vector<int>[a];
	nodes = a;
	string line;
	ifstream lee (name);
	int u, v;
    cout<<"x"<<endl;
	if (lee.is_open()){
        cout<<"y"<<endl;
		while (getline(lee, line)){
            cout<<"z"<<endl;
			u = stoi(line.substr(1,1));
			v = stoi(line.substr(4,1));
			addEdgeAdjList(u,v);
            
		}
		lee.close(); // Closes the file
	} else {
		cout << "Unable to open file";
	}
	sortAdjList();
}

void Graph::loadGraphMat(string name, int a, int b){
	adjMatrix = new int [a*b];
	nodes = a;
    cout<<"b"<<endl;
	for (int i = 0; i < a*b; i++)
		adjMatrix[i] = 0;
		string line;
		ifstream lee (name);
		int u, v;
        cout<<"a"<<endl;
		if (lee.is_open()){
            cout<<"c"<<endl;
			while (getline(lee, line)){
                cout<<"d"<<endl;
				u = stoi(line.substr(1,1));
				v = stoi(line.substr(4,1));
				addEdgeAdjMatrix(u,v);
			}
			lee.close(); // Closes the file
		} else {
			cout << "Unable to open file";
		}
}

#endif /* GRAPH_H_ */

// Class Graph:

// V (G): returns the number of vertices in the graph                                   done
// E (G): returns the number of edges in the graph                                      done
// adjacent (G, x, y): tests whether there is an edge from node x to node y.            tbd
// neighbors (G, x): lists all nodes y such that there is an edge from x to y.          tbd
// add (G, x, y): adds to G the edge from x to y, if it is not there.                   tbd
// delete (G, x, y): removes the edge from x to y, if it is there.                      tbd
// get_node_value (G, x): returns the value associated with the node x.                 done
// set_node_value( G, x, a): sets the value associated with the node x to a.            done
// get_edge_value( G, x, y): returns the value associated to the edge (x,y).            done
// set_edge_value (G, x, y, v): sets the value associated to the edge (x,y) to v.       done

// #ifndef A_H_INCLUDED
// #define A_H_INCLUDED

#include <climits> //INT_MAX
#include <cstdlib> //srand(),rand()
#include <ctime>   //time(0)
#include <iomanip>
#include <iostream>

using namespace std;

const int V = 50;
const int MAXWEIGHT = 999;
const int weightLO = 1;
const int weightHI = 10;
const double density = 0.4;
const int simulationloop = 1;           // modified the simulationloop to 10,000 to calculate average edge for each node.

double dijkstra(int **graph, int src);
void printSolution(int dist[], int path[], int V);
int minDistance(int dist[], bool sptSet[], int V);

class Graph
{
private:
    int numV;       // number of Vertex
    int numE;       // number of Edge
    double density; //edge density of graph
    // bool isWeighted = 1;
    // bool isDirected = 0;
    int **Matrix;

    bool check(int i, int j, int w = 1);
    int monteCarloSimulation(double density);

public:
    Graph(int numV);
    void createGraph(int numV, double density);
    ~Graph();
    int getnumV() { return numV; } //returns the number of vertices in the graph
    int getnumE() { return numE; } //returns the number of edges in the graph
    void setnumV(int numV) { this->numV = numV; }
    void setnumE(int numE) { this->numE = numE; }

    int **getMatrix() { return Matrix; } //returns the number of edges in the graph

    void setEdgeWeight(int tail, int head, double density); // sets the value associated to the edge (x,y) to v.
    int getEdgeWeight(int tail, int head);                  // returns the value associated to the edge (x,y).
    void removeEdgeWeight(int tail, int head, int weight);  // removes the edge from x to y, if it is there.

    void adjacent(int tail, int head);        // tests whether there is an edge from node x to node y.
    void add(int tail, int head, int weight); // adds to G the edge from x to y, if it is not there.

    void printAdjacentMatrix();
};
Graph::Graph(int numV)
{
    // while (numV <= 0)
    // {
    //     cout << "The number of vertices entered is incorrect! please re-enter" << endl;
    //     cin >> numV;
    // }
    this->numV = numV;
    // this->isWeighted = isWeighted;
    // this->isDirected = isDirected;

    // int **matrix;
    Matrix = new int *[numV]; //create nodes / create 2-D array
    int i, j;
    for (i = 0; i < numV; i++)
        Matrix[i] = new int[numV]; //create rows

    for (i = 0; i < numV; i++)
        for (j = 0; j < numV; j++)
            Matrix[i][j] = MAXWEIGHT;
}

void Graph::createGraph(int numV, double density)
{
    // cout << "enter edges";
    // cin >> numE;
    // while (numE < 0)
    //     cout << "input error! , re-enter";

    int i, j;
    srand(time(0));
    for (int i = 0; i < V; ++i)
        for (int j = i; j < V; ++j)
        {
            if (i == j)
                Matrix[i][j] = MAXWEIGHT;
            else
                setEdgeWeight(i, j, density);
        }
}

Graph::~Graph()
{
    int i = 0;
    for (i = 0; i < numV; i++)
        delete Matrix[i]; // delete array within matrix
    delete[] Matrix;      // delete actual matrix
}

//input check
bool Graph::check(int i, int j, int w)
{
    if (i >= 0 && i < numV && j >= 0 && j < numV && w > 0 && w <= MAXWEIGHT)
        return true;
    else
        return false;
}

void Graph::setEdgeWeight(int tail, int head, double density)
{

    // while (!check(tail, head, weight))
    // {
    //     cout << "error input, re-enter tail, head, weight";
    //     cin >> tail >> head >> weight;
    // }
    int weight;
    weight = monteCarloSimulation(density);
    Matrix[tail][head] = Matrix[head][tail] = weight;
}

void Graph::printAdjacentMatrix()
{
    int i, j;
    cout.setf(ios::left);
    cout << setw(4) << " ";
    for (i = 0; i < numV; i++)
        cout << setw(4) << i;
    cout << endl;
    for (i = 0; i < numV; i++)
    {
        cout << setw(4) << i;
        for (j = 0; j < numV; j++)
            cout << setw(4) << Matrix[i][j];
        cout << endl;
    }
}

int Graph::monteCarloSimulation(double density)
{
    double probability;
    int weight;
    probability = static_cast<double>(rand()) / RAND_MAX;
    if (probability <= density)
    {
        weight = weightLO + (weightHI - weightLO) * probability;
    }
    else
        weight = MAXWEIGHT;
    return weight;
}

int main()
{

    Graph graph(V);
    double avg_distance;
    double sum=0;

    // cout << "this is the first";
    for(int m=0;m<simulationloop;m++)
    {
    graph.createGraph(V, density);
    cout << "print Adjacent vertex" << endl;
    graph.printAdjacentMatrix();
    cout << endl
         << "+++++++++++++++++++++++++" << endl;

    int **arr = graph.getMatrix();
    int row = graph.getnumV();
    int column = graph.getnumV();

    // for (int i = 0; i < row; i++)
    // {
    //     for (int j = 0; j < column; j++)
    //     {
    //         arr[i][j] = *(arr[i] + j);
    //         cout << arr[i][j] << '\t';
    //     }
    //     cout << endl;
    // }

    sum+= dijkstra(arr, 0);
    // graph.~Graph();
    }

    cout<<"**Monte Carlo Simulation for Average Shortest Paths in Graphs**"<<endl;
    cout<<"Average Shortest Path for a Graph with 20% Density and edge weights between 1.0 to 10.0 is: "<<sum/simulationloop<<endl;

    return 0;
}

double dijkstra(int **arr, int src)
{

    // Step 1: Mark all nodes unvisited. Create a set of all the unvisited nodes called the unvisited set.
    // Step 2: Assign to every node a tentative distance value: set it to zero for our initial node and to infinity for all other nodes.
    //         Set the initial node as current.[15]
    // Step 3: For the current node, consider all of its unvisited neighbours and calculate their tentative distances through the current node.
    //         Compare the newly calculated tentative distance to the current assigned value and assign the smaller one.
    //         For example, if the current node A is marked with a distance of 6, and the edge connecting it with a neighbour B has length 2,
    //         then the distance to B through A will be 6 + 2 = 8.
    //         If B was previously marked with a distance greater than 8 then change it to 8. Otherwise, the current value will be kept.
    // Step 4: When we are done considering all of the unvisited neighbours of the current node,
    //         mark the current node as visited and remove it from the unvisited set. A visited node will never be checked again.
    // Step 5: If the destination node has been marked visited (when planning a route between two specific nodes)
    //         or if the smallest tentative distance among the nodes in the unvisited set is infinity (when planning a complete traversal;
    //         occurs when there is no connection between the initial node and remaining unvisited nodes), then stop. The algorithm has finished.
    // Step 6: Otherwise, select the unvisited node that is marked with the smallest tentative distance,
    //         set it as the new "current node", and go back to step 3.

    int dist[V], path[V];
    bool sptSet[V];
    double sum_distance=0;
    double avg_distance;
    int num_v =V;

    for (int i = 0; i < V; i++)
    {
        dist[i] = MAXWEIGHT;
        sptSet[i] = false;
        path[i] = -1;
    }

    dist[src] = 0;
    path[src] = src;

    for (int count = 0; count < V; count++)
    {
        // weight = MAXWEIGHT;
        int u = minDistance(dist, sptSet, V);
        path[count] = u;
        sptSet[count] = true;
        for (int v = 0; v < V; v++)
        {
            if (!sptSet[v] && arr && dist[u] != MAXWEIGHT && dist[u] + arr[u][v] < dist[v])
                dist[v] = dist[u] + arr[u][v];

        }
        if (dist[count]!=MAXWEIGHT)
                    sum_distance += dist[count];
                    else num_v--;
    }
    avg_distance = static_cast<double> (sum_distance / (num_v - 1));


// commit when calculate the average.
    printSolution(dist,path, V);

    cout << avg_distance << endl;

    return avg_distance;

}

int minDistance(int dist[], bool sptSet[], int V)
{
    int min = MAXWEIGHT, min_index;
    for (int v = 0; v < V; v++)
    {
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;
    }
    return min_index;
}

void printSolution(int dist[], int path[], int V)
{
    cout<<"Vertex \t\t Distance from Source"<<endl;
    for (int i = 0; i < V; i++)
        cout<<i<<'\t'<<'\t'<<dist[i]<<endl;
    cout << "++++++++++++++++" << endl;
    for (int i = 0; i < V; i++)
        cout << path[i] << "-->";
    cout << endl;
}

// #endif // A_H_INCLUDED
#include <iostream>
#include <vector>
#include <set>
#include <random>
#include <chrono>
#include <list>

using namespace std;
using namespace std::chrono;

// Greedy approximation for Maximal Independent Set
set<int> greedyMIS(const vector<list<int>>& graph) {
    int n = graph.size();
    vector<bool> selected(n, false); // To track selected vertices
    set<int> independentSet;

    for (int i = 0; i < n; ++i) {
        if (!selected[i]) {
            // Select vertex i for the independent set
            independentSet.insert(i);
            selected[i] = true;

            // Mark all its neighbors as selected (since they can't be part of the independent set)
            for (int neighbor : graph[i]) {
                selected[neighbor] = true;
            }
        }
    }

    return independentSet;
}

// Function to generate a random graph with n vertices and edge probability p using an adjacency list
vector<list<int>> generateRandomGraph(int n, double p) {
    vector<list<int>> graph(n);
    random_device rd;
    mt19937 gen(rd());
    bernoulli_distribution dist(p);

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (dist(gen)) {
                graph[i].push_back(j);
                graph[j].push_back(i);
            }
        }
    }
    return graph;
}

int main() {
    int n = 9999;        // Number of vertices
    double p = 0.004;    // Edge probability (very sparse)

    cout << "Generating graph with " << n << " vertices and edge probability " << p << "..." << endl;

    // Generate a large sparse random graph
    auto startGen = high_resolution_clock::now();
    vector<list<int>> graph = generateRandomGraph(n, p);
    auto endGen = high_resolution_clock::now();
    auto durationGen = duration_cast<seconds>(endGen - startGen);
    cout << "Graph generation completed in " << durationGen.count() << " seconds." << endl;

    // Measure time for Greedy MIS
    cout << "Running Greedy Maximal Independent Set algorithm..." << endl;
    auto startGreedy = high_resolution_clock::now();
    set<int> greedyIndependentSet = greedyMIS(graph);
    auto endGreedy = high_resolution_clock::now();
    auto durationGreedy = duration_cast<milliseconds>(endGreedy - startGreedy);

    cout << "Maximal Independent Set (Greedy Approximation) found with size: " << greedyIndependentSet.size() << endl;
    cout << "Time taken by Greedy Approximation: " << durationGreedy.count() << " milliseconds" << endl;

    return 0;
}

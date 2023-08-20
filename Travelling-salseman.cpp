#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <limits>
using namespace std;
const int INF = numeric_limits<int>::max();
int calculateBound(vector<vector<int>>& graph, vector<bool>& visited, int
currNode, int N) {
int bound = 0;
for (int i = 0; i < N; i++) {
if (!visited[i]) {
int minEdge = INF;
for (int j = 0; j < N; j++) {
if (i != j && !visited[j]) {
minEdge = min(minEdge, graph[i][j]);
}
}
bound += minEdge;
}
}
return bound;
}
int tspBranchAndBound(vector<vector<int>>& graph, vector<bool>& visited, int
currNode, int N, int cost, int& minCost) {
visited[currNode] = true;
if (count(visited.begin(), visited.end(), true) == N) {
visited[currNode] = false; 
return cost + graph[currNode][0];
}
int bound = calculateBound(graph, visited, currNode, N);
for (int i = 0; i < N; i++) {
if (!visited[i] && graph[currNode][i] != INF) {
int newCost = cost + graph[currNode][i];
if (newCost + bound < minCost) {
minCost = tspBranchAndBound(graph, visited, i, N, newCost, 
minCost);
}
}
}
visited[currNode] = false;
return minCost;
}
int main() {
int N;
cout << "Enter the number of cities: ";
cin >> N;
vector<vector<int>> graph(N, vector<int>(N));
vector<bool> visited(N, false);
cout << "Enter the adjacency matrix (INF for infinity):" << endl;
for (int i = 0; i < N; i++) {
for (int j = 0; j < N; j++) {
cin >> graph[i][j];
}
}
int minCost = INF;
int result = tspBranchAndBound(graph, visited, 0, N, 0, minCost);
cout << "Minimum cost for TSP: " << result << endl;
return 0;
}

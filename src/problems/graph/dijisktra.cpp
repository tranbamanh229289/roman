#include<bits/stdc++.h>

using namespace std;

const int N = 9;
const int INF = 1e9;
struct ComparePair{
  bool operator()(const pair<int, int>&a, const pair<int, int> & b) {
    return a.second > b.second;
  }
};

vector<pair<int, int>> adj[N];
vector<int> dist(N, INF);
priority_queue<pair<int, int>, vector<pair<int, int>>, ComparePair> pq;
int parent[N];


void solve(int source) {
  while(!pq.empty()) {
    pair<int, int> top = pq.top();
    int u = top.first;
    int d = top.second;
    pq.pop();

    if (d > dist[u]) continue;
    for (pair<int, int> edge: adj[u]) {
      int v = edge.first;
      int weight = edge.second;
      if (weight + dist[u] < dist[v]) {
        dist[v] = weight + dist[u];
        parent[v] = u;
        pq.push({v, dist[v]});
      }
    }
  }
}

vector<int> getPath(int source, int target) {
  vector<int> path;
  for(int v = target; v != source; v = parent[v]) {
    path.push_back(v);
  }
  path.push_back(source);
  reverse(path.begin(), path.end());
  return path;
}

void run() {
  adj[0] = {{1, 4}, {7, 8}};
  adj[1] = {{0, 4}, {2, 8}, {7, 11}};
  adj[2] = {{1, 8}, {3, 7}, {8, 2}, {5, 4}};
  adj[3] = {{2, 7}, {4, 9}, {5, 16}};
  adj[4] = {{5, 10}, {3, 9}};
  adj[5] = {{3, 14}, {2, 4}, {6, 2}};
  adj[6] = {{8, 6}, {5, 2}, {7, 1}};
  adj[7] = {{6, 1}, {8, 7}, {1, 11}, {0, 8}};
  adj[8] = {{7, 7}, {6, 6}, {2, 2}};

  int source = 0;
  int target = 8;
  dist[source] = 0;
  pq.push({source, dist[source]});
  solve(source);
  vector<int> path = getPath(source, target);

  for(int v: path) {
    cout<<v<<endl;
  }
}

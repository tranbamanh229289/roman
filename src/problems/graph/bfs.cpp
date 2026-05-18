#include<bits/stdc++.h>

using namespace std;

const int N = 9;
vector<int> adj[N];
queue<int> q;
bool visited[N];
int parent[N];

// using queue
void solve2(int k) {
  q.push(k);
  visited[k] = true;
  while(!q.empty()) {
    int top = q.front();
    q.pop();
    cout<<top<<endl;
    for(int v: adj[top]) {
      if (!visited[v]) {
        q.push(v);
        visited[v] = true;
        parent[v] = top;
      }
    }
  }
}

vector<int> getPath(int src, int dst) {
  vector<int> path;
  
  for(int v = dst; v!= src; v=parent[v]) {
    path.push_back(v);
  }
  path.push_back(src);
  reverse(path.begin(), path.end());
  return path;
}

void run() {
  adj[0] = {1, 7};
  adj[1] = {0, 2, 7};
  adj[2] = {1, 3, 8, 5};
  adj[3] = {2, 4, 5};
  adj[4] = {5, 3};
  adj[5] = {3, 2, 6};
  adj[6] = {8, 5, 7};
  adj[7] = {6, 8, 1, 0};
  adj[8] = {7, 6, 2};
  solve2(0);
  cout<<"==== path ===="<<endl;
  vector<int> path = getPath(2, 4);
  for(int v: path) {
    cout<<v<<endl;
  }
}
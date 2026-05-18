#include<bits/stdc++.h>

using namespace std;

const int N = 11;
vector<int> adj[N];
bool visited[N];
queue<int> q;

// using dfs
void dfs(int k) {
  visited[k] = true;
  cout<<k<<endl;
  for(int v: adj[k]) {
    if(!visited[v]) {
      dfs(v);
    }
  }
}

// using bfs
void bfs(int k) {
  q.push(k);
  visited[k] = true;
 
  while(!q.empty()) {
    int top = q.front();
    q.pop();

    for (int v: adj[top]) {
      if(!visited[v]) {
        q.push(v);
        visited[v] = true;
      }
    }
  }
 
}

int countConnected() {
  int components = 0;
  for(int i = 0; i < N; i++) {
    if(!visited[i]) {
      bfs(i);
      components ++;
    }
  }
  return components;
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
  adj[9] = {10};
  adj[10] = {9};

  int result = countConnected();
  cout<<result;
}
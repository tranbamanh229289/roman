#include<bits/stdc++.h>

using namespace std;

const int N = 9;
vector<int> adj[N];
int parent[N];
bool visited[N];


void dfs(int k) {
  visited[k] = true;
  
  for(int v: adj[k]) {
    if (!visited[v]) {
      dfs(k);
      parent[v] = k;
    }
  }
}

void solve(int k) {

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
}
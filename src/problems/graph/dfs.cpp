#include<bits/stdc++.h>

using namespace std;

const int N = 9;
vector<int> adj[N];
stack<int> s;
bool visited[N];
int parent[N];

void solve1(int k) {
  visited[k] = true;
  cout<< k << endl;
  for(int v: adj[k]) {
    if(!visited[v]) {
      parent[v] = k;
      solve1(v);
   
    } 
  }
  
}


// using stack
void solve2(int k) {
  s.push(k);
  visited[k] = true;
  while(!s.empty()) {
    int top = s.top();
    s.pop();
    cout<<top<<endl;
    for (int v: adj[top]) {
      if(!visited[v]) {
        s.push(v);
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

  vector<int> path = getPath(2, 4);
  cout<<"======= path ========"<<endl;
  for(int v: path) {
    cout<<v<<endl;
  }
} 






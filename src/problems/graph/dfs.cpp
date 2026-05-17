#include <iostream>
#include<vector>
#include<stack>

using namespace std;

vector<vector<int>> adj(9);
vector<bool> check(9);
stack<int> s;

void solve1(int k) {
  check[k] = true;
  cout<< k << endl;
  for(int v: adj[k]) {
    if(!check[v]) {
      solve1(v);
    } 
  }
  
}


// using stack
void solve2(int k) {
  s.push(k);
  check[k] = true;
  while(!s.empty()) {
    int top = s.top();
    s.pop();
    cout<<top<<endl;
    for (int v: adj[top]) {
      if(!check[v]) {
        s.push(v);
        check[v] = true;
      }
    } 
  }
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
} 






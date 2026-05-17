#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<vector<pair<int, int>>> adj(9);

void solve(int k) {

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
  solve(0);
}

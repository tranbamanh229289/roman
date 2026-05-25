#include<bits/stdc++.h>

using namespace std;

struct Node {
  int val;
  Node(int val): val(val){}
};

void change(Node *node) {
  node -> val = 30;
}
void change(int* x){
  int b = 30;
  x = &b;
}

void run() {
  Node *a = new Node(20);
  change(a);
  cout<<a->val;
  int b = 40;
  change(&b);
  cout<<b;
}
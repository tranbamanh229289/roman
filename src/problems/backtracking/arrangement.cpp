#include<iostream>

using namespace std;

constexpr int n = 5;
constexpr int m = 3;
int A[n+1];
bool mark[n+1];

void println(int size) {
  for(int i = 1; i <= size; i ++) {
    cout<<A[i];
  }
  cout<<endl;
}

void binary(int k) {
  for (int i = 0; i <= 1; i ++) {
    A[k] = i;
    if (k == n) {
      println(n);
    } else binary(k+1);
  }
}

void arrangement(int k) {
  for (int i = 1; i <= n ; i ++) {
    if (!mark[i]) {
      A[k] = i;
      mark[i] = true;
      if (k == n) {
        println(n);
      } else arrangement(k+1);
      mark[i] = false;
    }
  }
}

void combination(int k) {
  for (int i = A[k-1] + 1; i <= n-m+k; i ++) {
    A[k] = i;
    if (k == m) {
      println(m);
    } else combination(k+1);
  }
}

void run() {
  combination(1);
}
#include<bits/stdc++.h>

using namespace std;

vector<int> arr;

void solve(int l, int r) {
  if(l >= r) {
    return;
  }

  int i = l;
  int p = r;

  for(int j = l; j < r; j ++) {
    if (arr[j] < arr[p]) {
      swap(arr[i], arr[j]);
      i ++;
    }
  }
  swap(arr[i], arr[p]);
  solve(l, i - 1);
  solve(i + 1, r);
}


void run() {
  arr = {6, 1, 2, 5, 9, 3, 4, 7, 10, 8};
  solve(0, arr.size()-1);
  for(int v: arr) {
    cout<<v<<endl;
  }
}
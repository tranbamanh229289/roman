#include<bits/stdc++.h>

using namespace std;

vector<int> arr;

void merge(int l, int mid, int r) {
  int k = 0;
  int i = l; 
  int j = mid + 1;
  vector<int> v;
  while(i <= mid && j <= r) {
    if (arr[i] < arr[j]) {
      v.push_back(arr[i]);
      i++;
    } else {
      v.push_back(arr[j]);
      j++;
    };
  }

  while(i <= mid) {
    v.push_back(arr[i]) ;
    i ++;
  }

  while(j <= r) {
    v.push_back(arr[j]);
    j ++;
  }

  // override to arr in range(l, r);
  for(int k = 0; k < v.size(); k ++) {
    arr[l + k] = v[k];
  }
}
void mergeSort(int l, int r) {
  if (l >= r) {
    return;
  }
  int mid = (l+r)/2;
  mergeSort(l, mid);
  mergeSort(mid + 1, r);
  merge(l, mid, r);
}

void run() {
  arr = {6, 1, 2, 5, 9, 3, 4, 7, 10, 8};
  mergeSort(0, arr.size() - 1);
  for(int v: arr) {
    cout<<v<<endl;
  }
}
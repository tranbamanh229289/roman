#include<bits/stdc++.h>

using namespace std;

double solve1(vector<int>& nums1, vector<int>& nums2) {
  int i = 0;
  int j = 0;
  int k = 0;
  int m = nums1.size();
  int n = nums2.size();
  int sum[m+n];

  while (i < m && j < n) {
    if(nums1[i] < nums2[j]) {
        sum[k] = nums1[i];
        i ++ ;     
    } else if(nums1[i] >= nums2[j]) {
        sum[k] = nums2[j];

        j ++;
    }
    k ++;
  }

  if (i < m) {
    for(int t = i; t < m; t ++) {
      sum[k] = nums1[t];
      k++;
    }
  }

  if (j < n) {
    for (int t = j; t < n; t ++) {
      sum[k] = nums2[t];
      k++;
    }
  }


  int d = m + n;
  double result = 0;
  if (d % 2 == 0) {
    result = double(sum[d/2-1] + sum[d/2])/2;
       
  } else {
      result = double(sum[d/2]);
  }
  return result;

}
void run() {
  vector<int>nums1 = {1, 2, 3, 4, 5};
  vector<int>nums2 = {6,7,8,9,10,11,12,13,14,15,16,17};
  double result = solve1(nums1, nums2);
  cout<<result;
}
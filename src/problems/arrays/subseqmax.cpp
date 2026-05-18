#include<bits/stdc++.h>

using namespace std;

int solve(vector<int>& nums) {
  int max = nums[0];
  int current = nums[0];

  for(int i = 1; i < nums.size(); i ++) {
    current = current + nums[i] >= nums[i] ? current + nums[i] : nums[i]; 
    max = max > current ? max : current;
  }
  return max;
}

void run(){
  vector<int> a = {-2, 11, -4, 13, -5, 2};
  int result = solve(a);
  cout<<result;
}
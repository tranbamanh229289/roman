#include<bits/stdc++.h>

using namespace std;

void solve1(vector<int>& nums) {
  vector<int> temp(nums.size());
  int j = 0;
  for (int i = 0; i < nums.size(); i++) {
    if (nums[i] != 0) {
      temp[j] = nums[i];
      nums[i] = 0;
      nums[j] = temp[j];
      j ++;
    }
  }
}

void solve2(vector<int> &nums) {
  int index = 0;
  int temp = 0;
  for (int i = 0; i< nums.size(); i++) {
    if(nums[i] != 0) {
      temp = nums[i];
      nums[i] = 0;
      nums[index] = temp;

      index ++;
    }
  }
}

void run() {
  vector<int> a = {0, 1, 0, 3, 12};
  solve1(a);
  for(int i : a) {
    cout<<i<<endl;
  }

}
#include<iostream>
#include<vector>

using namespace std;

int binarySearch(vector<int>& nums, int l, int r, int target) {
  if (l <= r) {
    int mid = (r + l)/2;

    if (nums[mid] == target) {
      return mid;
    }

    if (nums[mid] < target) {
      return binarySearch(nums, mid+1, r, target);
    }
  
    if (nums[mid] > target) {
      return binarySearch(nums, l, mid-1, target);
    }

  } 
  return l;
}

int solve1(vector<int>& nums, int target) {
  return binarySearch(nums, 0, nums.size()-1, target);
}


void run(){
  vector<int> nums = {1, 3, 5, 6};
  int target = 7;
  int result = solve1(nums, target);
  cout<<result;
}
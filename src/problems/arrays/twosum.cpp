#include<bits/stdc++.h>

using namespace std;


vector<int> solve1(vector<int> nums, int target) {
  for(int i = 0; i < nums.size(); i ++) {
    int temp = target - nums[i];
    for(int j = i+1; j < nums.size(); j ++) {
      if (nums[j] == temp) {
        return {i, j};
      }
    }
  }
  return {0, 0};
}

vector<int> solve2(vector<int> nums, int target) {
  unordered_map<int, int> map;

  for (int i = 0; i < nums.size(); i ++) {
    int first = nums[i];
    int second = target - first;

    if (map.find(second) != map.end()) {
      if (i > map[second]) {
        return {map[second], i};
      } else return {i, map[second]};
    }

    map[first] = i;
  }
  return {0, 0};
}

void run() {
    vector<int> input = {3,2,4};

    vector<int> output = solve2(input, 6);

    for(int i: output) {
      cout<<i;
    }
   
}
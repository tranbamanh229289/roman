#include<bits/stdc++.h>

using namespace std;

int solve1(string s) {
  int max_len = 0;
  int current = 0;
  int start = 0;

  unordered_map<char, int> map;

  for(int i = 0; i < s.size(); i ++) {
    char c = s[i];

    if(map.find(c) != map.end() && start <= map[c]) {
      start = map[c]+1;
    }
    map[c] = i;
    max_len = max(max_len, i - start + 1);
  }
  return max_len;
}

void run() {
  string s = "vdvdf";
  int count = solve1(s);
  cout<<count;
}
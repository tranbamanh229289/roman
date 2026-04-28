#include<iostream>
#include<unordered_map>

using namespace std;

int solve1(string s) {
  int max = 0;
  int current = 0;
  int start = 0;

unordered_map<char, int> map;

  for(int i = 0; i < s.size(); i ++) {
    char c = s[i];

    if(map.find(c) != map.end() && start <= map[c]) {
      current = current - map[c] + start;
      start = map[c]+1;
    } else {
      current += 1;
    }
    max= max > current ? max: current;
  
    map[c] = i;
  }
  return max;
}

void run() {
  string s = "vdvdf";
  int count = solve1(s);
  cout<<count;
}
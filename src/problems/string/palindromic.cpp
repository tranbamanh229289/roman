#include<iostream>
#include<stack>
#include<unordered_map>

using namespace std;

bool checkPalindrome(string s, int i, int j) {
  if(i >= j) return true; 
  return s[i] == s[j] && checkPalindrome(s, i+1, j-1);
}

void run() {
  string s = "aba";
  bool result = checkPalindrome(s, 0, s.size() - 1);
  cout<<result<<endl;
}
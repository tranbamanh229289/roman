#include<bits/stdc++.h>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(): val(0), next(nullptr){};
  ListNode(int x): val(x), next(nullptr){};
  ListNode(int x, ListNode *next): val(x), next(next){};
};
  
 
ListNode* solve1(ListNode* l1, ListNode* l2) {
  ListNode* result = new ListNode{0};
  ListNode* ptr = result;
 
  int rem = 0;
  while(l1 != nullptr || l2 != nullptr || rem != 0) {
    int temp = 0;
    if(l1 != nullptr) {
      temp += l1->val;
      l1 = l1->next;
    }
    
    if(l2 != nullptr) {
      temp += l2->val;
      l2 = l2->next;
    }

    ptr->next = new ListNode((temp + rem)%10);
    ptr = ptr-> next;
    rem = temp+rem >= 10 ? 1 : 0;
  }

  return result->next;
}

void run() {
  ListNode *p1 = new ListNode{2};
  p1-> next = new ListNode{4};
  p1->next->next = new ListNode{3};

  ListNode *p2 = new ListNode{5};
  p2->next = new ListNode{6};
  p2->next->next = new ListNode{4};

  ListNode* result = solve1(p1, p2);

  while (result != nullptr) {
    cout << result->val <<endl;
    result = result->next;
  }
  
}
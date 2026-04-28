#include<iostream>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(): val(0), next(nullptr){};
  ListNode(int x): val(x), next(nullptr){};
  ListNode(int x, ListNode *next): val(x), next(next){};
};

  ListNode* reverseList(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* current = head;
    while(current != nullptr) {
      ListNode* next = current -> next;
      current->next = prev;
      prev = current;
      current = next;
    }
    return prev;
  }

void run() {
  ListNode *p1 = new ListNode{2};
  p1-> next = new ListNode{4};
  p1->next->next = new ListNode{3};
  ListNode* ptr = reverseList(p1);

  while(ptr->next != nullptr) {
    cout<<ptr->val<<endl;
    ptr = ptr->next;
  }
}
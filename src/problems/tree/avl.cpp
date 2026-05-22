#include<bits/stdc++.h>

using namespace std;

struct Node {
  int val;
  Node *l, *r;
  Node(int val): val(val), l(nullptr), r(nullptr){}
};

class AVL {
  private:
    Node *root;
    
    bool _existed(Node* node, int val) {
      if (!node) return false;
      if (node->val == val) return true;
      if (val > node->val) return _existed(node->r, val);
      else if (val < node->val) return _existed(node->l, val);
      return false;
    }

    Node* _insert(Node* node, int val) {
      if (!node) {
        return new Node(val);
      }
      if (val == node->val) {

      }
      
      if (val < node->val) node->l = _insert(node->l, val);
      else if(val > node->val) node ->r = _insert(node->r, val);
      
      return node;
    }

    Node* _remove(Node* node, int val) {

    }

    void _preOrder(Node *node) {
      cout<<node->val<<", ";

      if (node->l) {
        _preOrder(node->l);
      }
      if(node->r) {
        _preOrder(node->r);
      }
    }

    void _inOrder(Node *node) {
      if (node->l) {
        _inOrder(node->l);
      }

      cout<<node->val<<",";

      if(node->r) {
        _inOrder(node->r);
      }
    }

    void _postOrder(Node * node) {
      if (node->l) {
        _postOrder(node->l);
      }
      if (node->r) {
        _postOrder(node->r);
      }
      
      cout<<node->val<<", ";
    }
    
  public:
    AVL() {
      root = nullptr;
    }
    AVL(int val) {
      root = new Node(val);
    }
    AVL(vector<int> arr) {
      root = new Node(arr[0]);
      for(int i = 1; i < arr.size(); i++) {
        _insert(root, arr[i]);
      }
    }

    void insert(int val) {
      _insert(root, val);
    }

    void remove(int val) {
      _remove(root, val);
    }

    bool existed(int val) {
      return _existed(root, val);
    }

    void preOrder() {
      return _preOrder(root);
    }
    void inOrder() {
      return _inOrder(root);
    }
    void postOrder() {
      return _postOrder(root);
    }
};

void run(){
}
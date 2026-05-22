#include<bits/stdc++.h>

using namespace std;

struct Node {
  int val;
  Node *r, *l;
  Node(int val): val(val), r(nullptr), l(nullptr) {}
};

vector<int> arr(9);

class BST {
  private:
    Node* root;

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

    bool _existed(Node *node, int val) {
      if (!node) return false;
      if(node-> val == val) return true;

      if (val < node->val) {
        return _existed(node->l, val);
      } else if (val > node->val) {
        return _existed(node->r, val);
      }
      return false;
    }

    Node* _insert(Node* node, int val) {
      if (!node) {
        return new Node(val);
      }
      if (val < node->val) {
        node->l = _insert(node->l, val);
      } else if (val > node->val) {
        node->r = _insert(node->r, val);
      } 
      return node;
    }

    Node* _remove(Node* node, int val) {
      if (!node) {
        return nullptr;
      }

      if (val < node->val) {
        node -> l = _remove(node->l, val);
      } else if(val > node->val) {
        node -> r = _remove(node->r, val);
      } else {
        if (!node->r) {
          Node* temp = node->l;
          delete node;
          return temp;
        }

        if (!node->l) {
          Node * temp = node->r;
          delete node;
          return temp;
        }

        else {
          int val = _getMinium(node->r);
          node->val = val;
          node->r = _remove(node->r, val);
        }
      }
      return node;
    }

    int _getMinium(Node* node) {
      while (node->l != nullptr) {
        node = node->l;
      }
      return node->val;
    }

    int _getMaximum(Node* node) {
     while (node->r != nullptr) {
      node = node->r;
     }
     return node->val;
    }
   

  public:
    BST(){
      root = nullptr;
    }

    BST(int val){
      root = new Node(val);
    }

    BST(vector<int> arr) {
      Node *root = new Node(arr[0]);
      for(int i = 1; i < arr.size(); i++) {
        _insert(root, arr[i]);
      }
    }

    bool existed(int val) {
      return _existed(root, val);
    }

    void insert(int val) {
      _insert(root, val);
    }

    void remove(int val) {
      _remove(root, val);
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

void run() {
  arr = {8,3,10,1,6,4,7,14,13};

  BST bst = BST();
  for(int i: arr){
    bst.insert(i);
  }
  bst.postOrder();
  bst.remove(3);
  cout<<endl;
  bst.postOrder();
}








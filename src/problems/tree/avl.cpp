#include<bits/stdc++.h>

using namespace std;

struct Node {
  int val, height;
  Node *l, *r;
  Node(int val): val(val), height(1), l(nullptr), r(nullptr){}
};

vector<int> arr(9);

class AVL {
  private:
    Node *root = nullptr;
    
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
      
      if (val < node->val) node->l = _insert(node->l, val);
      else if (val > node->val) node ->r = _insert(node->r, val);
      
      return _balance(node);
    }

    Node* _remove(Node* node, int val) {
      if (!node) {
        return nullptr;
      }

      if (val < node->val) node -> l = _remove(node->l, val);
      else if(val > node->val) node -> r = _remove(node->r, val);
      else {
        if (!node->l) {
          Node* temp = node->r;
          delete(node);
          return temp;
        }

        if (!node->r) {
          Node* temp = node->l;
          delete(node);
          return temp;
        }

        else {
          int val = findMin(node->r);
          node->val = val;
          node->r = _remove(node->r, val);
        }
      }

      return _balance(node);
    }

    int findMin(Node* node) {
      while(node->l) {
        node = node->l;
      };
      return node->val;
    }

    int findMax(Node * node) {
      while(node->r) {
        node = node->r;
      };
      return node->val;
    }

    Node* _balance(Node* node) {
      node->height = 1 + max(_height(node->l), _height(node->r));
      int bf = _height(node->l) - _height(node->r);

      if (bf > 1) {
        if (_height(node->l->l) - _height(node->l->r) < 0) {
          node->l = _leftRotate(node->l);
        } 
        node = _rightRotate(node);
        
      } else if (bf < -1) {
        if (_height(node->r->l) - _height(node->r->r) > 0) {
          node->r = _rightRotate(node->r);
        }
        node = _leftRotate(node);
      }

      return node;
    }

    int _height(Node* node) {
      return node ? node->height : 0;
    }

    Node* _leftRotate(Node *x) {
      Node* y = x->r;
      Node* T2 = y->l;
      y->l = x;
      x->r = T2;
      x->height = 1 + max(_height(x->l), _height(x->r));
      y->height = 1 + max(_height(y->l), _height(y->r));
      return y;
    }

    Node* _rightRotate(Node *x) {
      Node* y = x->l;
      Node* T2 = y->r;
      y->r = x;
      x->l = T2;
      x->height = 1 + max(_height(x->l), _height(x->r));
      y->height = 1 + max(_height(y->l), _height(y->r));
      return y;
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
      for(int val: arr) {
        root = _insert(root, val);
      }
    }

    void insert(int val) {
      root = _insert(root, val);
    }

    void remove(int val) {
      root = _remove(root, val);
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
  arr = {8,3,10,1,6,4,7,14,13};
  AVL avl = AVL(arr);
  avl.preOrder();
  avl.remove(13);
  cout<<endl;
  avl.preOrder();
}
#include <stdio.h>
#include <cstring>
template <typename T>
class Tree;

template <typename T>
class Node{
  friend class Tree<T>;
  private:
  public:
    T data;
    Node* left;
    Node* right;
    Node(T data=0, Node* left=NULL, Node* right=NULL):data(data), left(left), right(right){}
};

template <typename T>
class Tree{
  private:
  public:
    Node<T> *root;
    Tree(){
      root = NULL;
    }
    void insert_start(T data){
      insert(root, data);
    }
    void insert(Node<T>*&current, T data){
      if(current==NULL) current = new Node<T>(data);
      else if(data < current->data){
        insert(current->left, data);
      }
      else{
        insert(current->right, data);
      }
    }
    void preorder(){
      preorder_rt(root);
      printf("\n");
    }
    void preorder_rt(Node<T> *&current){
      if(current==NULL) return;
      printf("%d ", current->data);
      preorder_rt(current->left);
      preorder_rt(current->right);
    }
};

int n, m;
Tree<int> trees[52];


template <typename T>
bool same(Node<T>*& rt1, Node<T>*& rt2){
  if(rt1==NULL&&rt2==NULL) return true;
  else if(rt1==NULL || rt2==NULL) return false;
  else{
    return same(rt1->left, rt2->left) && same(rt1->right, rt2->right);
  }
}

template <typename T>
bool same_tree(Tree<T> &t1, Tree<T> &t2){
  return same(t1.root, t2.root);
}

int types[51];

int parent(int x){
  if(types[x]==-1) return x;
  else return parent(types[x]);
}

int check(int x){
  for(int i=0;i<x;i++){
    if(types[i]==-1){
      if(same_tree(trees[i], trees[x])){
        types[x] = i;
        return 0;
      }
    }
  }
  return 1;
}

int main(){
  scanf("%d %d", &n, &m);
  memset(types, -1, sizeof(types));
  int ans = 0;
  for(int i=0;i<n;i++){
    trees[i] = Tree<int>();
    for(int j=0;j<m;j++){
      int num;
      scanf("%d", &num);
      trees[i].insert_start(num);
    }
    //trees[i].preorder();
    ans += check(i);
  }
  printf("%d\n", ans);
}

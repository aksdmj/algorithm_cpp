#include <stdio.h>
#include <vector>
#include <algorithm>

#define MAX 1000050000
using namespace std;

typedef long long ll;

int n;

ll h[100100];


int init(vector<ll> &tree, int node, int start, int end){
  //printf("init %d-%d:%d\n", start, end, node);
  if(start==end) return tree[node] = start;
  else{
    int idx_l = init(tree, node*2, start, (start+end)/2);
    int idx_r = init(tree, node*2+1, (start+end)/2+1, end);
    return tree[node] = h[idx_l] < h[idx_r]? idx_l : idx_r;
  }
}

int query(vector<ll> &tree, int node, int start, int end, int left, int right){
  if(left > end || right < start){
    return -1;
  }
  if(left <=start && end<= right){
    return tree[node];
  }
  int idx_l = query(tree, node*2, start, (start+end)/2, left, right);
  int idx_r = query(tree, node*2+1, (start+end)/2+1, end, left, right);
  ll lvalue = idx_l==-1? MAX : h[idx_l];
  ll rvalue = idx_r==-1? MAX : h[idx_r];
  return lvalue < rvalue? idx_l : idx_r;
}

ll go(vector<ll> &tree, int left, int right){
  if(left==right) return h[left];
  int smallest_idx = query(tree, 1, 0, n-1, left, right);
  //printf("go %d-%d / %d\n", left, right, smallest_idx);
  ll ret = h[smallest_idx] * (right-left+1);
  if(smallest_idx>left) ret = max(ret, go(tree, left, smallest_idx-1));
  if(smallest_idx<right) ret= max(ret, go(tree, smallest_idx+1, right));
  return ret;
}


int main(){
  while(true){
    scanf("%d", &n);
    if(n==0) return 0;
    for(int i=0;i<n;i++){
      scanf("%lld", &h[i]);
    }
    vector<ll> rt(4*n+1);
    rt[0] = MAX;
    init(rt, 1, 0, n-1);
    printf("%lld\n", go(rt, 0, n-1));
  }

}

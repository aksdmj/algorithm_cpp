#include <stdio.h>


int heap[100100];
int size = 0;

int lc(int p){
  return 2*p+1;
}
int rc(int p){
  return 2*p+2;
}
int parent(int c){
  if(c==0) return -1;
  return (c-1)/2;
}
void swap(int i1, int i2){
  int temp = heap[i1];
  heap[i1] = heap[i2];
  heap[i2] = temp;
}

void sift_up(int pos){
  if(pos==0) return;
  if(heap[parent(pos)] < heap[pos]){
    swap(pos, parent(pos));
    sift_up(parent(pos));
  }
}

void sift_down(int pos){
  if(lc(pos)>=size) return;
  int next_pos = lc(pos);
  if(rc(pos)>=size){
    next_pos = lc(pos);
  }
  else {
    next_pos = heap[lc(pos)]>heap[rc(pos)]? lc(pos):rc(pos);
  }
  if(heap[next_pos] > heap[pos]){
    swap(next_pos, pos);
    sift_down(next_pos);
  }
}

void push(int x){
  heap[size++] = x;
  sift_up(size-1);
}

int pop(){
  if(size==0) return 0;
  int ans = heap[0];
  heap[0] = heap[--size];
  sift_down(0);
  return ans;
}



int n;
int main(){
  scanf("%d", &n);
  while(n--){
    int com;
    scanf("%d",&com);
    if(com==0) printf("%d\n", pop());
    else push(com);
  }
}

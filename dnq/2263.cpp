#include <stdio.h>

int n;
int inord[100100];
int postord[100100];

void go(int is, int ie, int ps, int pe){
  if(is > ie || ps > pe) return;
  int root = postord[pe];
  printf("%d ", root);
  int idxroot;
  for(int i=is;i<=ie;i++){
    if(root==inord[i]){
      idxroot=i;
      break;
    }
  }
  //printf("%d %d %d %d %d\n", is, ie, ps, pe, idxroot);
  go(is, idxroot-1, ps, ps+(idxroot-1-is));
  go(idxroot+1, ie, ps+(idxroot-is), pe-1);
}

int main(){
  scanf("%d", &n);
  for(int i=0;i<n;i++){
    scanf("%d", &inord[i]);
  }

  for(int i=0;i<n;i++){
    scanf("%d", &postord[i]);
  }
  int is =0, ie = n-1, ps=0, pe=n-1;
  go(is, ie, ps, pe);
}

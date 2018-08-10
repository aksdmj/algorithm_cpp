#include <stdio.h>
#include <cstring>

int n;


int go(int x, int base, int tgt){
  if(x==1){
    printf("%d %d\n",base, tgt);
    return 1;
  }
  int ret =0;
  int new_target = 6-base-tgt;
  ret += go(x-1, base, new_target);
  printf("%d %d\n", base, tgt);
  ret +=1;
  ret += go(x-1, new_target, tgt);
  return ret;
}

int go_nop(int x, int base, int tgt){
  if(x==1){
    return 1;
  }
  int ret =0;
  int new_target = 6-base-tgt;
  ret += go_nop(x-1, base, new_target);
  ret +=1;
  ret += go_nop(x-1, new_target, tgt);
  return ret;
}

int main(){
  scanf("%d", &n);
  printf("%d\n", go_nop(n, 1, 3));
  go(n,1,3);
}

#include <stdio.h>

int e, s, m;

int main(){
  scanf("%d %d %d", &e, &s, &m);
  int n = s;
  while(n%15!=e%15 || n%19!=m%19){
    n+=28;
  }
  printf("%d\n", n);
}

#include <stdio.h>
#include <cstring>

int n;
bool arr[6600][6600];
void solve(int s, int x, int y){
  if(s==1){
    arr[x][y] = true;
    return;
  }
  int ns = s/3;
  solve(ns, x, y);
  solve(ns, x, y+ns);
  solve(ns, x, y+(ns*2));
  solve(ns, x+ns, y);
  solve(ns, x+ns, y+(ns*2));
  solve(ns, x+(ns*2), y);
  solve(ns, x+(ns*2), y+ns);
  solve(ns, x+(ns*2), y+(ns*2));
}

int main(){
  memset(arr, false , sizeof(arr));
  scanf("%d", &n);
  solve(n, 0, 0);
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      if(arr[i][j]) printf("*");
      else printf(" ");
    }
    printf("\n");
  }
}

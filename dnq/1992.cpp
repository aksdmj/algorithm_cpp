#include <stdio.h>


int n;
int arr[100][100];

void go(int size, int x, int y){
  int base = arr[x][y];
  for(int i=0;i<size;i++){
    for(int j=0;j<size;j++){
      if(base!=arr[x+i][y+j]){
        int ns = size/2;
        printf("(");
        go(ns, x, y);
        go(ns, x, y+ns);
        go(ns, x+ns, y);
        go(ns, x+ns, y+ns);
        printf(")");
        return;
      }
    }
  }
  printf("%d",base);
}

int main(){
  scanf("%d", &n);
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      scanf("%1d",&arr[i][j]);
    }
  }
  go(n,0,0);
}

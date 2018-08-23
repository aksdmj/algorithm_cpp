#include <stdio.h>
#include <cstring>


int n;
bool arr[8000][8000];

void go(int y, int x, int s){
  if(s==3){
    arr[y][x] = true;
    arr[y+1][x-1] = true;
    arr[y+1][x+1] = true;
    for(int i=x-2;i<=x+2;i++){
      arr[y+2][i] = true;
    }
    return;
  }
  // top
  go(y, x, s/2);
  // bottom
  int ny = y + s/2;
  // left
  go(ny, x - s/2, s/2);
  go(ny, x + s/2, s/2);
  return;
}

int main(){
  memset(arr, false, sizeof(arr));
  scanf("%d",&n);
  go(0, n-1, n);
  for(int i=0;i<n;i++){
    for(int j=0;j<2*n-1;j++){
      if(arr[i][j])printf("*");
      else printf(" ");
    }
    printf("\n");
  }
}

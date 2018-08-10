#include <stdio.h>

int n;

int arr[2200][2200];
int ans[3];

void go(int s, int lx, int uy){
  int base = arr[lx][uy];
  for(int i=0;i<s;i++){
    for(int j=0;j<s;j++){
      if(arr[lx+i][uy+j] != base){
       // printf("%d %d %d failed\n", s, lx, uy);
        int ns = s/3;
        for(int k=0; k<3;k++){
          for(int l=0;l<3;l++){
            go(ns, lx+k*ns, uy+l*ns);
          }
        }
        return;
      }
    }
  }
  if(base==-1) ans[0]++;
  else if (base==0) ans[1]++;
  else ans[2] ++;
  //printf("%d %d %d success\n", s, lx, uy);
  return;
}

int main(){
  scanf("%d", &n);
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      scanf("%d", &arr[i][j]);
    }
  }
  ans[0] = 0;
  ans[1] = 0;
  ans[2] = 0;
  go(n, 0, 0);
  for(int i=0;i<3;i++){
    printf("%d\n", ans[i]);
  }


}

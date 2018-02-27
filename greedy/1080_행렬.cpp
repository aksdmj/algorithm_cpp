#include <stdio.h>

int n, m;
int a[52][52];
int b[52][52];

void pmtx(){
  printf("print....\n");
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      printf("%d ", a[i][j]);
    }
    printf("\n");
  }

}

int main(){
  scanf("%d %d", &n,&m);
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      scanf("%1d", &a[i][j]);
    }
  }
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      scanf("%1d", &b[i][j]);
    }
  }
  int ans =0;
  for(int i=0;i<n-2;i++){
    for(int j=0;j<m-2;j++){
      if(a[i][j] != b[i][j]){
        ans ++;
        for(int r=0;r<3;r++){
          for(int d=0;d<3;d++){
            a[i+r][j+d] = (a[i+r][j+d] + 1)%2;
          }
        }
      }
    }
  }
  bool ok = true;
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      if(a[i][j] !=  b[i][j]) ok = false;
    }
  }
  if(!ok) printf("-1");
  else printf("%d",ans);
}


#include <stdio.h>
#include <cstring>
int m, n;

int b[510][510];
int dp[510][510];

int dy[4] = {0, 0, 1, -1};
int dx[4] = {1, -1, 0, 0};

int go(int y, int x){
  if(y==0&& x==0) return 1;
  int &ret = dp[y][x];
  if(ret!=-1)return ret;
  ret = 0;
  for(int i=0;i<4;i++){
    int py = y + dy[i];
    int px = x + dx[i];
    if(py<0 || px<0 || py>=m || px>=n)continue;
    if(b[py][px]<= b[y][x])continue;
    ret += go(py, px);
  }
  return ret;
}

int main(){
  scanf("%d %d", &m, &n);
  memset(dp,-1,sizeof(dp));
  for(int i=0;i<m;i++){
    for(int j=0;j<n;j++){
      scanf("%d", &b[i][j]);
    }
  }
  printf("%d\n", go(m-1,n-1));


}

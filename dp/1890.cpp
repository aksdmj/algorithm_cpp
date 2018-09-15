#include <stdio.h>

typedef long long ll;
int n;
ll board[110][110];
ll ans[110][110];

int main(){
  scanf("%d", &n);
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      scanf("%d", &board[i][j]);
    }
  }
  ans[0][0] = 1;
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      if(board[i][j]==0) continue;
      int ny = i + board[i][j];
      int nx = j + board[i][j];
      if(ny<n) ans[ny][j] += ans[i][j];
      if(nx<n) ans[i][nx] += ans[i][j];
    }
  }
  printf("%lld\n", ans[n-1][n-1]);
}

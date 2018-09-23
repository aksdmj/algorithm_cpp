#include <stdio.h>
#include <cstring>
#include <algorithm>
using namespace std;
int n, s, m;
int v[110];

int dp[110][1010];

int main(){
  memset(dp, -1, sizeof(dp));
  scanf("%d %d %d", &n, &s, &m);
  v[0] = 0;
  dp[0][s] = 1;
  for(int i=1;i<=n;i++){
    scanf("%d", &v[i]);

    for(int j=0;j<=m;j++){
      if(dp[i-1][j] != -1){
        int nx1 = j + v[i];
        int nx2 = j - v[i];
        if(nx1>=0 && nx1<=m){
          dp[i][nx1] = 1;
        }
        if(nx2>=0 && nx2<=m){
          dp[i][nx2] = 1;
        }
      }
    }
  }
  int ans = -1;
  for(int i=m;i>=0;i--){
    if(dp[n][i] == 1){
      ans = i;
      break;
    }
  }

  printf("%d\n", ans);

}

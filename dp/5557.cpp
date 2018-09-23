#include <stdio.h>
#include <cstring>
typedef long long ll;

int n;
int arr[110];
ll dp[110][30];

int main(){
  memset(dp, 0, sizeof(dp));
  scanf("%d", &n);
  for(int i=1;i<=n;i++){
    scanf("%d", &arr[i]);
  }
  dp[1][arr[1]] = 1;
  for(int i=2;i<n;i++){
    for(int j=0;j<=20;j++){
      if(dp[i-1][j] == 0) continue;
      int nx1 = j + arr[i];
      int nx2 = j - arr[i];
      if(nx1>=0 && nx1<=20) dp[i][nx1] += dp[i-1][j];
      if(nx2>=0 && nx2<=20) dp[i][nx2] += dp[i-1][j];
    }
  }
  printf("%lld\n", dp[n-1][arr[n]]);
}

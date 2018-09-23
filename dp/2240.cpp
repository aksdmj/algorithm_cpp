#include <stdio.h>
#include <algorithm>
using namespace std;

int t, w;
int arr[1010];
int dp[1010][33];
int main(){
  scanf("%d %d", &t, &w);
  for(int i=1;i<=t;i++){
    scanf("%d", &arr[i]);
  }

  dp[1][0] = arr[1]%2;
  dp[1][1] = (arr[1]+1)%2;
  int ans = 0;
  for(int i=2;i<=t;i++){
    for(int j=0;j<=i && j<=w;j++){
      if(j==0) dp[i][0] = dp[i-1][0] + (arr[i]%2);
      else{
        dp[i][j] = max(dp[i-1][j], dp[i-1][j-1])+(arr[i]+j)%2;
      }
      if(i==t) ans = max(ans, dp[i][j]);
    }
  }
  printf("%d\n", ans);
}

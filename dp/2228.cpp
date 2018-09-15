#include <stdio.h>
#include <cstring>
#include <algorithm>

#define MIN -100000000

using namespace std;

int n, m;
int arr[110];
int dp[110][60];
int dp2[110][60];

int main(){
  memset(dp,0,sizeof(dp));
  scanf("%d %d", &n, &m);
  for(int i=0;i<n;i++){
    scanf("%d", &arr[i]);
  }

  for(int i=0;i<n;i++){
    for(int j=0;j<=m;j++){
      if(j==0){
        dp[i][j] = 0;
        dp2[i][j] = 0;
        continue;
      }
      if(j > (i+1)/2){
        dp[i][j] = MIN;
        continue;
      }
      dp2[i][j] = max(dp2[i-1][j], dp[i-2][j-1]) + arr[i];
      dp[i][j] = max(dp2[i][j], dp[i-1][j]);
    }
  }
  printf("%d\n", dp[n-1][m]);

}

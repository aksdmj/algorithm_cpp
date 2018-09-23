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
  scanf("%d %d", &n, &m);
  for(int i=1;i<=n;i++){
    scanf("%d", &arr[i]);
  }

  for(int i=0;i<=n;i++){
    for(int j=0;j<=m;j++){
      dp[i][j] = MIN;
      dp2[i][j] = MIN;
    }
  }
  for(int i=0;i<=n;i++){
    for(int j=0;j<=m;j++){
      if(j==0){
        dp2[i][j] = 0;
        dp[i][j] = 0;
        continue;
      }
      if(j>(i+1)/2){
        continue;
      }
      if(i==1){
        dp2[i][j] = arr[i];
        dp[i][j] = arr[i];
      }
      dp2[i][j] = max(dp2[i-1][j], dp[i-2][j-1])+arr[i];
      dp[i][j] = max(dp2[i][j], dp[i-1][j]);
    }
  }
  printf("%d\n", dp[n][m]);

}

#include <stdio.h>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAX (1<<30)

int t, k;
int papers[505];
int psum[505];
int dp[505][505];
int segsum[505][505];


int main(){
  scanf("%d", &t);
  while(t--){
    memset(dp, -1, sizeof(dp));
    scanf("%d", &k);
    psum[0] = 0;
    for(int i=1;i<=k;i++){
      scanf("%d", &papers[i]);
      psum[i] = psum[i-1] + papers[i];
    }
    for(int i=1;i<=k;i++){
      for(int j=i;j<=k;j++){
        segsum[i][j] = psum[j] - psum[i-1];
      }
    }
    for(int s=1;s<=k;s++){
      dp[1][s] = 0;
    }
    for(int l=2;l<=k;l++){
      for(int s=1;s+l-1<=k;s++){
        dp[l][s] = MAX;
        int cost = segsum[s][s+l-1];
        for(int l2=1;l2<l;l2++){
          dp[l][s] = min(dp[l][s], dp[l2][s] + dp[l-l2][s+l2] + cost);
        }
      }
    }
    printf("%d\n", dp[k][1]);
  }

}

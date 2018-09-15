#include <stdio.h>
#include <utility>
#include <algorithm>
#include <cstring>

using namespace std;

#define MAX ((((1<<30)-1)<<1)+1)

typedef pair<int, int> mat;

int n;
int dp[505][505];
mat arr[505];


int main(){
  memset(dp, -1, sizeof(dp));
  scanf("%d", &n);
  for(int i=0;i<n;i++){
    scanf("%d %d", &arr[i].first, &arr[i].second);
  }
  for(int s=0;s<n;s++){
    dp[1][s] = 0;
  }
  for(int l=2;l<=n;l++){
    for(int s=0;s+l<=n;s++){
      dp[l][s] = MAX;
      int base_cost = arr[s].first * arr[s+l-1].second;
      for(int l2=1; l2<l; l2++){
        dp[l][s] = min(dp[l][s], dp[l2][s] + dp[l-l2][s+l2] + base_cost * arr[s+l2].first);
      }
    }
  }
  printf("%d\n", dp[n][0]);
}

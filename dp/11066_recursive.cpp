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

int go(int l, int s){
  if(l==1) return 0;
  int &ret = dp[l][s];
  if(ret!=-1)return ret;
  ret = MAX;
  int cost = segsum[s][s+l-1];
  for(int l2=1;l2<l;l2++){
    ret = min(ret, go(l2, s) + go(l-l2, s+l2) + cost);
  }

  return ret;
}

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
    printf("%d\n", go(k, 1));

  }

}

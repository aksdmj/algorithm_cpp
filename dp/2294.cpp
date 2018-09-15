#include <stdio.h>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAX 100000

int n,k;

int coins[110];
int ans[10100];
int main(){
  scanf("%d %d", &n, &k);
  for(int i=0;i<n;i++){
    scanf("%d", &coins[i]);
  }
  sort(coins, coins+n);
  for(int i=1;i<=k;i++){
    ans[i] = MAX;
  }
  ans[0] = 0;
  for(int i=0; i<=k;i++){
    for(int j=0;j<n;j++){
      int ny = i + coins[j];
      if(ny<=k){
        ans[ny] = min(ans[ny], ans[i]+1);
      }
    }
  }
  if(ans[k]==MAX) printf("-1\n");
  else printf("%d\n", ans[k]);
}

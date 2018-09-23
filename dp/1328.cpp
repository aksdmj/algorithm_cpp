#include <stdio.h>
#include <cstring>
#define MOD 1000000007

typedef long long ll;

int nn, l, r;

ll fact[101];
ll nck[101][101];
ll dp[101][101];


void precalc(){
  fact[0] = 1;
  for(int i=1;i<nn;i++){
    fact[i] = (fact[i-1] * i)%MOD;
  }
}

ll nCk(int n, int k){
  if(n==0) return 1;
  if(k==0||n==k) return 1;
  ll &ret = nck[n][k];
  if(ret!=-1) return ret;
  return ret = (nCk(n-1, k-1) + nCk(n-1, k))%MOD;
}

ll go2(int n, int x){
  if(x==0 && n==0) return 1;
  if(x==0 && n!=0) return 0;
  if(x>n) return 0;
  ll &ret = dp[n][x];
  if(ret!=-1) return ret;
  ret = 0;
  for(int i=0;i<n;i++){
    ret = (ret + ((nCk(n-1, i) * go2(i, x-1))%MOD)*fact[n-i-1])%MOD;
  }
  return ret;
}


ll go(int n, int l, int r){
  int ans = 0;
  for(int i=0;i<n;i++){
    ans = (ans + ((nCk(n-1, i) * go2(i,l-1))%MOD *go2(n-i-1, r-1))%MOD)%MOD;
  }
  return ans;
}

int main(){
  memset(dp, -1, sizeof(dp));
  memset(nck, -1, sizeof(dp));
  scanf("%d %d %d", &nn, &l, &r);
  precalc();
  printf("%lld\n", go(nn, l, r));

}

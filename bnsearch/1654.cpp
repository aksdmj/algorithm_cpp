#include <stdio.h>
#include <algorithm>
using namespace std;

#define INF 10000000

typedef long long ll;

ll k , n;
ll lans[10100];

ll calc(ll len){
  if(len ==0 ) return INF;
  ll ans = 0;
  for(int i=0;i<k;i++){
    ans += lans[i] / len;
  }
  return ans;
}

int main(){
  scanf("%lld %lld", &k, &n);
  ll max_len = 0;
  for(int i=0;i<k;i++){
    scanf("%lld", &lans[i]);
    max_len = max(max_len, lans[i]);
  }

  ll l = 0;
  ll r = max_len;
  ll ret = 0;
  while(l<=r){
    ll m = (l+r)/2;
    ll ans = calc(m);
    //printf("%d %d %d - %d\n", l, m , r, ans);
    if(ans<n){
      r = m-1;
    }
    else {
      l = m+1;
      ret = max(ret, m);
    }
  }
  printf("%lld\n", ret);

}


#include <stdio.h>
#include <algorithm>
using namespace std;
typedef long long ll;
ll n, m;
ll times[10100];

ll calc(long long t){
  ll ans = 0;
  for(int i=0;i<m;i++){
    ans +=  t/ times[i];
    if(t % times[i]) ans++;
  }
  return ans;
}

int main(){
  scanf("%lld %lld", &n, &m);
  ll max_t = 0;
  for(int i=0;i<m;i++){
    scanf("%lld", &times[i]);
    max_t = max(max_t, times[i]);
  }

  ll l = 0;
  ll r = n * max_t;
  ll ans = 0;
  while(l<=r){
    ll m = (l+r)/2;
    ll cand = calc(m);
    // 최대한 작게 구하기
    if (cand >= n){
      r = m-1;
      ans = m;
    }
    else {
      l = m +1;
    }
  }

  ans --;
  ll cnt = 0;
  for(int i=0;i<m;i++){
    cnt += ans/times[i];
    if(ans%times[i]) cnt ++;
  }

  ll over = n - cnt;

  int i;
  for(i=0;i<m;i++){
    if((ans) % times[i]) continue;
    if(over) over --;
    if(!over){
      printf("%d\n", i+1);
      return 0;
    }
  }

}

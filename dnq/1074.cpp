#include <stdio.h>

typedef long long ll;

ll n, r, c;
ll go(ll s, ll y, ll x){
  if(s==1){
    return 0;
  }
  ll ns = s/2;
  if(x + ns > c){
    if (y + ns > r){
      return go(ns, y, x);
    }
    else {
      return go(ns, y+ns, x) + (ns*ns)*2;
    }
  }
  else{
    if(y+ns>r){
      return go(ns,y,x+ns) + (ns*ns);
    }
    else{
      return go(ns,y+ns,x+ns) + (ns*ns)*3;
    }
  }
}

ll pow(ll n){
  if(n==1) return 2;
  else return 2* pow(n-1);
}

int main(){
  scanf("%lld %lld %lld", &n, &r, &c);
  printf("%lld", go(pow(n), 0, 0));
}


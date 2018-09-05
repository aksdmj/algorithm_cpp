#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;

ll n, c;
vector<ll> houses;

ll solve(ll dist){
  ll last = houses[0];
  ll ans = 1ll;
  for(int i=1;i<n;i++){
    if(houses[i] - last >= dist){
      last = houses[i];
      ans++;
    }
  }
  return ans;
}

int main(){
  scanf("%lld %lld", &n, &c);
  for(int i=0;i<n;i++){
    ll house;
    scanf("%lld", &house);
    houses.push_back(house);
  }

  sort(houses.begin(), houses.end());

  ll l = 0;
  ll r = *(houses.end()-1);
  ll ans = 0;
  while(l<=r){
    ll m = (l+r)/2;
    ll cand = solve(m);
    //printf("%lld %lld %lld %lld\n", l, m ,r, cand);
    if(cand>=c){
      l = m+1;
      ans = m;
    }
    else{
      r = m-1;
    }
  }
  printf("%lld\n",ans);
}

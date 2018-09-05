#include <stdio.h>
#include <vector>
#include <algorithm>

typedef long long ll;

using namespace std;
ll n, m;
vector<ll> trees;

ll solve(ll mid){
  ll ans = 0;
  for(int i=0;i<n;i++){
    ans += max(0ll, trees[i]-mid);
  }
  return ans;
}

int main(){
  scanf("%lld %lld", &n, &m);
  ll maxlen = 0;
  for(int i=0;i<n;i++){
    ll tree;
    scanf("%lld", &tree);
    maxlen= max(maxlen, tree);
    trees.push_back(tree);
  }

  ll l = 0;
  ll r = maxlen;
  ll ans = 0;

  while(l<=r){
    ll mid = (l+r)/2;
    ll m_cand = solve(mid);
    //printf("%lld %lld %lld - %lld\n", l, mid, r, m_cand);
    if(m_cand < m){
      r = mid-1;
    }
    else{
      l = mid +1;
      ans = max(ans, mid);
    }
  }
  printf("%lld\n", ans);

}

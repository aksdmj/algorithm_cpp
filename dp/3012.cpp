#include <stdio.h>
#include <string>
#include <cstring>
using namespace std;

#define MOD 100000

typedef long long ll;
int n;
char st[220];

ll dp[202][202];
bool over[202][202];

bool over_fn(int s, int e){
  if(s>e) return false;
  else return over[s][e];
}

ll ok(int s, int e){
  if(st[s] == ')' || st[s] == ']' || st[s] == '}') return 0;
  if(st[e] == '(' || st[e] == '[' || st[e] == '{') return 0;
  if(st[s] == '?' && st[e] == '?') return 3;
  if(st[s] == '?' || st[e] == '?') return 1;
  if(st[s] == '(' && st[e] == ')') return 1;
  if(st[s] == '{' && st[e] == '}') return 1;
  if(st[s] == '[' && st[e] == ']') return 1;
  return 0;
}

ll go(int s, int e){
  if(e-s % 2 ==0) return 0;
  if(s>e) return 1;
  if(e-s ==1) return ok(s,e);
  if(st[s] == ')' || st[s] == '}' || st[s] ==']') return 0;
  if((s-e) % 2 == 0) return 0;
  ll &ret = dp[s][e];
  if(ret!=-1) return ret;
  ret = 0;
  ll temp = ok(s,e);
  if(temp){
    ret= temp * go(s+1, e-1);
    if(ret>=MOD || over_fn(s+1,e-1)){
      over[s][e] = true;
      ret%=MOD;
    }
  }
  for(int i=e-2;i>=s+1;i-=2){
    int temp = ok(s,i);
    if(!temp) continue;
    ll a = go(s+1, i-1);
    if(a==0 && !over_fn(s+1, i-1)) continue;
    ll b = go(i+1, e);
    if(b==0 && !over_fn(i+1, e)) continue;
    ll now= temp * a * b;
    ret += now;
    if(over_fn(s+1, i-1) || over_fn(i+1,e) || ret>=MOD){
      over[s][e] = true;
      ret%=MOD;
    }
  }
  return ret%MOD;
}

int main(){
  memset(over, false, sizeof(over));
  memset(dp, -1, sizeof(dp));
  scanf("%d", &n);
  scanf("%s", st);
  ll ans = go(0, n-1);
  if(over_fn(0, n-1)) printf("%05lld", ans);
  else printf("%lld", ans);

}

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
  ret = ok(s, e) * go(s+1, e-1);
  for(int i=e-2;i>=s+1;i-=2){
    int temp = ok(s,i);
    ret += ok(s, i) * go(s+1, i-1) * go(i+1, e);
  }
  return ret%MOD;
}

int main(){
  memset(over, false, sizeof(over));
  memset(dp, -1, sizeof(dp));
  scanf("%d", &n);
  scanf("%s", st);
  printf("%lld\n", go(0, n-1));

}

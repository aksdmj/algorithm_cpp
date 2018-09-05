#include <stdio.h>
#include <bitset>
using namespace std;
typedef long long ll;

int n;
int type;

ll fact[20];
bitset<20> bs;

void fact_set(){
  ll now = 1;
  for(int i=0;i<n;i++){
    fact[i] = now;
    now *= (i+1);
  }
}

int find_xth_num(ll x){
  ll now = 0;
  for(int i=0;i<n;i++){
    if(!bs.test(i)){
      if(now==x) return i;
      now++;
    }
  }
}

int find_ord(int x){
  int temp = 0;
  for(int i=0;i<x;i++){
    if(bs.test(i))continue;
    else temp++;
  }
  return temp;
}

int main(){
  bs.reset();
  scanf("%d", &n);

  fact_set();

  scanf("%d", &type);
  if(type==1){
    ll ord;
    scanf("%lld", &ord);
    ord--;
    for(int i=0;i<n;i++){
      ll temp = ord / fact[n-i-1];
      int num = find_xth_num(temp);
      printf("%d ", num+1);
      bs.set(num);
      ord %= fact[n-i-1];
    }
    printf("\n");
  }
  else if(type==2){
    ll ans = 1;
    for(int i=0;i<n;i++){
      int temp;
      scanf("%d", &temp);
      int ord = find_ord(temp-1);
      bs.set(temp-1);
      ans += fact[n-i-1]*ord;
    }
    printf("%lld\n", ans);
  }
}

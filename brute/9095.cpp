#include <stdio.h>
#include <cstring>
int t, n;

int ans[11];

int go(int x){
  int &ret = ans[x];
  if(ret!=-1)return ret;
  if(x==0) return ret=1;
  if(x==1) return ret=1;
  if(x==2) return ret=2;
  ret = go(x-1) + go(x-2) + go(x-3);
  return ret;
}

int main(){
  memset(ans, -1, sizeof(ans));
  scanf("%d", &t);
  while(t--){
    scanf("%d",&n);
    printf("%d\n", go(n));
  }
}

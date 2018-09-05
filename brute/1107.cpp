#include <stdio.h>
#include <set>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

int n, m;

bool brk[10];

bool avail(int x){
  if(x==0) return brk[0] ? false:true;
  while(x!=0){
    if(brk[x%10]) return false;
    x/=10;
  }
  return true;
}

int main(){
  memset(brk, false, sizeof(false));
  scanf("%d %d", &n, &m);
  for(int i=0;i<m;i++){
    int temp;
    scanf("%d", &temp);
    brk[temp] = true;
  }
  int ans = n>100? n-100 : 100-n;
  for(int i=0;i<=1000000;i++){
    if(avail(i)){
      int cnt = 1;
      int temp = i;
      while(temp/10){
        cnt++;
        temp/=10;
      }
      int diff = n>i? n-i : i-n;
      ans = min(ans, cnt +diff);
    }
  }
  printf("%d\n", ans);
}

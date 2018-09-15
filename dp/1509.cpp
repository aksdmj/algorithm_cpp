#include <stdio.h>
#include <cstring>
#include <algorithm>
using namespace std;

int isPal[2501][2501];
int cache[2501];
char c[2501];

int checkPal(int s, int e){
  if(s>e) return 1;
  int &ret = isPal[s][e];
  if(ret!=-1)return ret;

  if(c[s] != c[e]) return 0;
  if(s==e){
    if(c[s] == c[e]){
      return ret = 1;
    }
    else return ret = 0;
  }
  return ret = checkPal(s+1, e-1);
}

int main(){
  memset(isPal, -1, sizeof(isPal));
  scanf("%s", c);
  int n;
  n= strlen(c);
  for(int i=0;i<n;i++){
    for(int j=0;j<=i;j++){
      checkPal(j, i);
    }
  }
  for(int i=0;i<n;i++){
    cache[i] = i+1;
    for(int j=0;j<=i;j++){
      if(checkPal(j, i)) cache[i] = min(cache[i], cache[j-1] + 1);
    }
  }
  printf("%d\n", cache[n-1]);
}

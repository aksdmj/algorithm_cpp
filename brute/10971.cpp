#include <stdio.h>
#include <algorithm>
#include <cstring>
using namespace std;

#define MAX 1000000*10;

int n;
int ct[11][11];
int cache[11][(1<<10)+1];

int go(int now, int visited){
  int full = (1<<n) -1;
  if((visited & full) == (full-1)){
    if(!ct[now][0]) {
        return MAX;
    }
    else {
        return ct[now][0];
    }
  }
  int &ret = cache[now][visited];
  if(ret!=-1) return ret;
  ret = MAX;
  for(int i=1;i<n;i++){
    if(!(visited & (1<<i)) && ct[now][i]){
      ret = min(ret, go(i, visited|(1<<i)) + ct[now][i]);
    }
  }
  return ret;
}

int main(){
  memset(cache, -1, sizeof(cache));
  scanf("%d", &n);
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      scanf("%d", &ct[i][j]);
    }
  }
  printf("%d\n", go(0, 0));

}

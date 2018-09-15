#include <stdio.h>
#include <cstring>

int n,m;

int arr[2010];
int isPal[2010][2010];

int go(int s, int e){
  if(s>=e) return 1;
  int &ret = isPal[s][e];
  if(ret!=-1) return ret;
  if(arr[s]!=arr[e]) return ret = 0;
  return ret = go(s+1, e-1);
}


int main(){
  memset(isPal, -1, sizeof(isPal));
  scanf("%d", &n);
  for(int i=1;i<=n;i++){
    scanf("%d", &arr[i]);
  }
  scanf("%d", &m);

  int s, e;
  for(int i=0;i<m;i++){
    scanf("%d %d", &s, &e);
    go(s,e)? printf("1\n"):printf("0\n");
  }

}


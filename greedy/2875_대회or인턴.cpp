#include <stdio.h>
#include <algorithm>
using namespace std;

int m,n,k;

int main(){
  scanf("%d %d %d",&m, &n, &k);
  while(k>0){
    if(m>2*n){
      k -= m-2*n;
      m = 2*n;
    }
    else if (2*n>m){
      k -= (n - m/2);
      n = m/2;
    }
    else {
      k -= 3;
      n--;
      m-=2;
    }
  }
  printf("%d\n", min(m/2, n));
}

#include <stdio.h>

int n;
int dp1[66];

int main(){
  scanf("%d", &n);

  dp1[0] = 1;
  dp1[1] = 1;
  for(int i=2;i<=n;i++){
    dp1[i] = dp1[i-1] * 1 + dp1[i-2] * 2;
  }
  int ans = dp1[n];
  int symm;
  if(n==1) symm = 1;
  else if(n==2) symm = 3;
  else symm = (n%2)? dp1[n/2]: dp1[n/2]+dp1[(n/2)-1]*2;
  printf("%d\n", (ans-symm)/2 + symm);
}

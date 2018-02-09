#include <stdio.h>

int n, k;

int arr[11];

int main(){
  scanf("%d %d",&n,&k);
  arr[0] = 1;
  for(int i=1;i<=n;i++){
    scanf("%d",&arr[i]);
  }
  int ans = 0;
  for(int i=n;i>0;i--){
    ans += (k/arr[i]);
    k = k % arr[i];
  }
  printf("%d\n",ans+k);
}

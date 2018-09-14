#include <stdio.h>

int t, n;

int gcd(int a, int b){
  if(a<b) return gcd(b,a);
  if(b==0) return a;
  return gcd(b, a%b);
}

int main(){
  scanf("%d", &t);
  while(t--){
    scanf("%d", &n);
    int arr[110];
    long long ans = 0;
    for(int i=0;i<n;i++){
      scanf("%d", &arr[i]);
      for(int j=0;j<i;j++){
        ans+=gcd(arr[i], arr[j]);
      }
    }
    printf("%lld\n", ans);
  }
}

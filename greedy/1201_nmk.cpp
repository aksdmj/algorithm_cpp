#include <stdio.h>
#include <algorithm>

using namespace std;

int n, m, k;
int arr[550];

int main(){
  scanf("%d %d %d",&n, &m, &k);
  if(m+k-1>n || m*k<n){
    printf("-1");
    return 0;
  }
  for(int i=0;i<n;i++){
    arr[i] = i+1;
  }
  int frt = 0;
  int bck;
  for(int i=0;i<m;i++){
    bck = min(frt + k , n-m+i+1);
    reverse(arr+frt, arr+bck);
    frt = bck;
  }
  for(int i=0;i<n;i++){
    printf("%d ", arr[i]);
  }
}

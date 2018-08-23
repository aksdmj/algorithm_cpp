#include <stdio.h>
#include <cstring>

int n;
int arr1[500500];
int arr2[500500];

typedef long long ll;

/*
void print_array(){
  for(int i=0;i<n;i++){
    printf("%d ", arr1[i]);
  }

    printf("\n====\n");
  for(int i=0;i<n;i++){
    printf("%d ", arr2[i]);
  }

    printf("\n====\n");
}
*/
ll merge_sort(int s, int e){
  if(s>=e)return 0;
  int m = s + (e-s)/2;
//  printf("%d %d %d\n", s, m, e);
  ll a1 = merge_sort(s, m);
  ll a2 = merge_sort(m+1, e);
  int i1=s, i2=m+1;
  int tok = s;
  ll ans = a1 + a2;
  while(i1<=m && i2<=e){
//    printf("arr1[%d]= %d arr2[%d] = %d \n", i1, arr1[i1], i2, arr1[i2]);
    if(arr1[i1]<=arr1[i2])arr2[tok++] = arr1[i1++];
    else {
      arr2[tok++] = arr1[i2++];
      ans += (ll)(m + 1 - i1);
//      printf("%d %d %d\n", s, m, e);
//      printf("add %lld\n", ll(m + 1 - i1));
    }
  }
  while(i1<=m) arr2[tok++] = arr1[i1++];
  while(i2<=e)arr2[tok++] =arr1[i2++];
  memcpy(arr1+s, arr2+s, sizeof(int)*(e-s+1));
  //printf("%d %d %d\n", s, m, e);
  //print_array();
  return ans;
}

int main(){
  scanf("%d",&n);
  for(int i=0;i<n;i++){
    scanf("%d",&arr1[i]);
  }
  printf("%lld", merge_sort(0, n-1));


}

#include <stdio.h>
#include <algorithm>
using namespace std;

int n, m;
int arr[500500];

int go(int x){
  auto er = equal_range(arr, arr+n, x);
  auto lb = er.first;
  auto ub = er.second;
  return ub-lb;
}

int main(){
  scanf("%d", &n);
  for(int i=0;i<n;i++){
    scanf("%d", &arr[i]);
  }
  sort(arr, arr+n);
  scanf("%d", &m);
  int temp;
  for(int i=0;i<m;i++){
    scanf("%d", &temp);
    printf("%d ", go(temp));
  }

}

#include <stdio.h>
#include <algorithm>

using namespace std;

int n, m;
int arr1[500500];


bool find(int x){
  int l = 0;
  int r = n-1;
  bool ok = false;
  while(l<=r){
    int m = (l+r)/2;
    if (arr1[m] > x) r = m-1;
    else if (arr1[m]<x) l = m+1;
    else {
      ok = true;
      break;
    }
  }
  return ok;
}

int main(){
  scanf("%d", &n);
  for(int i=0;i<n;i++){
    scanf("%d", &arr1[i]);
  }

  sort(arr1, arr1+n);

  scanf("%d", &m);
  for(int i=0;i<m;i++){
    int x;
    scanf("%d", &x);
    bool tok = find(x);
    if(tok){
      printf("1 ");
    }
    else{
      printf("0 ");
    }
  }


}


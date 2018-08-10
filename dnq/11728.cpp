#include <stdio.h>
#include <vector>
#include <algorithm>
int n, m;

int main(){
  scanf("%d %d", &n, &m);
  std::vector<int> v1(n);
  std::vector<int> v2(m);
  std::vector<int> v3;
  for(int i=0;i<n;i++){
    scanf("%d", &v1[i]);
  }
  for(int i=0;i<m;i++){
    scanf("%d", &v2[i]);
  }
  int idx1=0;
  int idx2=0;
  while(idx1+idx2 < n+m){
    if(idx1==n){
      printf("%d ", v2[idx2++]);
    }
    else if (idx2==m){
      printf("%d ",v1[idx1++]);
    }
    else if (v2[idx2] > v1[idx1]){
      printf("%d ",v1[idx1++]);
    }
    else{
      printf("%d ",v2[idx2++]);
    }
  }
}


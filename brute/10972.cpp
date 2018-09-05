#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int n;

int main(){
  scanf("%d", &n);
  vector<int> vt(n);
  for(int i=0;i<n;i++){
    scanf("%d",&vt[i]);
  }
  if(next_permutation(vt.begin(), vt.end())==false){
    printf("-1\n");
  }
  else{
    for(int i=0;i<n;i++){
      printf("%d ", vt[i]);
    }
    printf("\n");
  }
  return 0;
}

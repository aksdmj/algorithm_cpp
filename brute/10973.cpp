#include <stdio.h>
#include <algorithm>
using namespace std;

int n;

int vt[10010];

void swap(int a, int b){
  int temp = vt[a];
  vt[a] = vt[b];
  vt[b] = temp;
}

int cmp(const int &l, const int &r){
  return l>r;
}

int main(){
  scanf("%d", &n);
  for(int i=0;i<n;i++){
    scanf("%d",&vt[i]);
  }
  bool ok = false;
  int i;
  for(i=n-1;i>=1;i--){
    if(vt[i]<vt[i-1]){
      ok = true;
      int j;
      int swap_tgt = vt[i];
      int swap_tgt_idx = i;
      for(j=i;j<n;j++){
        if(vt[i-1] > vt[j] && vt[j] > swap_tgt){
          swap_tgt = vt[j];
          swap_tgt_idx = j;
        }
      }
      swap(swap_tgt_idx, i-1);
      sort(vt+i, vt+n, cmp);
      break;
    }
  }
  if(!ok){
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

#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int n;

vector<int> vt;

int abs(int x){
  return x>0? x: -x;
}

int calc(){
  int ans =0;
  for(int i=0;i<n-1;i++){
    ans += abs(vt[i]-vt[i+1]);
  }
  return ans;
}

int main(){
  scanf("%d",&n);
  for(int i=0;i<n;i++){
    int temp;
    scanf("%d",&temp);
    vt.push_back(temp);
  }
  sort(vt.begin(), vt.end());
  int ans = calc();
  while(next_permutation(vt.begin(), vt.end())!=false){
    ans = max(ans, calc());
  }
  printf("%d\n", ans);
}



#include <stdio.h>
#include <utility>
#include <algorithm>
using namespace std;


int n;
pair<int, int> arr[100010];


int main(){
  scanf("%d",&n);
  for(int i=0;i<n;i++){
    scanf("%d %d",&arr[i].first,&arr[i].second);
  }
  sort(arr, arr+n, [](const pair<int,int>& l, const pair<int,int>& r){
              return l.second==r.second? l.first<r.first : l.second< r.second;
          }
      );
  int ans = 0;
  int now = 0;
  for(int i=0;i<n;i++){
    if(now<=arr[i].first){
      ans++;
      now = arr[i].second;
    }
  }
  printf("%d\n",ans);
}

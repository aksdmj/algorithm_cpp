#include <stdio.h>
#include <cstring>
#include <utility>
#include <queue>
#include <algorithm>
using namespace std;
int abs(int x){
  return x>0? x:-x;
}

int n;
int arr[55];
int dp[55][255000];

int main(){
  memset(dp, 0, sizeof(dp));
  scanf("%d", &n);
  queue<pair<int, int>> q;
  for(int i=1;i<=n;i++){
    scanf("%d", &arr[i]);
  }
  q.push(make_pair(0,0));
  while(!q.empty()){
    pair<int, int> now = q.front();q.pop();
    //printf("%d %d, max= %d\n", now.first, now.second, dp[now.first][now.second]);
    int nx = now.first+1;
    if(nx>n) continue;
    int nd0 = now.second;
    int m0 = dp[now.first][now.second];
    dp[nx][nd0] = m0;
    q.push(make_pair(nx, nd0));

    int nd1 = abs(now.second + arr[nx]);
    int m1 = m0 + arr[nx];
    if(nd1 <=250000 && m1 > dp[nx][nd1]) {
      dp[nx][nd1] = m1;
      q.push(make_pair(nx, nd1));
    }

    int nd2 = abs(now.second - arr[nx]);
    int m2 = max(m0, m0-nd0+nd2);
    if(nd2 <=250000 && m2 > dp[nx][nd2]) {
      dp[nx][nd2] = m2;
      q.push(make_pair(nx, nd2));
    }
  }
  int ans = dp[n][0];
  if(ans==0) ans = -1;
  printf("%d\n", ans);
}

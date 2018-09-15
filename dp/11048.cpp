#include <stdio.h>
#include <algorithm>
using namespace std;

int n, m;

int arr[1010][1010];
int ans[1010][1010];

int dx[3] = {0, 1, 1};
int dy[3] = {1, 0, 1};


int main(){
  scanf("%d %d", &n, &m);
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      scanf("%d", &arr[i][j]);
      ans[i][j] = arr[i][j];
    }
  }
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      for(int k=0;k<3;k++){
        int ny = i + dy[k];
        int nx = j + dx[k];
        if(ny>n || nx>m) continue;
        ans[ny][nx] = max(ans[ny][nx], ans[i][j] + arr[ny][nx]);
      }
    }
  }

  printf("%d\n", ans[n][m]);
}

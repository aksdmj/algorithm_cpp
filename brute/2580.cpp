#include <stdio.h>


int arr[9][9];


bool possible(int y, int x, int n){
  for(int i=0;i<9;i++){
    if(arr[y][i] == n) return false;
    if(arr[i][x] == n) return false;
  }
  int ty = (y/3)*3, tx=(x/3)*3;
  for(int i=ty;i<ty+3;i++){
    for(int j=tx;j<tx+3;j++){
      if(arr[i][j] == n) return false;
    }
  }

  return true;
}


void solve(){
  static bool done = false;
  if(done) return;
  bool ok = true;
  int y=-1, x=-1;
  for(int i=0;i<9;i++){
    if(!ok) break;
    for(int j=0;j<9;j++){
      if(arr[i][j] ==0){
        y = i;
        x = j;
        ok = false;
        break;
      }
    }
  }
  if(ok){
    for(int i=0;i<9;i++){
      for(int j=0;j<9;j++){
        printf("%d ", arr[i][j]);
      }
      printf("\n");
    }
    done = true;
    return;
  }

  for(int i=1;i<=9;i++){
    if(possible(y, x, i)){
      arr[y][x] = i;
      solve();
      arr[y][x] = 0;
    }
  }
}

int main(){
  for(int i=0;i<9;i++){
    for(int j=0;j<9;j++){
      scanf("%d", &arr[i][j]);
    }
  }
  solve();


}

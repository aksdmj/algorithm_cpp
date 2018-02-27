#include <stdio.h>
#include <string>

using namespace std;

int r, c;

int arr[1010][1010];

int main(){
  scanf("%d %d",&r ,&c);
  for(int i=0;i<r;i++){
    for(int j=0;j<c;j++){
      scanf("%d", &arr[i][j]);
    }
  }


}

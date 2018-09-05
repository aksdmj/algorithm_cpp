#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int k;
int arr[15];

void print(vector<int> p){
  int plen = p.size();
  do{
    for(int i=0;i<plen;i++){
      if(!p[i]) printf("%d ", arr[i]);
    }
    printf("\n");
  }while(next_permutation(p.begin(), p.end()));
}



int main(){
  while(true){
    scanf("%d", &k);
    if(k==0) return 0;
    vector<int> p;
    for(int i=0;i<k;i++){
      i<6? p.push_back(0): p.push_back(1);
      scanf("%d",&arr[i]);
    }
    print(p);
    printf("\n");
  }
}

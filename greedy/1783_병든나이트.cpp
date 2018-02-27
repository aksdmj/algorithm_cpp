#include <stdio.h>
#include <algorithm>
using namespace std;

int n,m;

int main(){
  scanf("%d %d",&n, &m);
  int ans;
  if(n==1){
    ans = 1;
  }
  else if (n==2){
    if(m==1) ans = 1;
    else if (m==2) ans = 1;
    else if (m==3) ans = 2;
    else if (m==4) ans = 2;
    else if (m==5) ans = 3;
    else if (m==6) ans = 3;
    else ans = 4;
  }
  else{
    if(m<=4) ans = m;
    else if(m==5) ans = 4;
    else ans = m-2;
  }
  printf("%d\n",ans);

}



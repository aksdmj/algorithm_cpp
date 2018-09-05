#include <stdio.h>
#include <queue>
#include <cstring>
using namespace std;
int t;
int a, b;

bool isPrime[10100];
int ct[10100];

void prime(){

  for(int i=2;i<10000;i++){
    if(isPrime[i]){
      for(int j=2;i*j<10000;j++){
        isPrime[i*j] = false;
      }
    }
  }
}

int main(){
  memset(isPrime, true, sizeof(isPrime));
  isPrime[0] = false;
  isPrime[1] = false;
  prime();
  scanf("%d",&t);
  while(t--){
    scanf("%d %d", &a, &b);
    queue<int> q;
    memset(ct, -1, sizeof(ct));
    ct[a] = 0;
    q.push(a);
    bool ok = false;
    while(!q.empty()){
      if(ct[b]!=-1){
        ok = true;
        break;
      }
      int now = q.front(); q.pop();
      for(int i=1;i<10;i++){
        int nex = now%1000 + i*1000;
        if(isPrime[nex] && ct[nex]==-1){
          ct[nex] = ct[now] + 1;
          q.push(nex);
        }
      }
      for(int i=0;i<10;i++){
        int nex100 = (now/1000)*1000 + now%100 + i*100;
        if(isPrime[nex100] && ct[nex100]==-1){
          ct[nex100] = ct[now] + 1;
          q.push(nex100);
        }
        int nex10 = (now/100)*100 + now%10 + i*10;
        if(isPrime[nex10] && ct[nex10]==-1){
          ct[nex10] = ct[now] + 1;
          q.push(nex10);
        }
        int nex1 = (now/10)*10 + i;
        if(isPrime[nex1] && ct[nex1]==-1){
          ct[nex1] = ct[now] + 1;
          q.push(nex1);
        }
      }
    }
    if(ok)printf("%d\n", ct[b]);
    else printf("Impossible");

  }

}

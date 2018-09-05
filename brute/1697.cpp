#include <stdio.h>
#include <queue>
#include <cstring>
using namespace std;

int n, k;

int cost[100100];

int main(){
  memset(cost, -1, sizeof(cost));
  scanf("%d %d", &n, &k);
  queue<int> q;
  cost[n] = 0;
  q.push(n);
  while(!q.empty()){
    if(cost[k]!=-1) {
      printf("%d\n", cost[k]);
      return 0;
    }
    int now = q.front();q.pop();
    if(now>0 && cost[now-1]==-1){
      cost[now-1] = cost[now] + 1;
      q.push(now-1);
    }
    if(now<100000 && cost[now+1]==-1){
      cost[now+1] = cost[now] + 1;
      q.push(now+1);
    }
    if(now*2<=100000 && cost[now*2]==-1){
      cost[now*2] = cost[now] + 1;
      q.push(now*2);
    }
  }

}

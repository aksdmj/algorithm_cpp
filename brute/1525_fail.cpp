#include <stdio.h>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;


vector<int> vt;

int cost[370000];
int pow10[9];
int fact[9];

void pow(){
  pow10[0] = 1;
  fact[0] = 1;
  for(int i=1;i<=8;i++){
    pow10[i]= pow10[i-1]*10;
    fact[i] = fact[i-1]*i;
  }
}

int encode(int perm){
  int bit = 0;
  int ans = 0;
  for(int i=8;i>=0;i--){
    int now = perm/pow10[i];
    int ord = 0;
    for(int j=0;j<now;j++){
      if(!(bit & (1<<j))) ord ++;
    }
    ans += ord * fact[i];
    //printf("%d is in %dtih ord, %d is added, %d\n", now, ord, ord*fact[i], ans);
    bit = bit | (1<<now);
    perm -= now*pow10[i];
  }
  return ans;
}

int where0(int perm){
  int ans = 0;
  while(true){
    if(perm%10 == 0) return ans;
    ans++;
    perm/=10;
  }
}



int swap(int perm, int i, int j){
  int inum = (perm / pow10[i])%10;
  int jnum = (perm / pow10[j])%10;
  return perm + (jnum-inum)*pow10[i] + (inum-jnum)*pow10[j];
}


int main(){
  pow();
  memset(cost, -1, sizeof(cost));
  int temp;
  int num = 0;
  for(int i=0;i<9;i++){
    num*=10;
    scanf("%d",&temp);
    num+=temp;
  }
  queue<int> q;
  int end = encode(123456780);
  cost[encode(num)] = 0;
  q.push(num);
  while(!q.empty() && cost[end]==-1){
    int now = q.front(); q.pop();
    int wo = where0(now);
    int arr[4] = {wo-1, wo+1, wo+3, wo-3};
    for(int i=0;i<4;i++){
      if(arr[i]>=0 && arr[i]<9){
        int swapped = swap(now, arr[i], wo);
        int newperm_enocde = encode(swapped);
        if(cost[newperm_enocde] == -1){
          cost[newperm_enocde] = cost[encode(now)] + 1;
          q.push(swapped);
        }
      }
    }
  }

  printf("%d\n", cost[end]);
}

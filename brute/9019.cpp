#include <stdio.h>
#include <cstring>
#include <queue>
#include <stack>
using namespace std;

int t;
int a, b;
int prevN[10100];
int prevC[10100]; // start:0 D:1 S:2 L:3 R:4

int D(int x){
  return (2*x)% 10000;
}

int S(int x){
  return x==0? 9999: x-1;
}

int L(int x){
  return (x*10 + x/1000)%10000;
}

int R(int x){
  return (x/10) + (x%10)*1000;
}

char num2char(int x){
  if(x==1) return 'D';
  if(x==2) return 'S';
  if(x==3) return 'L';
  return 'R';
}

int main(){
  scanf("%d", &t);
  while(t--){
    scanf("%d %d", &a, &b);
    memset(prevC, -1, sizeof(prevC));
    memset(prevN, -1, sizeof(prevN));
    queue<int> q;
    prevN[a] = 0;
    prevC[a] = 0;
    q.push(a);
    while(!q.empty() && prevN[b]==-1){
      int now = q.front(); q.pop();
      int arr[4] = {D(now), S(now), L(now), R(now)};
      for(int i=0;i<4;i++){
        if(prevN[arr[i]] == -1){
          prevC[arr[i]] = i+1;
          prevN[arr[i]] = now;
          q.push(arr[i]);
        }
      }
    }
    stack<char> s;
    while(b!=a){
      s.push(num2char(prevC[b]));
      b = prevN[b];
    }
    while(!s.empty()){
      char c = s.top(); s.pop();
      printf("%c", c);
    }
    printf("\n");
  }
}

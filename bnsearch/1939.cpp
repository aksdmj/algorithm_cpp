#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

typedef long long ll;


int n, m;

vector< pair< int, ll > > bdgs[100100];

int from, to;

bool visited[100100];

bool bfs(ll cost){
  queue<int> q;
  q.push(from);
  visited[from] = true;

  while(!q.empty()){
    int now = q.front();q.pop();
    //printf("bfs -now:%d\n",now);
    if(now == to){
      return true;
    }
    for(int i=0;i<bdgs[now].size();i++){
      int next = bdgs[now][i].first;
      ll nextcw = bdgs[now][i].second;
      //printf("next=%d, nextcw=%lld\n", next, nextcw);
      if(!visited[next] && nextcw >= cost){
        visited[next] = true;
        q.push(next);
      }
    }
  }
  // bfs all, but not returned.
  return false;
}


int main(){
  scanf("%d %d", &n, &m);
  ll maxwl = 0;
  for(int i=0;i<m;i++){
    int f, t;
    ll wl;
    scanf("%d %d %lld", &f, &t, &wl);
    bdgs[f].push_back(make_pair(t, wl));
    bdgs[t].push_back(make_pair(f, wl));
    maxwl = max(maxwl, wl);
  }
  scanf("%d %d", &from, &to);

  ll l = 0;
  ll r = maxwl;
  ll ans = 0;
  while(l<=r){
    memset(visited, 0, sizeof(visited));
    ll m = (l+r)/2;
    bool ok = bfs(m);
    //printf("%lld %lld %lld %d\n", l, r, m, ok);
    if(ok){
      l = m +1;
      ans = m;
    }
    else{
      r = m -1;
    }
  }
  printf("%lld", ans);

}


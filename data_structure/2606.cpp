#include <stdio.h>
#include <cstring>
int n, m;

int parent[110];

int find(int a){
  if(parent[a]==-1) return a;
  else return parent[a] = find(parent[a]);
}

void merge(int a, int b){
  int parenta = find(a);
  int parentb = find(b);
  if(parenta!=parentb) parent[parentb] = parenta;
}

int check(int a, int b){
  return find(a)==find(b);
}

int main(){
  scanf("%d %d", &n, &m);
  memset(parent ,-1, sizeof(int)*(n+1));
  for(int i=0;i<m;i++){
    int a, b;
    scanf("%d %d", &a, &b);
    merge(a,b);
  }
  int ans = 0;
  for(int i=2;i<=n;i++){
    if(check(1, i)) ans++;
  }
  printf("%d", ans);
}

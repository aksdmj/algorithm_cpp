#include <stdio.h>
#include <cstring>
int n, m;

int parent[1000100];

int find_parent(int x){
  if(parent[x]==-1) return x;
  parent[x] = find_parent(parent[x]);
  return parent[x];
}

void merge(int a, int b){
  int parentb = find_parent(b);
  int parenta = find_parent(a);
  if(parenta!= parentb) parent[parenta] = parentb;
}

bool check(int a, int b){
  return find_parent(a) == find_parent(b);
}

int main(){
  scanf("%d %d", &n, &m);
  memset(parent, -1, sizeof(int)*(n+1));
  for(int i=0;i<m;i++){
    int command, a, b;
    scanf("%d %d %d", &command, &a, &b);
    if(command == 0){
      merge(a,b);
    }
    else{
      check(a,b)? printf("YES\n") : printf("NO\n");
    }
  }
}

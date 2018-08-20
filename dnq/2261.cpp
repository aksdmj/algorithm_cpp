#include <stdio.h>
#include <algorithm>
#include <utility>

#define INF 20000*20000*2+1
using namespace std;

typedef pair<int, int> point;

int n;
point ps[100100];

int sq(int a){
  return a*a;
}

int dist_sq(point p1, point p2){
  return sq(p1.first-p2.first) + sq(p1.second-p2.second);
}

bool cmp(const point &p1, const point &p2){
  return p1.first == p2.first? p1.second<p2.second : p1.first<p2.first;
}

int main(){
  scanf("%d", &n);
  for(int i=0;i<n;i++){
    scanf("%d %d", &ps[i].first, &ps[i].second);
  }


}

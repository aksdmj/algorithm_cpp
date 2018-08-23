#include <stdio.h>
#include <algorithm>
#include <utility>
#include <vector>
#include <set>
#define INF 20000*20000*2+1
using namespace std;

struct point{
  int x, y;
  point(int x, int y):x(x),y(y){}
  point(){}
  // basically sorted by y, then x(in set)
  bool operator <(const point &p) const{
      return y==p.y ? x<p.x : y<p.y;
  }
};

// sorted by x in vector
bool cmp(const point &l, const point &r){
  return l.x==r.x? l.y < r.y : l.x<r.x;
}

int sq(int a){
  return a*a;
}

int dist(point a, point b){
  return sq(a.x-b.x) + sq(a.y-b.y);
}


int solve(vector<point>::iterator it, int n){
  if(n<2) return INF;
  if(n==2) return dist(it[0], it[1]);
  if(n==3) return min({dist(it[0], it[1]), dist(it[0],it[2]), dist(it[1], it[2])});
  int line = (it[n/2 - 1].x + it[n/2].x)/2;
  int d = min(solve(it, n/2), solve(it+n/2, n-n/2));
  set<point> st;
  for(int i=n/2;i<n;i++){
    int dd = line - it[i].x;
    if(sq(dd) < d) st.insert(it[i]);
    else break;
  }
  for(int i=n/2-1;i>=0;i--){
    int dd = line - it[i].x;
    if(sq(dd) < d) st.insert(it[i]);
    else break;
  }
  printf("set info \n");
  for(auto it1 = st.begin(); it1 != st.end(); it1++){
      printf("%d ", (*it1).x);
  }
  printf("\n");

  for(auto it1 = st.begin(); it1 != st.end(); it1++){
    printf("it %d %d , yd =%d, d= %d \n", (*it1).x, (*(next(it1, 1))).x,sq((*(next(it1,1))).y - (*it).y),d) ;
    for(auto it2 = next(it1,1); it2!=st.end() && sq((*it2).y - (*it).y) < d; it2++){
      printf("it %d %d\n", (*it1).x, (*it2).x);
      d = min(d, dist(*it1, *it2));
    }
  }
  return d;
}

int nn;

vector<point> vt;

int main(){
  scanf("%d", &nn);
  int x, y;
  for(int i=0;i<nn;i++){
    scanf("%d %d", &x, &y);
    vt.push_back(point(x,y));
  }
  sort(vt.begin(), vt.end(), cmp);

  printf("%d\n", solve(vt.begin(), nn));
}



#include <stdio.h>
#include <algorithm>
#include <math.h>
using namespace std;
double x, y, c;

double cross(double a, double b, double m){
  return (a*b)/(a+b);
}

double solve(double m){
  double a = sqrt(x*x - m*m);
  double b = sqrt(y*y - m*m);
  return cross(a, b, m);
}

int main(){
  scanf("%lf %lf %lf", &x, &y, &c);
  double l = 0.0;
  double r = min(x, y);
  double m;
  while(r-l > 1e-6){
    m = (l+r)/2.0;
    double cand = solve(m);
    if(cand > c){
      l = m;
    }
    else{
      r = m;
    }
  }
  printf("%.3f", l);
}

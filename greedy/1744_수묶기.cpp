#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;

int n;

vector<ll> v1;
vector<ll> v2;

int main(){
  scanf("%d", &n);
  ll temp;
  ll ans = 0;
  for(int i=0;i<n;i++){
    scanf("%lld", &temp);
    if(temp==1)ans++;
    else if(temp>0)v1.push_back(temp);
    else v2.push_back(temp);
  }
  sort(v1.begin(), v1.end(), [](const ll& l, const ll& r){
          return l>r;
          });
  sort(v2.begin(),v2.end());
  for(int i=0;i+1<v1.size();i+=2){
    ans += v1[i] * v1[i+1];
  }
  if(v1.size()%2) ans += v1[v1.size()-1];


  for(int i=0;i+1<v2.size();i+=2){
    ans += v2[i] * v2[i+1];
  }
  if(v2.size()%2) ans += v2[v2.size()-1];
  printf("%lld\n",ans);
}

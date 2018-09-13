#include <stdio.h>
#include <stack>
#include <algorithm>
using namespace std;

typedef long long ll;

int n;
ll h[100100];

int main(){
  while(true){
    scanf("%d", &n);
    if(n==0) return 0;
    for(int i=0;i<n;i++){
      scanf("%lld", &h[i+1]);
    }
    h[0] = -1;
    stack<ll> st;
    ll ans = 0;
    st.push(0);
    for(int i=1;i<=n;i++){
      while(!st.empty() && h[i] < h[st.top()]){
        ll start = st.top();st.pop();
        if(!st.empty())ans = max(ans, (i-st.top()-1)*h[start]);
      }
      st.push(i);
    }
    while(!st.empty()){
      ll start = st.top();st.pop();
      if(!st.empty())ans = max(ans, (n+1-st.top()-1)*h[start]);
    }
    printf("%lld\n",ans);
  }

}

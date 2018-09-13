#include <stdio.h>
#include <stack>
#include <utility>
using namespace std;

typedef long long ll;

int n;
stack<pair<int,int>> st;
int heights[500500];

int main(){
  scanf("%d",&n);
  ll ans = 0ll;
  for(int i=0;i<n;i++){
    scanf("%d",&heights[i]);
    int tok = 1;
    while(!st.empty() && heights[st.top().first]<=heights[i]){
      if(heights[i] == heights[st.top().first]) tok += st.top().second;
      ans += st.top().second;st.pop();
    }
    if(!st.empty()){
      ans++;
    }
    st.push(make_pair(i, tok));
  }
  printf("%lld",ans);
}

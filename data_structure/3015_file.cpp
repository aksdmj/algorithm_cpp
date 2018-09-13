#include <stdio.h>
#include <stack>
#include <utility>
using namespace std;

typedef long long ll;

int n;
stack<pair<int,int>> st;
int heights[500500];

int main(){
  scanf("%d", &n);
  char buffer[200];
  sprintf(buffer, "3015_ts/patrik.in.%d",n);
  FILE *fp = fopen(buffer, "r");
  fscanf(fp,"%d",&n);
  ll ans = 0ll;
  for(int i=0;i<n;i++){
    fscanf(fp,"%d",&heights[i]);
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

#include <stdio.h>
#include <set>
#include <string>
using namespace std;


int n, m;
set<string> st;
set<string> st2;
int main(){
  scanf("%d %d", &n,&m);
  char buf[30];
  for(int i=0;i<n;i++){
    scanf("%s", buf);
    string s(buf);
    st.insert(s);
  }
  for(int i=0;i<m;i++){
    scanf("%s", buf);
    string s(buf);
    if(st.count(s))st2.insert(s);
  }
  printf("%d\n", (int)st2.size());
  for(auto x:st2)printf("%s\n", x.c_str());

}

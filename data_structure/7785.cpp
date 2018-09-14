#include <stdio.h>
#include <set>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int n;

bool cmp(const string& s1, const string& s2){
    return s1>s2;
}

set<string>  st;
int main(){
  char c1[50], c2[10];
  scanf("%d", &n);
  while(n--){
    scanf("%s %s", c1, c2);
    string s(c1);
    if(c2[0]=='e'){
      st.insert(s);
    }
    else{
      st.erase(s);
    }
  }
  for(auto it=st.rbegin(); it!=st.rend();it++){
    printf("%s\n", (*it).c_str());
  }
}


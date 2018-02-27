#include <stdio.h>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

string s;

int main(){
  cin>>s;
  int slen = s.length();
  bool ok = false;
  int sum = 0;
  for(int i=0;i<slen;i++){
    if(s[i] == '0'){
      ok = true;
    }
    sum += s[i] - '0';
  }
  if(!ok){
    printf("%d\n",-1);
  }
  else if(sum % 3 != 0){
    printf("%d\n",-1);
  }
  else{
    sort(s.begin(),s.end(),[](const char& l, const char& r){
            return l>r;
            });
    cout<<s<<endl;
  }
}


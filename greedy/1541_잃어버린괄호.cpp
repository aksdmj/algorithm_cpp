#include <iostream>
#include <string>
#include <algorithm>

using namespace std;


string s;

int string_handler(string s){
  int slen = s.length();
  string now = "";
  int ans = 0;
  for(int i=0;i<slen;i++){
    if(s[i] == '-' || s[i] == '+'){
      ans += stoi(now);
      now = "";
    }
    else{
      now += s[i];
    }
  }
  return ans + stoi(now);
}


int main(){
  cin>>s;
  int slen = s.length();
  int first_minus = -1;
  for(int i=0;i<slen;i++){
    if(s[i]=='-'){
      first_minus = i;
      break;
    }
  }
  if(first_minus==-1){
    printf("%d\n", string_handler(s));
    return 0;
  }
  string pp = s.substr(0,first_minus);
  string mm = s.substr(first_minus+1);
  printf("%d\n", string_handler(pp)- string_handler(mm));

}


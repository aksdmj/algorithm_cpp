#include <stdio.h>
#include <cstring>
#include <bitset>
using namespace std;

int m;

bitset<20> st;

int main(){
  scanf("%d", &m);
  for(int i=0;i<m;i++){
    char c[20];
    int n;
    scanf("%s %d", c, &n);
    if(!strcmp(c,"add"))st.set(n-1);
    else if(!strcmp(c,"remove"))st.reset(n-1);
    else if(!strcmp(c,"check"))st.test(n-1)?printf("1\n") : printf("0\n");
    else if(!strcmp(c,"toggle"))st.flip(n-1);
    else if(!strcmp(c,"all"))st.set();
    else st.reset();
  }
}

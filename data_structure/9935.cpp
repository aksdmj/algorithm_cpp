#include <stdio.h>
#include <cstring>


template <typename T>

struct stack{
  T *arr;
  int ptr;
  stack() :ptr(0){arr = new T[1000100];}
  ~stack(){delete arr;}
  void clear(){ptr=0;}
  void push(T t){arr[ptr++]=t;}
  void pop(){if(ptr>0)ptr--;}
  T top(){return arr[ptr-1];}
  bool empty(){return ptr==0;}
  int size(){return ptr;}
};


char s[1000100];
char a[40];

int main(){
  scanf("%s %s", s, a);
  stack<char> st;
  int s_idx = 0;
  int s_size = strlen(s);
  int a_size = strlen(a);
  for(s_idx=0;s_idx<s_size;s_idx++){
    st.push(s[s_idx]);
    if(st.size()>=a_size){
      bool ok = true;
      for(int i=0;i<a_size;i++){
        if(st.arr[st.size()-i-1]!=a[a_size-i-1]){
          ok = false;
          break;
        }
      }
      if(ok){
        for(int i=0;i<a_size;i++){
          st.pop();
        }
      }
    }
  }
  if(st.empty()){
    printf("FRULA");
    return 0;
  }
  for(int i=0;i<st.size();i++){
    printf("%c",st.arr[i]);
  }

}


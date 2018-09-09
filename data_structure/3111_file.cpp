#include <stdio.h>
#include <cstring>
#include <deque>
#include <algorithm>

using namespace std;

/*
template <typename T>
struct stack {
  T *arr;
  int ptr;
  stack() : ptr(0){arr = new T[300055];}
  ~stack(){delete arr;}
  void clear(){ptr =0;}
  void push(T data){arr[ptr++] = data;}
  void pop(){ptr--;}
  T top(){ return arr[ptr-1];}
  bool empty(){return ptr==0;}
  int size(){return ptr;}
};
*/
char A[26], T[300300];
int alen, tlen;
int main(){
  FILE *fp = fopen("3111_ts/cenzura.in.10", "r");
  fscanf(fp, "%s %s", A, T);
  fclose(fp);
  printf("A=%s\n", A);
  printf("T=%s\n", T);
  //scanf("%s %s", A, T);
  alen = strlen(A);
  tlen = strlen(T);
  int l = 0;
  int r = tlen-1;
  int flag = 1;
  deque<char> d1;
  deque<char> d2;
  while(l<=r){
    if(flag){
      d1.push_back(T[l]);
      if(d1.size()>=alen){
        bool find = true;
        for(int i=d1.size()-alen, t=0; i<d1.size(); i++,t++){
          if(d1[i] != A[t]){
            find = false;
            break;
          }
        }
        if(find){
          for(int i=0;i<alen;i++)d1.pop_back();
          flag ^=1;
        }
      }
      l++;
    }
    else{
      d2.push_front(T[r]);
      if(d2.size()>=alen){
        bool find = true;
        for(int i=0; i<alen; i++){
          if(d2[i] != A[i]){
            find = false;
            break;
          }
        }
        if(find){
          for(int i=0;i<alen;i++)d2.pop_front();
          flag ^=1;
        }
      }
      r--;
    }
  }
  bool ok = true;
  while(ok){
  if(d1.size()+d2.size()<alen) break;
  ok = false;
  for(int i=max(0,(int)d1.size()-alen);i<d1.size();i++){
    if(i+d2.size()<alen) break;
    bool smallok= true;
    for(int j=i;j<i+alen;j++){
      printf("i=%d,j=%d,d1s=%d,d2s=%d\n",i,j,d1.size(),d2.size());
      char now;
      if(j<d1.size()){now = d1[j];}
      else {now = d2[j - d1.size()];}
      printf("%c?=%c\n", now, A[j-i]);
      if(now != A[j-i]){
        smallok=false;
        break;
      }
    }
    if(smallok)ok = true;
    else continue;
    if(ok){
      for(int k=i;k<d1.size();k++)printf("%c",d1[k]);
      printf("\n");
      int x = alen;
      int d1size = d1.size();
      for(int k=i; k<d1size; k++, x--)d1.pop_back();
      printf("x=%d\n", x);
      for(int k=0; k<x;k++)d2.pop_front();
      break;
    }
  }
  }
  FILE *fp2;
  fp2 = fopen("3111_ts/out","w");
  for(auto c:d1)fprintf(fp2,"%c",c);
  for(auto c:d2)fprintf(fp2,"%c",c);

}


/*******************************************************
# File Name: a.cpp
# Author: Vincent
# Mail: mengxian0913@gmail.com
# Created Time: 五 11/17 14:58:04 2023
*********************************************************/

#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ff first
#define ss second
#define fastIO cin.tie(nullptr)->sync_with_stdio(false);
#define INF 0x7FFFFFFF
#define pb push_back
#define all(aa) aa.begin(),aa.end()
#define MOD (int)(1e9+7)
#define MAXN 100

typedef enum {op = 0, val = 1} mytype ;
struct Data {
  mytype type;
  int value;
  char oper;
};

struct mystack {
  Data a[MAXN];
  int top;
  bool IsEmpty();
  bool IsFull();
  void Push(Data da);
  Data Pop();
  Data Top();

  mystack() {
    top = -1;
  }
};

bool mystack::IsEmpty() {
  return (top == -1);
}

bool mystack::IsFull() {
  return (top == MAXN - 1);
}

void mystack::Push(Data da) {
  if(IsFull())
    puts("The STACK is full") ;
  else
    a[++top] = da;
}

Data mystack::Pop() {
  if(IsEmpty())
    puts("The STACK is empty") ;
  else
    return a[top--] ;
  return Data{ mytype::op, 0, '\0' };
}

Data mystack::Top() {
  if(IsEmpty())
    puts("The STACK is empty");
  else
    return a[top];
  return Data{ mytype::op, 0, '\0' };
}


int getPriority(char op) {
  return (op == '*' || op == '/');
}


void solve(string ss) {
  mystack st; // 堆疊用於處理運算符
  mystack res;
  string resProfix = ""; // The result of Profix.
  int cnt = 0, now = 0; // 括號計數
  bool haveNum = false;
  for(const char i : ss) {
    if(i >= '0' && i <= '9') {
      now *= 10;
      now += (int)(i - '0');
      haveNum = true;
      resProfix += i;
    }

    else {
      if(haveNum) {
        res.Push({val, now, '\0'});
        now = 0;
        haveNum = false;
      }
      if(i != ')') {
        if(i == '(') {
          cnt++;
        } 
        if(cnt <= 0) {
          if(!st.IsEmpty() && getPriority(st.Top().oper) >= getPriority(i)) {
            res.Push(st.Top());
            resProfix += st.Top().oper;
            st.Pop();
          }
        }
        st.Push({op, 0, i});
      }
    
      else {
        cnt--;
        while(st.Top().oper != '(' && !st.IsEmpty()) {
          res.Push(st.Top());
          resProfix += st.Top().oper;
          st.Pop();
        }
        st.Pop();
      }    
    }
  } 

  if(haveNum) res.Push({val, now, '\0'});
  while (!st.IsEmpty()) {
    res.Push(st.Top()); // 彈出堆疊中剩餘的運算符
    resProfix += st.Top().oper;
    st.Pop();
  }
  
  mystack Postfix;

  for(int i = 0; i <= res.top; i++) {
    if(res.a[i].type == op) {
      int a = Postfix.Pop().value;
      int b = Postfix.Pop().value;
      swap(a, b);
      if(res.a[i].oper == '+') {
        a += b;
      } else if(res.a[i].oper == '-'){
        a -= b;
      } else if(res.a[i].oper == '*'){
        a *= b;
      } else {
        a /= b;
      }
      Postfix.Push({val, a, '\0'});
    } else {
      Postfix.Push({val, res.a[i].value, '\0'});
    }
  }

  cout << resProfix << " result: " << Postfix.Top().value << "\n";
  return;
}


signed main(){
  fastIO
  ifstream ifs("./A.txt", ifstream::in);
  string ss;
  while(ifs >> ss) {
    solve(ss);
  }
  return 0;
}

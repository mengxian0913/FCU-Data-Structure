#include<bits/stdc++.h>
using namespace std;

#define int long long
#define MAXN 101

stack<int> st;

unordered_set<char> oper;

void solve() {
  // st.clear();
  int ans = 0, a = 0, b = 0;
  string ss;
  cin >> ss;
  for(int i = 0; i < ss.size(); i++) {

    if(oper.count(ss[i]) == false) {
      int now = (int)(ss[i] - '0');
      // cout << "now: " << now << "\n";
      st.push(now);
      continue;
    }

    a = st.top();
    st.pop();
    b = st.top();
    st.pop();

    
    if(ss[i] == '+') {
      a += b; 
    }

    else if(ss[i] == '-'){
      a -= b;
    }

    else if(ss[i] == '*') {
      a *= b;
    }

    else if(ss[i] == '/') {
      // cout << "divided: " << a << " " << b << "\n";
      a = b / a;
    }

    // cout << "current a: " << a << "\n";

    st.push(a);
    
  }

  cout << st.size() << "\n";
  cout << st.top() << "\n";
  
}

signed main() {
  oper.insert('+');
  oper.insert('-');
  oper.insert('*');
  oper.insert('/');
  solve();
  return 0;
}

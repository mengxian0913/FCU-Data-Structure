/*********************************************************
# File Name: a.cpp
# Author: Vincent
# Mail: mengxian0913@gmail.com
# Created Time: 五 10/27 13:14:02 2023
*********************************************************/

#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#include <time.h>
using namespace std;
#define int long long
#define ff first
#define ss second
#define fastIO cin.tie(nullptr)->sync_with_stdio(false);
#define INF 0x7FFFFFFF
#define pb push_back
#define all(aa) aa.begin(),aa.end()
#define MOD (int)(1e9+7)
#define MAXN (int)(1e2 + 10)

struct LongInt {
  int MyInt[MAXN];
  bool IsPositive;
  LongInt(); //利用亂數產生一個長度小於 19 的值
  LongInt(int); //指定一個長度小於 19 的值
  LongInt(const char*);
 
  void Zero(); //將本身的陣列初始為 0
  void Show(); //顯示陣列
  int Compare(LongInt); //比較本身跟長整數 b 之間何者較大，若大於 b 則回傳 1，反之，則回傳-1，若一樣大則回傳 0 
  
  bool operator > (LongInt);
  bool operator < (LongInt);
  bool operator == (LongInt);
  bool operator <= (LongInt);
  
  LongInt Add(LongInt);
  LongInt operator + (LongInt); //運算子多載
  LongInt Sub(LongInt);
  LongInt operator - (LongInt); //運算子多載
  
  LongInt Multi(LongInt);
  LongInt operator * (LongInt);
  LongInt Div(LongInt);
  LongInt operator / (LongInt);
  void operator = (LongInt);
};

///////////////////////////////////////////////////////
LongInt::LongInt() {
  Zero();
  IsPositive = (rand() & 1);
  MyInt[MAXN - 20] = (rand() % 9) + 1; 
  for(int i = MAXN - 1; i >= MAXN - 19; i--) {
    MyInt[i] = rand() % 10;
  }
}

LongInt::LongInt(int num) {
  IsPositive = (to_string(num)[0] != '-');
  Zero();
  int idx = MAXN - 1;
  while(num) {
    MyInt[idx--] = num % 10;
    num /= 10;
  }
}

LongInt::LongInt(const char* filename) {
  Zero();
  ifstream ifs(filename, ifstream::in);
  string input;
  ifs >> input;
  int idx = 0;

  IsPositive = true;
  if(input[0] == '-') {
    idx++;
    IsPositive = false;
  }
  
  for(int i = MAXN - 1, j = input.size() - 1; i >= MAXN - 20 + idx && j >= 0; i--, j--) {
    MyInt[i] = (int)(input[j] - '0');
  }
  ifs.close();
}

///////////////////////////////////////////////////////





///////////////////////////////////////////////////////
bool LongInt::operator <= (LongInt b) {
  return (Compare(b) == -1 || Compare(b) == 0);
}

bool LongInt::operator > (LongInt b) {
  return (Compare(b) == 1);
}

bool LongInt::operator < (LongInt b) {
  return (Compare(b) == -1);
}

bool LongInt::operator == (LongInt b) {
  return (Compare(b) == 0);
}

LongInt LongInt::operator - (LongInt b) {
  return Sub(b);
}

LongInt LongInt::operator + (LongInt b) {
  return Add(b);
}

LongInt LongInt::operator * (LongInt b) {
  return Multi(b);
}

void LongInt::operator = (LongInt b) {
  IsPositive = b.IsPositive;
  for(int i = 0; i < MAXN; i++) MyInt[i] = b.MyInt[i];
  return;
}

LongInt LongInt::operator / (LongInt b) {
  return Div(b);
}
///////////////////////////////////////////////////////


///////////////////////////////////////////////////////
LongInt LongInt::Div(LongInt b) {
  if (b == LongInt(static_cast<int>(0))) {
    cout << "You can not divided by 0\n";
    return LongInt(static_cast<int>(0));
    // 處理除以 0 的錯誤情況
  }

  LongInt a = *this;
  LongInt tmp1 = a, tmp2 = b;
  tmp1.IsPositive = tmp2.IsPositive = true;

  LongInt Lptr(static_cast<int>(0)), Rptr(tmp1);
  LongInt ans(static_cast<int>(0));
  for(LongInt i = LongInt(static_cast<int>(0)); i <= tmp1; i = i + 1) {
    LongInt now = (tmp2 * i);
    if(now <= tmp1) {
      ans = i;
    } else {
      break;
    }
  }

  ans.IsPositive = ((a.IsPositive ^ b.IsPositive) ^ 1);

  return ans;
}
///////////////////////////////////////////////////////


///////////////////////////////////////////////////////
LongInt LongInt::Sub(LongInt b) {
  LongInt a = *this;
  LongInt tmp1 = a, tmp2 = b;
  tmp1.IsPositive = tmp2.IsPositive = true;
  bool pos = true;

  if(IsPositive == 0 && b.IsPositive == 1) {
    b.IsPositive = 0;
    LongInt res = Add(b);
    b.IsPositive = 1;
    return res;
  }

  else if(IsPositive == 1 && b.IsPositive == 0){
    b.IsPositive = 1;
    LongInt res = Add(b);
    b.IsPositive = 0;
    return res;
  }

  // 把負號提出來
  if(a.IsPositive == 0 && b.IsPositive == 0) {
    pos = false; // less than 0
  }

  else {
    pos = true; // more than 0
  }


  if(tmp1.Compare(tmp2) == -1) { // a < b
    pos ^= 1;
    LongInt tmp3 = tmp1;
    tmp1 = tmp2;
    tmp2 = tmp3;
  }
  
  for(int i = MAXN - 1; i >= 0; i--) {
    if(tmp1.MyInt[i] < tmp2.MyInt[i]) {
      if(i > 0) {
        tmp1.MyInt[i] += 10;
        tmp1.MyInt[i - 1]--;
      }
    }
    tmp1.MyInt[i] -= tmp2.MyInt[i];
  }

  tmp1.IsPositive = pos;

  return tmp1;
}
///////////////////////////////////////////////////////


///////////////////////////////////////////////////////
LongInt LongInt::Add(LongInt b) {
  LongInt a = *this;
  LongInt res(static_cast<int>(0)), tmp1 = a, tmp2 = b;

  if(tmp1.IsPositive != tmp2.IsPositive) {
    tmp2.IsPositive ^= 1;
    return Sub(tmp2);
  }

  res.IsPositive = tmp1.IsPositive;

  for(int i = MAXN - 1; i >= 0; i--) {
    res.MyInt[i] += (tmp1.MyInt[i] + tmp2.MyInt[i]);
    if(i > 0) res.MyInt[i - 1] += (res.MyInt[i] / 10);
    res.MyInt[i] %= 10;
  }

  return res;
}
///////////////////////////////////////////////////////


///////////////////////////////////////////////////////
int LongInt::Compare(LongInt b) {

  if(IsPositive != b.IsPositive) {
    return (IsPositive > b.IsPositive ? 1 : -1);
  }

  for(int i = 0; i <= MAXN - 1; i++) {
    if(MyInt[i] != b.MyInt[i]) {
      if(IsPositive == 1) {
        return (MyInt[i] > b.MyInt[i] ? 1 : -1);
      }

      else {
        return (MyInt[i] > b.MyInt[i] ? -1 : 1);
      }
    }
  }

  return 0;
}
///////////////////////////////////////////////////////


///////////////////////////////////////////////////////
void LongInt::Zero() {
  for(int i = 0; i < MAXN; i++) {
    MyInt[i] = 0;
  }
  return;
}

void LongInt::Show() {
  int start = MAXN - 1;
  for(int i = 0; i < MAXN; i++) {
    if(MyInt[i] != 0) {
      start = i;
      break;
    }
  }

  if(IsPositive == false && MyInt[start] != 0) cout << "-";
  for(int i = start; i < MAXN; i++) {
    cout << MyInt[i];
  }

  cout << "\n";
  return;
}
///////////////////////////////////////////////////////




///////////////////////////////////////////////////////
LongInt LongInt::Multi(LongInt b) {
  LongInt res;
  for(int i = 0; i < MAXN; i++) {
    res.MyInt[i] = 0;
  }
  
  res.IsPositive = ((IsPositive ^ b.IsPositive) ^ 1);

  int index = MAXN - 1;

  for(int i = MAXN - 1, idx = MAXN - 1; i >= 0; i--, idx--) {
    for(int j = MAXN - 1, k = idx; j >= 0; j--, k--) {
      int multi = MyInt[i] * b.MyInt[j];
      res.MyInt[k] += multi;
      if(k > 0) {
        res.MyInt[k - 1] += res.MyInt[k] / 10;
        res.MyInt[k] %= 10;
      }
    }
  }
  
  return res;
}
///////////////////////////////////////////////////////




///////////////////////////////////////////////////////
void showshow(LongInt a, LongInt b) {
  cout << "a =     ";
  a.Show();
  cout << "b =     ";
  b.Show();
  cout << "a + b = ";
  (a + b).Show();
  cout << "a - b = ";
  (a - b).Show();
  cout << "a * b = ";
  (a * b).Show();
  cout << "a / b = ";
  (a / b).Show();
}


void solve(){
  int mode = 0;
  cout << "選擇 1 (讀檔案) | 2 (隨機亂數) | 3 (結束): ";
  cin >> mode;

  if(mode == 3) {
    exit(0);
  }

  if(mode == 1) {
    LongInt a("./a.txt"), b("./b.txt");
    showshow(a, b);
  }

  else {
    LongInt a, b;
    showshow(a, b);
  }
  
  return;
}

signed main(){
  fastIO
  srand(time(0));
  while(1) {
    solve();
  }
  return 0;
}
///////////////////////////////////////////////////////

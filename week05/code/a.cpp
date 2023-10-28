/*********************************************************
# File Name: a.cpp
# Author: Vincent
# Mail: mengxian0913@gmail.com
# Created Time: 五 10/20 13:20:39 2023
*********************************************************/

#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ff first
#define ss second
#define fastIO cin.tie(nullptr)->sync_with_stdio(false);
#define INF 0x7FFFFFFF
#define pb push_back
#define all(aa) aa.begin(),aa.end()
#define MOD (int)(1e9+7)

#define MAXN (int)(1e6 + 10)

struct MyString {
  char arr[MAXN];
  MyString() {
    memset(arr, '\0', sizeof(arr));
  }

  MyString(const char * str) {
    int i = 0;
    while(str[i] != '\0') {
      arr[i] = str[i];
      i++;
    }
  }

  void Show() {
    printf("%s\n", arr);
  }

  int Length() {
    int i = 0;
    while(arr[i] != '\0') {
      i++;
    }
    return i;
  }

  int IndexOf(const char *str) {
    int arr_sz = Length();
    int str_sz = strlen(str);
    bool ch_flg = true, ch_flg_start = false;
    for(int i = 0; i < arr_sz; i++) {
      ch_flg = true;
      ch_flg_start = false;
      if(arr[i] == str[0] && (arr_sz-i) >= str_sz) {
        ch_flg_start = true;
        for(int j = i, k = 0; k < str_sz; j++, k++) {
          if(arr[j] != str[k]) {
            ch_flg = false;
            break;
          }
        }
      }

      if(ch_flg && ch_flg_start) {
        return i;
      }
    }

    return -1;
  }

  MyString SubString(int start, int len) {
    MyString newStr;
    for(int i = start, j = 0; j < len; j++, i++) {
      newStr.arr[j] = arr[i];
    }
    return newStr;
  }
  
  void Assign(char *newarray) {
    int sz = Length();
    for(int i = 0; i < sz; i++) {
      newarray[i] = arr[i];
    }
    return;
  }

  void InsertOf(const char* newarray, int idx) {
    char temp_str[MAXN];
    int index1 = 0, index2 = 0, temp_index = 0;
    int sz1 = Length();
    int sz2 = strlen(newarray);
   
    while(index1 < idx && index1 < sz1) {
      temp_str[temp_index++] = arr[index1++];   
    }
    temp_index = idx;

    while(index2 < sz2) {
      temp_str[temp_index++] = arr[index2++];
    }

    while(index1 < sz1) {
      temp_str[temp_index++] = arr[index1++];
    }

    for(int i = 0; i < 1e6; i++) {
      arr[i] = ' ';
    }
    for(int i = 0; i < temp_index; i++) {
      arr[i] = temp_str[i];
    }
    return;
  }

  void operator = (const char * str) {
    memset(arr, '\0', sizeof(arr));
    int sz = strlen(str);
    for(int i = 0; i < sz; i++) {
      arr[i] = str[i];
    }
    return;
  }

  
  MyString operator + (MyString str) {
    MyString res;
    int sz1 = Length(), sz2 = str.Length();
    int idx = 0;
    for(int i = 0; i < sz1; i++) {
      res.arr[idx++] = arr[i];
    }

    for(int i = 0; i < sz2; i++) {
      res.arr[idx++] = str.arr[i];
    }
    return res;
  }

  MyString operator + (const char * str) {
    MyString res;
    int sz1 = Length(), sz2 = strlen(str);
    int idx = 0;
    for(int i = 0; i < sz1; i++) {
      res.arr[idx++] = arr[i];
    }

    for(int i = 0; i < sz2; i++) {
      res.arr[idx++] = str[i];
    }
    return res;
  } 

  MyString operator + (int number) {
    MyString res;
    int sz1 = Length();
    int idx = 0;
    for(int i = 0; i < sz1; i++) {
      res.arr[idx++] = arr[i];
    }
    
    string ss = to_string(number);

    for(int i = 0; i < ss.size(); i++) {
      res.arr[idx++] = ss[i];
    }

    return res;
  }
  
};

void solve(){
  MyString str1("Apple"), str2("Banana");
  printf("%s\n", (str1 + str2).arr);
  printf("%s\n", (str1 + "Banana").arr);
  printf("%s\n", (str1 + 123456789).arr);
  char *res;
  res = (str1 + str2).arr;
  printf("%s\n", res);
  cout << "-----------------\n";
  str1.Show();
  cout << str1.Length() << "\n";
  cout << str1.IndexOf("App") << "\n";
  str1.InsertOf("CCC", 1);
}

signed main(){
  fastIO
  solve();
  return 0;
}

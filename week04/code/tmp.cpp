/*********************************************************
# File Name: a.cpp
# Author: Vincent
# Mail: mengxian0913@gmail.com
# Created Time: 五 10/13 13:35:48 2023
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


struct polynomial {
  int coef;
  int expon;
};

struct MyPoly {
  // vector<polynomial> terms;
  polynomial terms[MAXN];
  int idx;
  MyPoly();
  MyPoly(const char*);
  void refresh(const char*);
  void ShowPoly();
  MyPoly Add(MyPoly);
  void SingleMult(int);
  int Lead_Exp();
  void Attach(int, int);
  void Remove(int);
  MyPoly Mult(MyPoly);
};

MyPoly::MyPoly() {
  memset(terms, 0, sizeof(terms));
  idx = 0;
}


bool cmp(polynomial a, polynomial b) {
  if(a.expon != b.expon) {
    return a.expon > b.expon;
  }
  return false;
}


MyPoly MyPoly::Mult(MyPoly poly2) {
  MyPoly result, result2;

  for(int i = 0; i < terms.size(); i++) {
    for(int j = 0; j < poly2.terms.size(); j++) {
      polynomial current = {terms[i].coef * poly2.terms[j].coef, terms[i].expon + poly2.terms[j].expon};
      result.terms.pb(current);
    }
  }

  sort(all(result.terms), cmp);
  
  polynomial cur = result.terms[0];

  for(int i = 1; i < result.terms.size(); i++) {
    if(result.terms[i].expon == cur.expon) {
      cur.coef += result.terms[i].coef;
    } else {
      result2.terms.pb(cur);
      cur = result.terms[i];
    }
  }
  
  return result2;
}

void MyPoly::Remove(int expon) {
  int idx = -1;
  for(int i = 0; i < terms.size(); i++) {
    if(terms[i].expon == expon) {
      idx = i;
      break;
    }
  }
  
  if(idx == -1) {
    cout << "The expon isn't in the function\n";
    return;
  }

  vector<polynomial>::iterator it = terms.begin() + idx;

  terms.erase(it);
  cout << "Success\n";
  return;
}


void MyPoly::Attach(int coef, int expon) {
  for(int i = 0; i < terms.size(); i++) {
     if(terms[i].expon == expon) {
        terms[i].coef += coef;
        return;
    }
  }
  
  terms[idx] = {coef, expon};
  sort(terms, terms + idx, cmp);
  idx++;
  return;
}

int MyPoly::Lead_Exp() {
  return terms[0].coef;
}

void MyPoly::SingleMult(int n) {
  for(int i = 0; i < terms.size(); i++) {
    terms[i].coef *= n;
  }
  return;
}

void MyPoly::refresh(const char* filename) {
  terms.clear();
  ifstream ifs(filename, ifstream::in);
  polynomial input;
  while(ifs >> input.coef >> input.expon) {
    terms[idx] = input;
    idx++;
  }
  ifs.close();
}

MyPoly::MyPoly(const char* filename) {
  ifstream ifs(filename, ifstream::in);
  polynomial input;
  while(ifs >> input.coef >> input.expon) {
    terms[idx] = input;
    idx++;
  }
  ifs.close();
}

void MyPoly::ShowPoly() {
  for(int i = 0; i < idx; i++) {
    cout << terms[i].coef << "X^" << terms[i].expon << "+";
  }
  cout << "\b \n";
  return;
}

MyPoly MyPoly::Add(MyPoly poly2) {
  MyPoly res;

  int idxR = 0, idxL = 0;
  
  while(idxR < terms.size() && idxL < poly2.terms.size()) {
    if(terms[idxR].expon > poly2.terms[idxL].expon) {
      res.terms[idx] = terms[idxR];
      idxR++;
    }
    else if(terms[idxR].expon < poly2.terms[idxL].expon) {
      res.terms[idx] = poly2.terms[idxL];
      idxL++;
    }
    else {
      res.terms[idx] = {terms[idxR].coef + poly2.terms[idxL].coef, terms[idxR].expon};
      idxR++;
      idxL++;
    }
    idx++;
  }

  while(idxR < terms.size()) {
    res.terms[idx] = terms[idxR];
    idxR++;
    idx++;
  }

  while(idxL < poly2.terms.size()) {
    res.terms[idx] = poly2.terms[idxL];
    idxL++;
    idx++;
  }

  return res;
}

void OutputSelect() {
  cout << "Select function:\n";
  cout << "1、讀入多項式\n2、印出多項式內容\n3、多項式相加\n4、多項式乘上一數值\n5、印出多項式中最大指數的係數\n6、新增項式\n7、刪除多項式中的項式\n8、多項式相乘\n";
  return;
}


void solve(){
  MyPoly poly("B1.txt");
  MyPoly poly2("B2.txt");
  
  int mode = 0;
  while(mode != -1) {
    OutputSelect();
    cin >> mode;
    system("clear");

    if(mode == 1) {
      poly.refresh("B1.txt");
    } else if(mode == 2) {
      poly.ShowPoly();
    } else if(mode == 3) {
      // MyPoly result = poly.Add(poly2);
      // result.ShowPoly();
      poly = poly.Add(poly2);
      poly.ShowPoly();
    } else if(mode == 4) {
      int n;
      cout << "input a number: ";
      cin >> n;
      cout << "\n";
      poly.SingleMult(n);
      poly.ShowPoly();
    } else if(mode == 5) {
      cout << poly.Lead_Exp() << "\n";
    } else if(mode == 6) {
      int coef, expon;
      cout << "Please input the coef: ";
      cin >> coef;
      cout << "Please input the expon: ";
      cin >> expon;
      poly.Attach(coef, expon);
      poly.ShowPoly();
    } else if(mode == 7) {
      int expon;
      cout << "Please input the expon you want to remove: ";
      cin >> expon;
      poly.Remove(expon);
      poly.ShowPoly(); 
    } else if(mode == 8) {
      poly = poly.Mult(poly2);
      poly.ShowPoly();
    }
  }

  return;
}

signed main(){
  fastIO
  solve();
  return 0;
}

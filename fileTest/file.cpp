#include<bits/stdc++.h>
using namespace std;

int main() {
  ifstream ifs("./A.txt", ifstream::in);
  ofstream ofs("./B.txt", ofstream::out);
  string ss;
  while(ifs >> ss) {
    ofs << ss << "\n";
  }
  ifs.close();

  return 0;
}

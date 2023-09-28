#include<bits/stdc++.h>
using namespace std;

#define int long long

int fac(int n){
   if(n <= 1){
        return 1;
    } 

    return n * (n - 1);
}

void solve(){
    int n;
    cin >> n;
    cout << n << "! = " << fac(n) << "\n";
}

signed main(){
    solve();
}

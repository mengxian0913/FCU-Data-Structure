#include<bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
stack<char> st;

string get_ans(string ms) {
	int cnt = 0;
	for(int i = 0; i < ms.size(); i++) {
		if(ms[i] == 's') {
			if(cnt > 0) {
				while(!st.empty()) {
					char now = st.top();
					st.pop();
					if(now == 'e') {
						cnt--;
						break;
					}
				}
			} else {
				st.push(ms[i]);
			}
		} else {
			if(ms[i] == 'e') cnt++;
			st.push(ms[i]);
		}
	}
	
	string ans = "";
	while(!st.empty()) {
		ans = st.top() + ans;
		st.pop(); 
	}
	return ans;
}

void solve() {	
	string ss, ms = "";
	ifstream ifs("input.txt", ifstream::in);
	
	if(!ifs.is_open()) {
		cout << "error\n";
		return;
	}
	
	while(getline(ifs, ss)) {
		if(ss == "") {
			cout << get_ans(ms) << "\n";
			ms = "";
		}
		ms += ss;
		ms += "\n";
	}	
	cout << get_ans(ms) << "\n";
	return;
}

signed main() {
	solve();
	return 0;
}

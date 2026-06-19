//100
#include<bits/stdc++.h>
using namespace std;

int n;
string s;
set<string> st;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	freopen("poker.in", "r", stdin);
	freopen("poker.out", "w", stdout);
	
	cin >> n;
	while(n --){
		cin >> s;
		st.insert(s);
	}
	cout << 52 - st.size();
	return 0;
}

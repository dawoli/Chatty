#include <bits/stdc++.h>
using namespace std;
set<int> st;
map<char, int> m1, m2;

int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	string s;
	int n;
	cin >> n;
	m1['D'] = 0;
	m1['C'] = 1;
	m1['H'] = 2;
	m1['S'] = 3;
	m2['A'] = 1;
	m2['2'] = 2;
	m2['3'] = 3;
	m2['4'] = 4;
	m2['5'] = 5;
	m2['6'] = 6;
	m2['7'] = 7;
	m2['8'] = 8;
	m2['9'] = 9;
	m2['T'] = 10;
	m2['J'] = 11;
	m2['Q'] = 12;
	m2['K'] = 0;
	for(int i = 1; i <= n; i ++){
		cin >> s;
		st.insert(m1[s[0]] * 13 + m2[s[1]]);
	}
	cout << 52 - st.size();
	return 0;
}

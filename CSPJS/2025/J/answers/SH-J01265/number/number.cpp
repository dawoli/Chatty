//01-11-25 08:38
#include<bits/stdc++.h>
using namespace std;

string s;
vector<int> v;
int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	 
	cin >> s;
	for(int i = 0; i <= s.size(); ++ i){
		if(s[i] >= '0' && s[i] <= '9')
			v.push_back(s[i] - '0'); 
	}
	
	sort(v.begin(), v.end());
	
	for(int i = 0; i < v.size(); ++ i){
		cout << v[v.size() - i - 1];
	}
	return 0; 
}

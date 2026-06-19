#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
const int maxn = 1e6 + 5;
string s;
int a[maxn], cnt = 0;
bool cmp(int a, int b){
	return a > b;
}
int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	
	cin >> s;
	for(int i = 0; i < s.size(); i++){
		if(s[i] >= '0' && s[i] <= '9') a[++cnt] = s[i] - '0';
	}
	
	sort(a + 1, a + cnt + 1, cmp);
	
	if(a[1] == 0){
		cout << "0\n";
	}else{
		for(int i = 1; i <= cnt; i++) cout << a[i];
		cout << '\n'; 
	}
	
	return 0;
}

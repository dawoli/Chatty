#include<bits/stdc++.h>
using namespace std;
string s;
int num[1000005], c;
bool cmp(int x, int y){
	return x > y;
}
int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	for(int i = 0; i < s.length(); i++){
		if(s[i] >= '0' && s[i] <= '9'){
			num[c] = s[i] - '0';
			c++;
		}
	}
	sort(num, num + c, cmp);
	for(int i = 0; i < c; i++){
		cout << num[i];
	}
	return 0;
}

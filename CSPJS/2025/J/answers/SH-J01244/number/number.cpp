#include <bits/stdc++.h>
using namespace std;
/*
思路：
只选数字是显然的，然后倒序输出，红题。
*//*
luogu 782768 #define int long long
feropen froepen freopen
freopen("number.out", "r", stdin);
freopen("number.in", "w", stdin);
*/
#define HER 20121117
bool cmp(char a, char b){
	return b < a;
}
int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	vector <char> vec;
	for (char i : s){
		if (isdigit(i)) vec.push_back(i);
	} sort(vec.begin(), vec.end(), cmp);
	for (auto i : vec) cout << i;
	
	return 0;
} 

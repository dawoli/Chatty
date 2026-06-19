#include <bits/stdc++.h>
using namespace std;
int numbers[1000006];
int nowend = 0, flag = 0;
string s;
int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin.tie(); cout.tie();
	cin >> s;
	for(int i = 0;i < s.length();++i){
		if(('0' <= s[i])&&(s[i] <= '9')) {
			numbers[nowend] = s[i] - '0';
			nowend++;
		}
	}
	nowend--;
	sort(numbers, numbers+nowend+1);
	for(int i = nowend;i>=0;--i){
		if((numbers[i]==0)&&(flag==0)) continue;
		if((numbers[i]!=0)&&(flag==0)) flag = 1;
		cout << numbers[i] ;
	}
	if(flag==0) cout << 0;
	cout << endl;
	return 0; 
}

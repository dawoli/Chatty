#include<iostream>
using namespace std;
int n;
string s;
int caohua[14];
int fangpian[14];
int hongtao[14];
int heitao[14];
int main() {
	freopen("poker.in",'r',"poker.in");
	freopen("poker.out",'w',"poker.out");
	cin >> n;
	for(int i = 0;i < n;i++) {
		cin >> s;
		if(s[0] == 'D') {
			if(s[1] == 'T')
				fangpian[10] = 1;
			else if(s[1] == 'J')
				fangpian[11] = 1;
			else if(s[1] == 'Q')
				fangpian[12] = 1;
			else if(s[1] == 'K')
				fangpian[13] = 1;
			else if(s[1] == 'A')
				fangpian[1] = 1;
			else {
				fangpian[s[1] - '0'] = 1;
			}
		}
		if(s[0] == 'H') {
			if(s[1] == 'T')
				hongtao[10] = 1;
			else if(s[1] == 'J')
				hongtao[11] = 1;
			else if(s[1] == 'Q')
				hongtao[12] = 1;
			else if(s[1] == 'K')
				hongtao[13] = 1;
			else if(s[1] == 'A')
				hongtao[1] = 1;
			else {
				hongtao[s[1] - '0'] = 1;
			}
		}
		if(s[0] == 'C') {
			if(s[1] == 'T')
				caohua[10] = 1;
			else if(s[1] == 'J')
				caohua[11] = 1;
			else if(s[1] == 'Q')
				caohua[12] = 1;
			else if(s[1] == 'K')
				caohua[13] = 1;
			else if(s[1] == 'A')
				caohua[1] = 1;
			else {
				caohua[s[1] - '0'] = 1;
			}
		}
		if(s[0] == 'S') {
			if(s[1] == 'T')
				heitao[10] = 1;
			else if(s[1] == 'J')
				heitao[11] = 1;
			else if(s[1] == 'Q')
				heitao[12] = 1;
			else if(s[1] == 'K')
				heitao[13] = 1;
			else if(s[1] == 'A')
				heitao[1] = 1;
			else {
				heitao[s[1] - '0'] = 1;
			}
		}
	}
	int ans = 52;
	for(int i = 1;i <= 13;i++) {
		if(caohua[i] == 1)
			ans--;
		if(heitao[i] == 1)
			ans--;
		if(hongtao[i] == 1) 
			ans--;
		if(fangpian[i] == 1)
			ans--;
	}
	cout << ans; 
	return 0;
} 

#include<bits/stdc++.h>

using namespace std;

int b[130];

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	string s; cin >> s;
	for(int i = 0; i < s.size(); i ++)
		b[s[i]] ++;
	
	for(char i = '9'; i >= '0'; i --){
		while(b[i]){
			cout << i;
			b[i] --;
		}
	}
	
	return 0;
}

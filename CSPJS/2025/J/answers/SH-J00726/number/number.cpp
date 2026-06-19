#include<bits/stdc++.h> 
using namespace std;
string s;
int num[11];
int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	freopen("number.in","r",stdin); 
	freopen("number.out","w",stdout); 
	cin >> s;
	for(char c:s) {
		if(c >= '0' && c <= '9')
			num[c - '0']++;
	}
	for(int i = 9; i >= 0; i--) 
		for(int j = 0; j < num[i]; j++) 
			putchar(i+'0');
	return 0;
}

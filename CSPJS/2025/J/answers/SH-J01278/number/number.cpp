#include<bits/stdc++.h>
using namespace std;
string s;
long long m[15];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	for(long long i = 0; i < s.size(); i++){
		if(s[i] == '9') m[9]++;
		if(s[i] == '8') m[8]++;
		if(s[i] == '7') m[7]++;
		if(s[i] == '6') m[6]++;
		if(s[i] == '5') m[5]++;
		if(s[i] == '4') m[4]++;
		if(s[i] == '3') m[3]++;
		if(s[i] == '2') m[2]++;
		if(s[i] == '1') m[1]++;
		if(s[i] == '0') m[0]++;
	}
	for(long long j = 9; j >= 0; j--){
		for(long long i = 1; i <= m[j]; i++){
			cout << j;
		}
	}
	return 0;
} 

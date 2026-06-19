#include <bits/stdc++.h>
using namespace std;
int v[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	bool f = false;
	string s;
	cin >> s;
	for(int i = 0;i<s.size();i++){
		if(s[i] >= '0' && s[i] <= '9'){
			v[s[i]-'0'] ++;
			if(s[i] != '0') f = true;
		}	
	}
	if(f == false) cout << 0 ;	
	else{
		for(int i = 9;i >= 0;i--)
		for(int k = 1; k<= v[i];k++)
			cout << i;
	}
	
	return 0;
}
 

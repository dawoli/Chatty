#include <bits/stdc++.h>
using namespace std;
int a[15];
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	bool fg=0;
	cin >>s;
	for (int i=0;i<s.size();i++){
		if ('9'>=s[i] && s[i]>='0'){
			a[s[i]-'0']++;
			if (s[i]-'0'!=0)
				fg=1;
		}
	}
	if (!fg){
		cout <<0;
		return 0;
	}
	for (int i=9;i>=0;i--){
		for (int j=0;j<a[i];j++){
			cout <<i;
		}
	}
	return 0;
}

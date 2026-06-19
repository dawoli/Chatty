#include<bits/stdc++.h>
using namespace std;
int a[1000005],b = 0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin >> s;
	for(int i = 0;i < s.length();i ++){
		if(s[i] >= 48 && s[i] <= 57){
			a[b] = int(s[i])-48;
			b ++;
		}
	}
	sort(a,a+b);
	for(int i = b-1;i >= 0;i --){
		cout << a[i];
	}
	return 0;
}

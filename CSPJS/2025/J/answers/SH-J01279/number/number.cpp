#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int a[s.length()];
	int digit=0;
	for(int i=0;i<s.length();i++){
		if(s[i]>='0'&&s[i]<='9'){
			digit++;
			a[digit]=s[i];
		}
	}
	sort(a+1,a+digit+1);
	for(int i=digit;i>=1;i--){
		cout<<char(a[i]);
	}
	return 0;
} 

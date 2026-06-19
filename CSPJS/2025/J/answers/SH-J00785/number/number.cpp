#include<bits/stdc++.h>
using namespace std;
int a[15];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<s.length();i++){
		if(s[i]<='9'&&s[i]>='0')a[s[i]-'0']++;
	}
	for(int i=9;i>=0;i--){
		if(a[i]!=0){
			for(int j=1;j<=a[i];j++)cout<<i;
		}
	}
	return 0;
}

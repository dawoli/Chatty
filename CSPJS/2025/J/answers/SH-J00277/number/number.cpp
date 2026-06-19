#include<bits/stdc++.h>
using namespace std;
int a[1000009];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int p=0;
	for(int i=0;i<s.size();i++){
		if('0'<=s[i]&&s[i]<='9'){
			a[p++]=(int)s[i]-'0';
		}
	}
	sort(a,a+p);
	for(int i=p-1;i>=0;i--){
		cout<<a[i];
	}
	return 0;
} 

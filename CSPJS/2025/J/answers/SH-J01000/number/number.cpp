//RP++
#include <bits/stdc++.h>
#define N 1000020
using namespace std;
short a[N];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s,v;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if((s[i]>='0'&&s[i]<='9')){
			v+=s[i];
		}
	}
	//cout<<v;
	
	for(int i=0;i<v.size();i++){
		a[i]=v[i]-'0';
	}
	
	sort(a,a+v.size());
	
	for(int i=v.size()-1;i>=0;i--){
		cout<<a[i];
	}
	
	return 0;
}

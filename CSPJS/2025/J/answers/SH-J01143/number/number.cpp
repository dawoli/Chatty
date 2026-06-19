#include<bits/stdc++.h>
using namespace std;
int cnt(int a,int b){
	return a>=b;
}
int main(){
	freopen("number.in","s",stdin);
	freopen("number.out","w",stdout);
	string s;
	int a[1000005],b=0;
	cin>>s;
	for(int i=0;i<s.length();i++){
		if(s[i]<'0'||s[i]>'9'){
			continue;
		}else if(s[i]=='9'){
			cout<<9;
		}else{
			a[b]=(s[i]-'0');
			b++;
		}
	}
	sort(a,a+b,cnt);
	for(int i=0;i<b;i++){
		cout<<a[i];
	}
	return 0;
}

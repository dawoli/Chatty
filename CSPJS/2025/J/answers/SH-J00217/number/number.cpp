#include<bits/stdc++.h>
using namespace std;
int a[1000010],b;
bool cmp(int a,int b){
	return a>=b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<s.length();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[++b]=s[i]-'0';
		}
	}
	sort(a+1,a+b+1,cmp);
	for(int i=1;i<=b;i++)
		cout<<a[i];
	return 0;
}

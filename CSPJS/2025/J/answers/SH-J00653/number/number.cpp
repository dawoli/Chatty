#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;
int a[1000005];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s,s1="";
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9') s1+=s[i];
	}
	for(int i=0;i<s1.size();i++){
		int x=s1[i]-48;
		a[i]=x;
	}
	sort(a,a+s1.size(),cmp);
	for(int i=0;i<s1.size();i++) cout<<a[i];
	fclose(stdin);
	fclose(stdout);
	return 0;
}

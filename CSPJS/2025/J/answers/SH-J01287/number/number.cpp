#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000005];
int cnt;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	cin>>s;
	for(int i=0;i<s.length();i++){
		if('0'<=s[i]&&s[i]<='9') a[++cnt]=s[i]-'0';
	}
	sort(a+1,a+cnt+1,cmp);
	for(int i=1;i<=cnt;i++){
		cout<<a[i];
	}
}

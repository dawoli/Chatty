#include<bits/stdc++.h>
using namespace std;
int a[1000001],cnt=0;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<s.size();++i){
		if(isdigit(s[i])){
			a[++cnt]=s[i]-'0';
		}
	}
	sort(a+1,a+cnt+1,cmp);
	for(int i=1;i<=cnt;++i){
		cout<<a[i];
	}
	return 0;
}

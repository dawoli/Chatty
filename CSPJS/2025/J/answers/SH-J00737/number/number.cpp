#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	int a[1000011];
	for(int i=0;i<=1000001;++i){
		a[i]=-1;
	}
	int cnt;
	cnt=0;
	cin>>s;
	int x=s.length();
	for(int i=0;i<x;++i){
		if(s[i]>='0' && s[i]<='9'){
			cnt++;
			a[cnt]=(s[i]-48);
		}
	}
	sort(a+1,a+cnt+1);
	reverse(a+1,a+cnt+1);
	for(int i=1;i<=cnt;++i){
		if(a[i]!=-1){
			cout<<a[i];
		}
	}
	return 0;
}

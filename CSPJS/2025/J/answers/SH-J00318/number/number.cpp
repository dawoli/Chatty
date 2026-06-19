#include<bits/stdc++.h>
using namespace std;
long long a[1000001],cnt=0;
bool cmp(long long x, long long y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(long long i=0;i<s.size();i++){
		if(isdigit(s[i])){
			a[++cnt]=s[i]-'0';
		}
	}
	sort(a+1,a+cnt+1,cmp);
	for(long long i=1;i<=cnt;i++){
		cout<<a[i];
	}
	return 0;
}

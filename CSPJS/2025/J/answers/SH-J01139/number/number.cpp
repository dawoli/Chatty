#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+7;
int ans[maxn];
int main() {
	int cnt=0;
	string s;
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0; i<=s.size(); i++) {
		if(s[i]=='0') ans[i]+=0;
		if(s[i]=='1') ans[i]+=1;
		if(s[i]=='2') ans[i]+=2;
		if(s[i]=='3') ans[i]+=3;
		if(s[i]=='4') ans[i]+=4;
		if(s[i]=='5') ans[i]+=5;
		if(s[i]=='6') ans[i]+=6;
		if(s[i]=='7') ans[i]+=7;
		if(s[i]=='8') ans[i]+=8;
		if(s[i]=='9') ans[i]+=9;
		if(s[i]>'a' and s[i]<'z') cnt++;
	}
	sort(ans,ans+1+s.size());
	for(int i=s.size(); i>=cnt+1; i--) {
		cout<<ans[i];	
	}
	return 0;
}

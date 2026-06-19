#include <bits/stdc++.h>
using namespace std;
long long a[1000000];
int t=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.ont","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<s.length();i++){
		if(s[i]>='0' && s[i]<='9') a[t]=s[i]-'0',t++;
	}
	sort(a,a+t);
	bool q=0;
	if(a[t-1]!=0) q=1;
	if(q==0){
		cout<<0;
		return 0;
	}
	for(int i=t-1;i>=0;i--){
		printf("%d",a[i]);
	}
	return 0;
} 

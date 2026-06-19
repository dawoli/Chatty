#include<bits/stdc++.h>
using namespace std;
int a[1000001];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int cnt=0;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9') a[++cnt]=s[i]-'0';
	}
	sort(a+1,a+cnt+1);
	for(int i=cnt;i>=1;i--) cout<<a[i];
	fclose(stdin);
	fclose(stdout);
} 

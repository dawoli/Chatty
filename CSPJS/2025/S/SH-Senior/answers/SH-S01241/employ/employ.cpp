#include<bits/stdc++.h>
using namespace std;
string s;
int n,m,c[505];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	int cnt=0,f=1;
	for(int i=0;i<s.length();i++){
		if(s[i]=='0')cnt++;
		if(s[i]=='1'&&f)f=0;
		else if(s[i]=='1'&&f==0)break;
	}
	if(cnt<m){
		cout<<0;
		return 0;
	}
	else{
		int ans=1;
		for(int i=1;i<=n;i++){
			ans*=i;
			ans%=998244353;
		}
		cout<<ans;
	}
}

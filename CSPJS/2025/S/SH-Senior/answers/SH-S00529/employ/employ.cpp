#include<bits/stdc++.h>
using namespace std;
int n,m;
string s;
int c[509];
int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	bool flag=1;
	for(int i=0;i<n;i++){
		cin>>c[i];
	}
	for(int i=0;i<n;i++){
		if(s[i]=='0') flag=0;
	}
	if(flag){
		long long ans=1,num=n;
		for(int i=n-1;i>=0;i--){
			if(c[i]==0) num--;
		}
		for(int i=num;i>=m;i--){
			ans*=i;
			ans%=998244353;
		}
		cout<<ans<<endl;
	}
	else{
		cout<<0<<endl;
	}
	return 0;
} 

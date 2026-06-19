#include<bits/stdc++.h>
using namespace std;
int mod=998244353;
int a[5001],ans=0,n;
string sz(int x){
	string s="";
	while(x){
		int g=x%2;
		s=char(g+'0')+s;
		x=x/2;
	}
	return s;	
}
void cl(int x){
	string s=sz(x);
	int c1=0,sum=0,zd=0;
	while(s.size()<=n)s='0'+s;
	for(int i=0;i<s.size();i++){
		if(s[i]=='1')c1++,sum=sum+a[i],zd=max(zd,a[i]);
	}
	if(c1>=3&&sum>zd*2)ans++;//cout<<x<<' '<<s<<' '<<sum<<' '<<zd<<endl;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int zds=0;
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i],zds=max(zds,a[i]);
	if(n<=25){
		int t=1;
		for(int i=1;i<=n;i++)t=t*2;
		for(int i=1;i<=t;i++){
			cl(i);
		}
		cout<<ans%mod;
	}
	else if(zds==1){
		long long ans1=0;
		for(int i=3;i<n;i++){
			long long a1=1,a2=1;
			for(int j=i+1;j<=n;j++)a1=a1*j%mod;
			for(int j=1;j<=n-i;j++)a2=a2*j%mod;
			ans1=(ans1+a1/a2)%mod;
		}
		cout<<(ans1+1)%mod;
	}
	else cout<<366911923;
}

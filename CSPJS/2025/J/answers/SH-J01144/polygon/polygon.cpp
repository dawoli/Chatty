#include<bits/stdc++.h>
using namespace std;
#define int long long
int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
	return x*f;
}
const int mod=998244353;
int n,a[5005];
int s[25000005],top,S[25000005];
int ans;
signed main(){//polygon
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	n=read();
	bool flag=1;
	for(int i=1;i<=n;i++){
		a[i]=read();
		if(a[i]>1)flag=0;
	}
	if(flag){
		ans=1;
		for(int i=1;i<=n;i++){
			ans=(ans*2)%mod;
		}
		cout<<(ans-(n*(n-1)/2)-n-1+mod)%mod;
		return 0;
	}
	sort(a+1,a+n+1);
	s[0]=1;
	top=0;
	for(int i=1;i<=n;i++){
		if(i>=3){
			int res=0;
			for(int j=a[i]+1;j<=top;j++){
				res=(res+s[j])%mod;
			}
			ans=(ans+res)%mod;
		}
		for(int j=0;j<=top;j++){
			S[j+a[i]]=s[j];
			S[j]%=mod;
		}
		top+=a[i];
		for(int j=0;j<=top;j++){
			s[j]+=S[j];
			s[j]%=mod;
			S[j]=0;
		}
	}
	cout<<(ans+mod)%mod;
	return 0;
}


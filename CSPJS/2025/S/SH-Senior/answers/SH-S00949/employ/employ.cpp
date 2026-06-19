#include<bits/stdc++.h>
#define ll long long
#define M 998244353
using namespace std;

ll rd(){
	ll x=0;
	char c=getchar();
	while(c<'0' || c>'9') c=getchar();
	while(c>='0'&& c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x;
}

ll n,m,ans,a[510],cnt,fac[510],vis[510],lft[510];
string s;

void dsy(ll d,ll now){
	if(now==n+1){
		if(n-d>=m) ans++;
		return;
	}
	//if(n-d<m || lft[n]-lft[now-1]+now-d<m) return;
	if(now-1-d>m){
		ans+=fac[n-now+1];
		return;
	}
	for(ll i=1;i<=n;i++){
		if(vis[i]) continue;
		vis[i]=1;
		if(a[i]>d && s[now-1]=='1') dsy(d,now+1);
		else dsy(d+1,now+1);
		vis[i]=0;
	}
}

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=rd(),m=rd();
	ll f=n;
	cin>>s;
	fac[0]=1;
	for(ll i=1;i<=n;i++){
		fac[i]=(fac[i-1]*i)%M;
	}
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==0) f--;
	}
	if(n<=18){
		dsy(0,1);
		cout<<ans%M;
	}
	lft[0]=0;
	for(ll i=0;i<s.length();i++){
		if(s[i]=='1') cnt++,lft[i+1]=lft[i]+1;
		else lft[i+1]=lft[i];
	}
	if(cnt<m || f<m){
		cout<<0;
		return 0;
	}
	if(cnt==n){
		cout<<fac[n];
		return 0;
	}
	return 0;
}

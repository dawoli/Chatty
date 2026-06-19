#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD=998244353;
const ll K=18;
const ll N=509;
ll read(){
	ll x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9') f=((bool)(c^'-')<<1)-1,c=getchar();
	while(c>='0'&&c<='9') x=(x<<3)+(x<<1)+(c^48),c=getchar();
	return x*f;
}
ll n,m,Bcnt[(1<<K)+10],f[(1<<K)+10][20],c[N],ans;
string s;
inline ll LSB(ll x){return x&(-x);}
void mod(ll&x){
	if(x>=MOD) x-=MOD;
}
void solveBF(){
	cin>>s;
	for(ll i=0;i<n;++i) cin>>c[i];
	for(ll i=1;i<(1<<n);++i)
		Bcnt[i]=Bcnt[i^LSB(i)]+1;
	f[0][0]=1;
	for(ll S=1;S<(1<<n);++S){
		for(ll cnt=Bcnt[S];cnt>=0;--cnt)
			for(ll i=0;i<n;++i)
				if(S&(1<<i)){//如果这个人可以不通过
					if(cnt&&((s[Bcnt[S]-1]=='0')||cnt-1>=c[i])) f[S][cnt]+=f[S^(1<<i)][cnt-1];
					//这个人可以通过
					if(s[Bcnt[S]-1]=='1'&&c[i]>cnt)f[S][cnt]+=f[S^(1<<i)][cnt];
					mod(f[S][cnt]);
				}//cnt代表不通过的人数
	}
//	for(ll S=1;S<(1<<n);++S)
//		for(ll i=0;i<n;++i)
//			if(f[S][i]) cout<<"f["<<S<<"]["<<i<<"]="<<f[S][i]<<"\n";
	for(ll i=0;i<=n-m;++i)//不通过的人数应当在 
		ans+=f[(1<<n)-1][i],mod(ans);
//		,cout<<f[(1<<n)-1][i]<<"\n";
	cout<<ans;exit(0);
}
ll pos[30],cnt=0,r[30],sum;
void solveSP(){
	cin>>s;
	for(ll i=1;i<=n;++i)
		cin>>c[i];
	bool all1=1;
	for(ll i=0;i<n;++i)
		all1&=(s[i]=='1');
	if(all1){
		ll ans=1,cnt0=0;
		for(ll i=1;i<=n;++i)
			ans*=i,ans%=MOD,cnt0+=(c[i]==0);
		if(cnt0>=n-m+1) cout<<0,exit(0);
		cout<<ans,exit(0);
	}
	sort(c+1,c+n+1);
	for(ll i=0;i<s.size();++i)
		if(s[i]=='1') pos[cnt++]=i+1;
	for(ll i=1;i<(1<<cnt);++i)
		Bcnt[i]=Bcnt[i^LSB(i)]+1;
	for(ll S=0;S<(1<<cnt);++S){
		if(Bcnt[S]<m) continue;
		ll sumOK=0,cntR=0,xi=(((Bcnt[S]-m)&1)?-1:1);
		for(ll j=0;j<cnt;++j){
			bool ok=S&(1<<j);//可以
			if(ok)r[++cntR]=pos[j]-sumOK;
			sumOK+=ok;
		}
		for(ll i=cntR,j=n+1;i>=1;--i){
			while(j>1&&c[j-1]>=r[i]) --j;
			ll op=(n-j+1)-(cntR-i);
			if(op<=0){ans=0;break;}
			ans*=op,ans%=MOD;
		}
		sum+=xi*ans,sum%=MOD;
	}
	cout<<(sum%MOD+MOD)%MOD;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	if(n<=18) solveBF(),exit(0);
	solveSP();
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=200009;
ll n,a[N],b[N],ans,len;
void solveBF(){
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int k=0;k<(1<<n);k++){
		ll now0=0,now1=0,cnt=0;
		for(int i=1;i<=n;i++){
			int p=(k>>(i-1))&1;
			if(p==0){
				if(now0==a[i]) cnt+=a[i];
				now0=a[i]; 
			}else{
				if(now1==a[i]) cnt+=a[i];
				now1=a[i];
			}
		} 
		ans=max(ans,cnt);
	}
	cout<<ans<<endl;
	ans=0;
}
int pre[5*N],nxt[5*N];
ll f[N],fm[N];
ll max(ll num1,ll num2){
	if(num1>num2) return num1;
	return num2;
} 
void solve(){
	for(int i=1;i<=n;i++){
		cin>>b[i];
		if(b[i]==a[len]) ans+=b[i];
		else a[++len]=b[i];
	}
	n=len;
	for(int i=n;i>=1;i--){
		pre[nxt[a[i]]]=i;
		nxt[a[i]]=i;
	}
	f[0]=fm[0]=0;
	for(int i=1;i<=n;i++){
		fm[i]=fm[i-1];
		if(pre[i]==0) continue;
		f[i]=f[pre[i]]+a[i]+(a[pre[i]-1]==a[pre[i]+1])*a[pre[i]+1];
		f[i]=max(f[i],f[pre[i]+1]+a[i]);
		f[i]=max(f[i],fm[pre[i]-1]+a[i]);
		fm[i]=max(fm[i-1],f[i]);
	}
	cout<<ans+fm[n]<<endl;
	for(int i=1;i<=n;i++) f[i]=a[i]=pre[i]=nxt[a[i]]=0;
	len=ans=0;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int T;
	cin>>T;
	while(T--){ 
		cin>>n;
		if(n<=15)
			solveBF();
		else
			solve();
	}
	return 0;
} 

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t,n,m,Rlen,maxV;
ll d[29],v[29],a[29],p[29];
ll checkList[29][29],tot[29];//di i liang che/bei shen me she xiang tou/fa xian de
ll ok(ll Code){
	bool nwP[29];
	memset(nwP,0,sizeof(nwP));
	ll nwans=m;
	ll anoCode=Code;
	for(ll i=1;i<=m;i++){
		if(anoCode%2==1) nwP[i]=1,nwans--;
		anoCode/=2;
	}
	for(ll i=1;i<=n;i++){
		if(!tot[i]) continue;
		bool fl=0;
		for(ll j=1;j<=tot[i];j++) if(nwP[checkList[i][j]]){
			fl=1;
			break;
		}
		if(!fl) return -1;
	}
	return nwans;
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>t;
	while(t--){
		memset(checkList,0,sizeof(checkList));
		memset(tot,0,sizeof(tot));
		cin>>n>>m>>Rlen>>maxV;
		for(ll i=1;i<=n;i++){
			cin>>d[i]>>v[i]>>a[i];
		}
		for(ll i=1;i<=m;i++){
			cin>>p[i];
		}
		int SumAll=0;
		for(ll i=1;i<=n;i++){
			bool continueFlag=0;
			if(a[i]<0){
				ll lveFZ=2*a[i]*d[i]-v[i]*v[i],lveFM=2*a[i];
				if(lveFZ<lveFM*Rlen){
					continueFlag=1;
					for(ll j=1;j<=m;j++){
						if(lveFZ>p[j]*lveFM) continue;
						if(p[j]<d[i]) continue;
						ll s=p[j]-d[i];
						ll v0=v[i];
						ll Ja=a[i];
						ll nwSpSq=v0*v0+2*Ja*s;
						if(nwSpSq>maxV*maxV) checkList[i][++tot[i]]=j;
					}
				}
			}
			if(continueFlag) continue;
			for(ll j=1;j<=m;j++){
				if(p[j]<d[i]) continue;
				ll s=p[j]-d[i];
				ll v0=v[i];
				ll Ja=a[i];
				ll nwSpSq=v0*v0+2*Ja*s;
				if(nwSpSq>maxV*maxV) checkList[i][++tot[i]]=j;
			}
			
		}
		for(int i=1;i<=n;i++) if(tot[i]>0) SumAll++;
		cout<<SumAll<<" ";
		ll ans=0;
		for(ll i=0;i<=(1<<m)-1;i++){
			ans=max(ans,ok(i));
		}
		cout<<ans<<endl;
	}
	return 0;
}

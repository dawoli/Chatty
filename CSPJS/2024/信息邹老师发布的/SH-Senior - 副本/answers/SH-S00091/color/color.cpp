#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1000007;
ll T,n,a[N],f[N],tag[N],TAG,ans,MX;
int main(){
	ios::sync_with_stdio(false);
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>T;
	memset(f,-0x3f,sizeof(f));
	while(T--){
		cin>>n>>a[1];
		ans=TAG=MX=0;
		for (int i=2;i<=n;++i){
			cin>>a[i];
			ll F=max(MX,f[a[i]]+TAG-tag[a[i]]+a[i]);
			if (a[i-1]==a[i]) {MX+=a[i];TAG+=a[i];}
			f[a[i-1]]=max(f[a[i-1]]+TAG-tag[a[i-1]],F);tag[a[i-1]]=TAG;
			MX=max(MX,f[a[i-1]]);
		}
		for (int i=1;i<=n;++i){ans=max(ans,f[a[i]]+TAG-tag[a[i]]);f[a[i]]=-1e18;tag[a[i]]=0;}
		cout<<ans<<endl;
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=200009,A=1e6+9;
ll T,n;
ll a[N],f[N][2];
ll pos[A],lst[N];
void solveBFDP(){
	ll ans=0;
	for(int i=0;i<(1<<(n+1));i++){
		ll sum=0;
		for(int j=0;j<n;j++)
			for(int k=j-1;k>=0;k--){
				if(bool(i&(1<<j))!=bool(i&(1<<k)))
					continue;
				if(a[j+1]==a[k+1])
					sum+=a[j+1];
				break;
			}
		ans=max(ans,sum);
	}
	cout<<ans<<endl;
}
int main(){
	freopen("color2.in","r",stdin);
	//freopen(".out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		if(n<=15){
			solveBFDP();
			continue;
		}
		for(int i=1;i<=1e6;i++)
			pos[i]=-1;
		for(int i=1;i<=n;i++){
			lst[i]=pos[a[i]];
			pos[a[i]]=i;
		}
	}
	return 0;
}


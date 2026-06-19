#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll N=200009;
ll t,n;
ll a[N];
ll c[N];

//¶à²âÇå¿Õ£¡ 

void solve15(){
	//20pts
	
	ll ans=0;
	for(ll s=0;s<=(1<<n)-1;s++){
		for(ll i=1;i<=n;i++){
//			if(i==1)c[i]=s&(1<<(i-1));
//			else c[i]=s&((1<<(i-1))-(1<<(i-2)));
			c[i]=s>>(i-1)&1;
//			cout<<c[i]<<" ";
		}
		ll res=0;
		for(ll i=1;i<=n;i++){
			for(ll j=i-1;j>=1;j--){
				if(c[i]==c[j]){
					if(a[i]==a[j])res+=a[i];
					break;
				}
			}
		}
		ans=max(ans,res);
	}
	cout<<ans<<endl;
	return;
}

ll f[109][109][109];
ll maxa=0;

void solvedp(){
	for(ll i=1;i<=n;i++)for(ll j=1;j<=maxa;j++)for(ll k=1;k<=maxa;k++)f[i][j][k]=0;
	for(ll i=2;i<=n;i++){
		for(ll j=1;j<=maxa;j++){
			f[i][j][a[i]]=f[i-1][j][a[i]]+a[i];
		}
		for(ll k=1;k<=maxa;k++){
			f[i][a[i]][k]=f[i-1][a[i]][k]+a[i];
		}
		for(ll j=1;j<=maxa;j++)for(ll k=1;k<=maxa;k++){
			f[i][j][k]=max(f[i][j][k],f[i-1][j][k]);
//			cout<<f[i][j][k]<<" ";
		}
	}
	ll ans=0;
	for(ll j=1;j<=maxa;j++)for(ll k=1;k<=maxa;k++)ans=max(ans,f[n][j][k]);
	cout<<ans<<endl;
	return;
}

int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	
	cin>>t;
	while(t--){
		cin>>n;
		for(ll i=1;i<=n;i++){cin>>a[i];maxa=max(maxa,a[i]);}
		if(n<=15)solve15();
		else if(n<=109 && maxa<=109)solvedp(); 
//		solve15();
//		solvedp();
	}
	
	return 0;
}

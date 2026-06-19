#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+10;
int n,a[N][4];
int sz[4],b[4][N];
inline void MAIN(){
	cin>>n;
	int ans=0,t=1,k=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=3;j++) cin>>a[i][j];
		t=1;
		for(int j=2;j<=3;j++) if(a[i][j]>a[i][t]) t=j;
		ans+=a[i][t];
		k=0;
		for(int j=1;j<=3;j++){
			if(j==t) continue;
			k=max(k,a[i][j]);
		}
		b[t][++sz[t]]=a[i][t]-k;
	}
	t=0;
	for(int i=1;i<=3;i++){
		if(sz[i]>n/2){
			t=i;
			break;
		}
	}
	if(t==0){
		cout<<ans<<'\n';
	}
	else{
		sort(b[t]+1,b[t]+1+sz[t]);
		for(int i=1;i+(n/2)<=sz[t];i++){
			ans-=b[t][i];
		}
		cout<<ans<<'\n';
	}
	for(int i=1;i<=3;i++) sz[i]=0;
	return;
}

signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--) MAIN();
	return 0;
}

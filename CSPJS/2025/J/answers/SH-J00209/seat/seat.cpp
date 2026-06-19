#include<bits/stdc++.h>
//inclue<bits/extc++.h>
using namespace std;
long long n,m,a[2009],ans[20][20],now,r,ansr;
bool cmp(long long x,long long y){
	return x>y;
}
void solve(){
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	r=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(r==a[i]) ansr=i;
	}
	for(int i=1;i<=m;i++){
		if(i%2) for(int j=1;j<=n;j++) ans[j][i]=++now;
		else for(int j=n;j>=1;j--) ans[j][i]=++now;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(ans[i][j]==ansr){
				cout<<j<<' '<<i<<'\n';
				return ;
			}
			//cout<<ans[i][j]<<' ';
		}
		//cout<<'\n';
	}
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	long long T=1;//cin>>T;
	while(T--) solve();
}
//subscribe tasho11y in bilibili(in luogu)!!! 
//S rp++
//AK at 10:36

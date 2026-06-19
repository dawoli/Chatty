#include<bits/stdc++.h>
using namespace std;
const int N=1e5+9;
int T,n,a[N][4],ch[N],num[4],ans,minn[N],cnt;
void solve(){
	ans=0;
	cin>>n;
	for(int i=1;i<=3;i++) num[i]=0;
	for(int i=1;i<=n;i++){
		int maxn=0;
		for(int j=1;j<=3;j++) cin>>a[i][j],maxn=max(maxn,a[i][j]);
		ans+=maxn;
		for(int j=1;j<=3;j++)
			if(a[i][j]==maxn){
				ch[i]=j;
				num[j]++;
				break;
			} 
	}
	int now=0;
	for(int i=1;i<=3;i++)
		if(num[i]>n/2) now=i;
	if(!now){
		cout<<ans<<'\n';
		return;
	}
	cnt=0;
	for(int i=1;i<=n;i++)
		if(ch[i]==now){
			minn[++cnt]=1e9;
			for(int j=1;j<=3;j++)
				if(j!=now) minn[cnt]=min(minn[cnt],a[i][now]-a[i][j]);
		}
	sort(minn+1,minn+cnt+1);
	for(int i=1;i<=num[now]-n/2;i++) ans-=minn[i];
	cout<<ans<<'\n';
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>T;
	while(T--) solve();
	return 0;
} 

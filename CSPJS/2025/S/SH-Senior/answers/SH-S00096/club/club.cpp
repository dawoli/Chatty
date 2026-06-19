#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=100007;
ll T,n,m,a[N][3],c[N],cnt[3],d[N],b[N],ans;
int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;ans=0;cnt[0]=cnt[1]=cnt[2]=0;
		for (int i=1;i<=n;++i){
			cin>>a[i][0]>>a[i][1]>>a[i][2];
			int p=0;
			if (a[i][1]>a[i][p]){
				p=1;
			}
			if (a[i][2]>a[i][p]){
				p=2;
			}
			c[i]=p;
			ans+=a[i][p];
			++cnt[c[i]];
			d[i]=0;
			for (int x=0;x<3;++x){
				if (x!=p){
					d[i]=max(d[i],a[i][x]);
				}
			}
			d[i]=a[i][p]-d[i];
		}
		int p=0;
		if (cnt[1]>cnt[p]){
			p=1;
		}
		if (cnt[2]>cnt[p]){
			p=2;
		}
		if (cnt[p]*2>n){
			m=0;
			for (int i=1;i<=n;++i){
				if (c[i]==p){
					b[++m]=d[i];
				}
			}
			sort(b+1,b+1+m);
			for (int i=1;i<=m-n/2;++i){
				ans-=b[i];
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

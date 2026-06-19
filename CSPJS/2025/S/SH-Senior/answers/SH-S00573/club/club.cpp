#include<bits/stdc++.h>
#define int long long
#define N 100005
using namespace std;
int n,a[N][4],b[N],c[4],d[N];
void solve(){
	cin>>n;
	for(int j=1;j<=3;j++)c[j]=0;
	int sum=0;
	for(int i=1;i<=n;i++){
		cin>>a[i][1]>>a[i][2]>>a[i][3];
		int mx=*max_element(a[i]+1,a[i]+4);
		b[i]=0;
		for(int j=1;j<=3;j++){
			if(a[i][j]==mx){
				b[i]=j;
				sum+=mx;
				++c[j];
				break;
			}
		}
		assert(b[i]);
	}
	for(int j=1;j<=3;j++){
		if(c[j]>n/2){
			int tot=0;
			for(int i=1;i<=n;i++){
				if(b[i]==j){
					d[++tot]=-1e12;
					for(int k=1;k<=3;k++)
						if(k!=j)
							d[tot]=max(d[tot],a[i][k]-a[i][j]);
				}
			}
			stable_sort(d+1,d+1+tot,greater<int>());
			for(int i=1;i<=c[j]-n/2;i++){
				sum+=d[i];
			}
			cout<<sum<<'\n';
			return;
		}
	}
	cout<<sum<<'\n';
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	int T=1;
	cin>>T;
	while(T--){
		solve();
	}
	return 0;
}
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=100005;
int t,n,a[N][4],tmp[4][N];
int f[2][205][205],ans;
int cnt1,cnt2,cnt3;
bool flag1,flag2;
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;++i){
			scanf("%lld%lld%lld",a[i]+1,a[i]+2,a[i]+3);
			if(a[i][2]||a[i][3]) flag1=0;
			if(a[i][3]) flag2=0;
		}
		if(flag1){
			for(int i=1;i<=n;++i) tmp[1][i]=a[i][1];
			sort(tmp[1]+1,tmp[1]+n+1);
			ans=0;
			for(int i=n/2+1;i<=n;++i) ans+=tmp[1][i];
			cout<<ans<<endl;
			continue;
		}
		if(flag2){
			cnt1=0; cnt2=0; ans=0;
			for(int i=1;i<=n;++i){
				if(a[i][1]>=a[i][2]){
					cnt1++; ans+=a[i][1]; tmp[1][cnt1]=a[i][1]-a[i][2];
				}
				else{
					cnt2++; ans+=a[i][2]; tmp[2][cnt2]=a[i][2]-a[i][1];
				}
			}
			if(cnt1==cnt2) cout<<ans<<endl;
			else if(cnt1>n/2){
				sort(tmp[1]+1,tmp[1]+cnt1+1);
				for(int i=1;i<=cnt1-n/2;++i) ans-=tmp[1][i];
				cout<<ans<<endl;
			}
			else{
				sort(tmp[2]+1,tmp[2]+cnt2+1);
				for(int i=1;i<=cnt2-n/2;++i) ans-=tmp[2][i];
				cout<<ans<<endl;
			}
			continue;
		}
		if(n<=200){
			for(int j=1;j<=n/2;++j)
				for(int k=1;k<=n/2;++k)
					f[1][j][k]=-1e9;
			f[0][0][0]=0; ans=0;
			for(int i=1;i<=n;++i){
				for(int j=0;j<=min(i,n/2);++j){
					for(int k=0;k<=min(i,min(i-j,n/2));++k){
						f[i%2][j][k]=-1e9;
						if(i-j-k>n/2) continue;
						if(j!=0) f[i%2][j][k]=max(f[i%2][j][k],f[(i-1)%2][j-1][k]+a[i][1]);
						if(k!=0) f[i%2][j][k]=max(f[i%2][j][k],f[(i-1)%2][j][k-1]+a[i][2]);
						if(i-j-k!=0) f[i%2][j][k]=max(f[i%2][j][k],f[(i-1)%2][j][k]+a[i][3]);
						if(i==n) ans=max(ans,f[i%2][j][k]);
					}
				}
			}
			cout<<ans<<endl;
		}
		else{
			cnt1=0; cnt2=0,cnt3=0; ans=0;
			for(int i=1;i<=n;++i){
				if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]){
					cnt1++; ans+=a[i][1];
					tmp[1][cnt1]=min(a[i][1]-a[i][2],a[i][1]-a[i][3]);
				}
				else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3]){
					cnt2++; ans+=a[i][2];
					tmp[2][cnt2]=min(a[i][2]-a[i][1],a[i][2]-a[i][3]);
				}
				else{
					cnt3++; ans+=a[i][3];
					tmp[3][cnt3]=min(a[i][3]-a[i][1],a[i][3]-a[i][2]);
				}
			}
			if(cnt1>n/2){
				sort(tmp[1]+1,tmp[1]+cnt1+1);
				for(int i=1;i<=cnt1-n/2;++i) ans-=tmp[1][i];
			}
			else if(cnt2>n/2){
				sort(tmp[2]+1,tmp[2]+cnt2+1);
				for(int i=1;i<=cnt2-n/2;++i) ans-=tmp[2][i];
			}
			else if(cnt3>n/2){
				sort(tmp[3]+1,tmp[3]+cnt3+1);
				for(int i=1;i<=cnt3-n/2;++i) ans-=tmp[3][i];
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}

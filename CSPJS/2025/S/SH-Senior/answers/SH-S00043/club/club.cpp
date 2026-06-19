#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10,inf=1e9;
int a[N][4];
int n,m;
int ans;
int T;
int f[210][210][210];
void clean(){
	for(int i=0;i<=n;i++){
		for(int j=0;j<=n;j++){
			for(int k=0;k<=n;k++){
				f[i][j][k]=-inf;
			}
		}
	}
	ans=-inf;
}
int temp[N];
struct node{
	int val,id,i;
} e[N*3];
bool cmp(node a,node b){
	return a.val>b.val;
}
int cnt[4],vis[N*3];
void clean2(){
	m=0;
	ans=0;
	for(int i=1;i<=n;i++){
		vis[i]=0;
	}
	cnt[1]=cnt[2]=cnt[3]=0;
}
void solve(){
	ans=0;
	int flg1=0,flg2=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=3;j++){
			scanf("%lld",&a[i][j]);
		}
		if(a[i][2]==0&&a[i][3]==0)	flg1++;
		if(a[i][3]==0)	flg2++;
	}
	if(flg1==n){
		for(int i=1;i<=n;i++){
			temp[i]=a[i][1];
		}
		sort(temp+1,temp+n+1);
		for(int i=n;i>n/2;i--){
			ans+=temp[i];
		}
		cout<<ans<<endl;
	}

	else{
		clean2();
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				ans+=a[i][j];
			}
			e[++m]={a[i][1]-a[i][2]-a[i][3],1,i};
			e[++m]={a[i][2]-a[i][1]-a[i][3],2,i};
			e[++m]={a[i][3]-a[i][1]-a[i][2],3,i};
		}
		sort(e+1,e+m+1,cmp);
		for(int i=1;i<=m;i++){
			int val=e[i].val,u=e[i].i,id=e[i].id;
			if(cnt[id]==n/2||vis[u])	continue;
			vis[u]=1;
			cnt[id]++;
			ans+=val;
		}
		cout<<ans/2<<endl;
	}
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&T);
	while(T--){
		scanf("%lld",&n);
		if(n>200){
			solve();
		}
		else{
			clean();
			for(int i=1;i<=n;i++){
				for(int j=1;j<=3;j++){
					scanf("%lld",&a[i][j]);
				}
			}
			f[0][0][0]=0;
			for(int i=1;i<=n;i++){
				for(int j=0;j<=i;j++){
					for(int k=0;k+j<=i;k++){
						int w=i-j-k;
						if(w<0)	continue;
						if(j>0)	f[i][j][k]=max(f[i][j][k],f[i-1][j-1][k]+a[i][1]);
						if(k>0)	f[i][j][k]=max(f[i][j][k],f[i-1][j][k-1]+a[i][2]);
						if(w>0)	f[i][j][k]=max(f[i][j][k],f[i-1][j][k]+a[i][3]);
					}
				}
			}
			for(int j=0;j<=n/2;j++){
				for(int k=0;k<=n/2;k++){
					int w=n-j-k;
					if(w>n/2)	continue;
					if(w<0)	continue;
					ans=max(ans,f[n][j][k]);
				}
			}
			cout<<ans<<endl;
		}
	}
	return 0;
} 
//////Ren5Jie4Di4Ling5%


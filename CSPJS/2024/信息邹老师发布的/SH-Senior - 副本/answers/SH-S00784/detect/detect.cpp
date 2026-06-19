#include<bits/stdc++.h>
using namespace std;
bool f[50][50],ff[50],fff[50][50];
int ans1=0,ans2=0,n,m;
void dfs(int i,int sum){
	if(i==m+1){
		bool ffff[50];
		memset(ffff,0,sizeof ffff);
		for(int j=1;j<=m;j++){
			for(int k=1;k<=n;k++){
				if(fff[j][k]) ffff[k]=1; 
			}	
		}
		int sum2=0;
		for(int j=1;j<=n;j++) if(ffff[j]) sum2++;
		if(sum2==ans1) ans2=max(sum,ans2);
		return;
	}
	for(int k=1;k<=n;k++){
		if(f[i][k]) fff[i][k]=0;
	}
	dfs(i+1,sum+1);
	for(int k=1;k<=n;k++){
		if(f[i][k]) fff[i][k]=1;
	}
	dfs(i+1,sum);
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		int l,xv,d[100005],v[100005],a[100005],p[100005];
		ans2=0;
		ans1=0;
		memset(d,0,sizeof d);
		memset(v,0,sizeof v);
		memset(a,0,sizeof a);
		memset(p,0,sizeof p);
		cin>>n>>m>>l>>xv;
		for(int i=1;i<=n;i++) scanf("%d%d%d",&d[i],&v[i],&a[i]);
		for(int i=1;i<=m;i++) scanf("%d",&p[i]);
		if(n<=20&&m<=20){
			memset(f,1,sizeof f);
			memset(ff,0,sizeof ff);
			memset(fff,1,sizeof fff);
			for(int i=1;i<=m;i++){
				for(int j=1;j<=n;j++){
					if(d[j]>p[i]){
						f[i][j]=0;
						fff[i][j]=0;
						continue;
					}
					if(v[j]*v[j]+2*a[j]*(p[i]-d[j])<=0){
						f[i][j]=0;
						fff[i][j]=0;
						continue;
					} 
					int sd=sqrt(v[j]*v[j]+2*a[j]*(p[i]-d[j]));
					if(sd<=xv){
					 	f[i][j]=0;	
					 	fff[i][j]=0;
					}
					else ff[j]=1;
			 }
			}
			for(int i=1;i<=n;i++) if(ff[i]) ans1++;
			cout<<ans1<<" ";
			dfs(1,0);
			cout<<ans2<<endl;
		}
		else{
			for(int i=1;i<=n;i++){
				if(d[i]>p[m]) continue;
				if(v[i]>xv) ans1++;
			}
			if(ans1==0) m++;
			printf("%d %d",ans1,m-1);
			cout<<endl;
		}
	}
}

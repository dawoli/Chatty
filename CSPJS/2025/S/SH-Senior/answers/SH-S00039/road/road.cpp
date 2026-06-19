#include<bits/stdc++.h>
#define int long long
using namespace std;
const int M=1e6+19,N=1e4+19,K=19,Inf=1e15+9;
int n,m,k,uu,vv,ww,aa,c[K],fa[N],ans=Inf;
struct to{
	int u,v,w;
	bool operator <(const to &other)const{
		return w<other.w;
	}
}a[M],kk[K][N];
int too(int i){
	if(fa[i]==i) return i;
	else{
		fa[i]=too(fa[i]);
		return fa[i];
	}
}
int cal(int ii){
	int ccnt=0,cnt[K],b[K]={},minn,summ=0;
	for(int j=0;j<=k;j++)cnt[j]=1;
	for(int j=0;j<=k-1;j++)
		if((ii>>(j))%2==1)b[++ccnt]=j+1,summ+=c[j+1];
	for(int i=0;i<=n+k;i++)fa[i]=i;
	kk[k+1][0].w=Inf;cnt[k+1]=0;
	for(int i=0;i<n-1+ccnt;){
		minn=k+1;
		for(int j=1;j<=ccnt;j++){
			if(kk[j][cnt[j]].w<kk[minn][cnt[minn]].w&&cnt[j]<=n){
				minn=j;
			}
		}
		if((kk[minn][cnt[minn]].w<a[cnt[0]].w||cnt[0]>m)&&minn!=k+1){
			int l=too(kk[minn][cnt[minn]].u),r=too(kk[minn][cnt[minn]].v);
			if(l!=r){
				i++;summ+=kk[minn][cnt[minn]].w;
				fa[min(l,r)]=max(l,r);
			}
			cnt[minn]++;
		}
		else{
			int l=too(a[cnt[0]].u),r=too(a[cnt[0]].v);
			if(l!=r){
				i++;summ+=a[cnt[0]].w;
				fa[min(l,r)]=max(l,r);
			}
			cnt[0]++;
		}
	}
	return summ;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>uu>>vv>>ww;
		a[i].u=uu;a[i].v=vv;a[i].w=ww;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>aa;
			kk[i][j].u=n+i;
			kk[i][j].v=j;
			kk[i][j].w=aa;
		}
	}
	sort(a+1,a+m+1);
	for(int i=1;i<=k;i++)sort(kk[i]+1,kk[i]+n+1);
	for(int i=0;i<(1<<k);i++){
		ans=min(ans,cal(i));
	}
	cout<<ans;
	return 0;
} 

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=(1<<17);
int T,n,m,A[N],c[N],X[4];
int a[N*2],wn[N*2],lv[N*2],mn[N*2],lim[N*2],b[N*2]; char d[2*N],str[N];
ll sum[N*2];
vector<int> vec[N],vecr[N],ve[N];
bool vis[N*2],f[N*2];

void dfs(int x,int id,int l,int r,int p){
	
//	cout<<x<<" "<<id<<" "<<l<<" "<<r<<" "<<p<<endl;
	int mid=l+r>>1;
	if(l==0&&mid>=p&&l!=r){
		dfs(x<<1,id,l,mid,p);
		return;
	}
	vec[id].emplace_back(x);
	if(l>p) return;
	if(r<=p){
		ve[id].emplace_back(x);
		return;
	}
	dfs(x<<1,id,l,mid,p);
	dfs(x<<1|1,id,mid+1,r,p);
}

int main(){
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i) scanf("%d",A+i);
	for(int i=1;i<=m;++i) scanf("%d",c+i),c[i]-=1;
	int K=1; while(K<n) K<<=1;
	int R=log2(K);
	for(int i=K/2;i;i>>=1){
		scanf("%s",str);
		for(int j=i;j<=i*2-1;++j) d[j]=str[j-i]-'0';
	}
	for(int i=K;i<=K*2-1;++i) sum[i]=i-K+1,mn[i]=i-K;
	for(int i=K-1;i;--i){
		lv[i]=lv[i<<1]+1;
		sum[i]=sum[i<<1]+sum[i<<1|1];
		mn[i]=min(mn[i<<1],mn[i<<1|1]);
	}
	cin>>T;
//	cout<<T<<endl;
	for(int i=1;i<=m;++i){
		dfs(1,i,0,K-1,c[i]);
		vecr[i]=vec[i];
	//	cout<<vec[i].size()<<endl;
		reverse(vec[i].begin(),vec[i].end());
	}
	while(T--){
		memset(a,0,sizeof(a));
	//	memset(sum2,0,sizeof(sum2));
		for(int i:{0,1,2,3}) scanf("%d",X+i);
		for(int i=1;i<=n;++i) a[K+i-1]=min(A[i]^X[i&3],R),wn[K+i-1]=i;
		for(int i=K-1;i;--i){
			if(d[i]) a[i]=(a[i<<1|1]>=lv[i])?a[i<<1|1]:a[i<<1],wn[i]=(a[i<<1|1]>=lv[i])?wn[i<<1|1]:wn[i<<1];
			else a[i]=(a[i<<1]>=lv[i])?a[i<<1]:a[i<<1|1],wn[i]=(a[i<<1]>=lv[i])?wn[i<<1]:wn[i<<1|1];
		//	for(int j=0;j<=R;++j) sum2[i][j]=sum2[i][j<<1]+sum2[i][j<<1|1];
		}
	//	for(int x=1;x<=K*2-1;++x)
	//		for(int j=R-1;~j;--j) sum2[x][j]+=sum2[x][j+1];
		ll ans=0;
		for(int i=1;i<=m;++i){
			ll res=0;
			for(int x:ve[i]) vis[x]=1;
			for(int x:vec[i]){
				if(mn[x]>c[i]) b[x]=(1<<(R+1))-1;
				else if(vis[x]) b[x]=1<<a[x];
				else{
					int u=(d[x]?b[x<<1|1]:b[x<<1]);
					int v=(d[x]?b[x<<1]:b[x<<1|1]);
					b[x]=((u>>lv[x])<<lv[x])|((!!(u&((1<<lv[x])-1)))*v);
				}
			}
			f[vecr[i][0]]=1,lim[vecr[i][0]]=0;
			for(int x:vecr[i]){
				if(mn[x]>c[i]) res+=f[x]*sum[x];
				else if(vis[x]) res+=f[x]*(a[x]>=lim[x])*wn[x];
				else{
					int u=(d[x]?(x<<1|1):(x<<1));
					int v=(d[x]?(x<<1):(x<<1|1));
					f[v]=(f[x]&&(!!((b[u]&((1<<lv[x])-1)))));
					f[u]=f[x];
					lim[v]=lim[x];
					lim[u]=max(lim[x],lv[x]);
				}
			}
			for(int x:ve[i]) vis[x]=0;
			ans^=(res*i); 
		}
		printf("%lld\n",ans);
	}
	return 0;
}

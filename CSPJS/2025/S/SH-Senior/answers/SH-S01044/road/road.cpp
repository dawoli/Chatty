#include <bits/stdc++.h>
using namespace std;
struct node{
	long long x,y,w;
};
long long n,m,k,len,ans=1e9,f=1;
node a[1000005],b[1000005],ab[1000005];
long long c[10005],czh[15][10005],fa[10005],dis[1005][1005];
bool cmp(node x,node y){
	return x.w<y.w; 
}
long long get(long long x){
	if(x==fa[x])return x;
	return fa[x]=get(fa[x]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.ans","w",stdout);
	memset(dis,0x3f,sizeof(dis));
	scanf("%lld%lld%lld",&n,&m,&k);
	for(long long i=1;i<=m;i++){
		long long x,y,w;
		scanf("%lld%lld%lld",&x,&y,&w);
		a[++len]=(node){x,y,w};
		dis[x][y]=dis[y][x]=w;
	}
	for(long long i=1;i<=k;i++){
		scanf("%lld",&c[i]);
		if(c[i]!=0)f=0;
		for(long long j=1;j<=n;j++){
			scanf("%lld",&czh[i][j]);
		}
	}
	for(long long i=1;i<=n;i++){
		fa[i]=i;
	}
	if(k==0){
		long long sum=0;
		sort(a+1,a+1+len,cmp);
		long long cnt=0;
		for(long long j=1;j<=len;j++){
			if(get(a[j].x)==get(a[j].y))continue;
			fa[get(a[j].x)]=get(a[j].y);
			sum+=a[j].w;
			cnt++;
			if(cnt==n-1)break;
		}
		printf("%lld\n",sum);
		return 0;
	}
	if(f==1){
		for(long long i=1;i<=n;i++){
			dis[i][i]=0;
		}
		for(long long i=1;i<=k;i++){
			for(long long j=1;j<=n;j++){
				for(long long l=1;l<=n;l++){
					if(k==l)continue;
					dis[j][l]=min(dis[j][l],czh[i][j]+czh[i][l]);
					dis[l][j]=dis[j][l];
				}
			}
		}
		for(long long i=1;i<=n;i++){
			for(long long j=i+1;j<=n;j++){
				a[++len]=(node){i,j,dis[i][j]};
	//			cout<<i<<" "<<j<<" "<<dis[i][j]<<endl;
			}
	//		cout<<endl;
		}
		sort(a+1,a+1+len,cmp);
		long long sum=0,cnt=0;
		for(long long j=1;j<=len;j++){
			if(get(a[j].x)==get(a[j].y))continue;
			fa[get(a[j].x)]=get(a[j].y);
			sum+=a[j].w;
			cnt++;
			if(cnt==n-1)break;
		}
		printf("%lld\n",sum);
		return 0;
	}
	for(long long i=0;i<=((1<<k)-1);i++){//城镇化的情况 
		long long sum=0,len1=0;
		for(long long i=1;i<=n;i++){
			fa[i]=i;
		}
		for(long long j=0;j<k;j++){
			if(i&(1<<j)){
				sum+=c[j+1]+czh[j+1][j+1];
				for(long long l=1;l<=n;l++){
					if(l==j+1)continue;
					b[++len1]=(node){j+1,l,czh[j+1][l]};
				}
			}
		}
		for(long long j=1;j<=len;j++){
			ab[j]=a[j];
		}
		for(long long j=1;j<=len1;j++){
			ab[len+j]=b[j];
		}
		long long newlength=len1+len;
		long long cnt=0;
		sort(ab+1,ab+1+len1+len,cmp); 
//		for(long long j=1;j<=len+len1;j++){
//			cout<<ab[j].x<<" "<<ab[j].y<<" "<<ab[j].w<<endl;
//		}
//		cout<<endl;
		for(long long j=1;j<=newlength;j++){
			if(get(ab[j].x)==get(ab[j].y))continue;
			fa[get(ab[j].x)]=get(ab[j].y);
			sum+=ab[j].w;
			cnt++;
			if(cnt==n-1)break;
		}
		ans=min(ans,sum);
	}
	printf("%lld",ans);
} 


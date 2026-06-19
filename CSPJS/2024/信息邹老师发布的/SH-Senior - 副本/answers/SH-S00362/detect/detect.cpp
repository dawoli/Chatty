#include<bits/stdc++.h>
using namespace std;
int t,n,m,l,v,pos[100009],ok,ans,cnt,tot,now=1;
int dp[100009],maxt[100009];

struct Car{
	int d,v,a;
}arr[100009];

bool check(Car car,int p){
	if(car.v*car.v+2*car.a*(pos[p]-car.d)<0) return 0;
	double vt=sqrt(car.v*car.v+2*car.a*(pos[p]-car.d));
	return vt>v;
}

struct Edge{
	int l,r;
	bool operator<(const Edge &e)const{
		return r==e.r?l<e.l:r<e.r;
	}
}edge[100009];

int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d%d%d%d",&n,&m,&l,&v);
		now=1,cnt=0,ans=0,ok=0,tot=0;
		memset(maxt,0,sizeof(maxt));
		for(int i=1;i<=n;i++) scanf("%d%d%d",&arr[i].d,&arr[i].v,&arr[i].a);
		for(int i=1;i<=m;i++) scanf("%d",&pos[i]);
		sort(pos+1,pos+m+1);
//		cout<<check(arr[n],m)<<endl;
		for(int i=1;i<=n;i++){
			if(arr[i].d>pos[m]) continue;
			if(arr[i].a>0){
				int x,l=lower_bound(pos+1,pos+m+1,arr[i].d)-pos,r=m,y=m;
				if(!check(arr[i],r)) continue;
				ans++;
				while(l<=r){
					int mid=(l+r)>>1;
					if(check(arr[i],mid)) r=mid-1,x=mid;
					else l=mid+1;
				}
				edge[++tot].l=x,edge[tot].r=y;
//				cout<<i<<endl;
			}
			else if(arr[i].a==0){
				if(arr[i].v>v) ans++,edge[++tot].l=lower_bound(pos+1,pos+m+1,arr[i].d)-pos,edge[tot].r=m;
			}
			else{
				int x=lower_bound(pos+1,pos+m+1,arr[i].d)-pos,l=x,r=m,y=0;
				if(!check(arr[i],l)) continue;
				ans++;
				while(l<=r){
					int mid=(l+r)>>1;
					if(check(arr[i],mid)) l=mid+1,y=mid;
					else r=mid-1;
				}
				edge[++tot].l=x,edge[tot].r=y;
//				cout<<i<<endl;
			}
		}
		sort(edge+1,edge+tot+1);
//		for(int i=1;i<=tot;i++){
//			cout<<edge[i].l<<' '<<edge[i].r<<endl;
//		}
		for(int i=1;i<=tot;i++){
//			if(edge[i].r==m&&ok) continue;
			int la=max(maxt[now-1],dp[i-1]);
			for(;now<edge[i].r;now++) maxt[now]=la;
			dp[i]=maxt[edge[i].l-1]+1;
			cnt=max(cnt,dp[i]);
			
//			for(int j=1;j<=m;j++)  cout<<maxt[j]<<' ';
//			cout<<now<<endl;
		}
//		for(int i=1;i<=tot;i++) cout<<dp[i]<<' ';
//		cout<<endl;
		cnt+=ok;
		printf("%d %d\n",ans,m-cnt);
	}
	return 0;
	
}


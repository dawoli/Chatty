#include<bits/stdc++.h>
using namespace std;
int t;
int n,m,l,v;
int p[100010];
struct node{
	int d,v,a;
}car[100010];
double speed(int a,int v,int s){
	return sqrt((double)(v*v*1.0+2*a*s*1.0)*1.0);
}
int a[100010];
int b[100010];
struct node1{
	int l[3010],cnt,val;
}k[3010];
int ans;
bool cmp(node1 a,node1 b){
	return a.cnt>b.cnt;
}
bool cmp1(node1 a,node1 b){
	return a.val>b.val;
}
int pd=0;
void solve(){
	sort(p+1,p+m+1);
	ans=0;
	memset(k,0,sizeof(k));
	memset(a,0,sizeof(a));
	for(int i=1;i<=n;i++){
		int jl=0;
		for(int j=1;j<=m;j++){
			if(p[j]<car[i].d) continue;
			double s=speed(car[i].a,car[i].v,p[j]-car[i].d);
			if(2*car[i].a*(p[j]-car[i].d)<0 && abs(2*car[i].a*(p[j]-car[i].d))>car[i].v*car[i].v) continue;
			if(s>v){
				k[j].l[++k[j].cnt]=i;
				if(jl==0){
					ans++,jl=1;
				}
			}
		}
	}
	cout<<ans<<" ";
	ans=m;
	int maxm=-1;
	sort(k+1,k+m+1,cmp);
	for(int i=1;i<=m;i++){
		for(int j=1;j<=k[i].cnt;j++) a[k[i].l[j]]=1;
		for(int j=i+1;j<=m;j++){
			k[j].val=0;
			for(int l=1;l<=k[j].cnt;l++){
				if(a[k[j].l[l]]==0) k[j].val++;
			}
		}
		sort(k+i+1,k+m+1,cmp1);
	}
	memset(a,0,sizeof(a));
	for(int i=1;i<=m;i++){
		int jl=0;
		for(int j=1;j<=k[i].cnt;j++){
			if(a[k[i].l[j]]==0){
				a[k[i].l[j]]=1;
				jl=1;
			}
		}
		if(jl==0) ans--;
	}
	cout<<m-ans<<endl;
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>t;
	while(t--){
		pd=0,ans=0;
		scanf("%d%d%d%d",&n,&m,&l,&v);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&car[i].d,&car[i].v,&car[i].a);
			if(car[i].a!=0) pd=1;
			if(car[i].v>v) ans++;
		}
		for(int i=1;i<=m;i++){
			scanf("%d",&p[i]);
		}
		if(!pd){
			printf("%d %d\n",ans,(ans==0 ? m:m-1));
			continue;
		}
		solve();
	}
	return 0;
}
//30~60

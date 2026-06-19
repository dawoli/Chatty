#include<bits/stdc++.h>
using namespace std;
const long double eps=1e-4;
struct info{
	long double l,r;
	int id;//0为数据 
}q[1000005];
bool valid[1000005],tab[1000005],choose[1000005];
int p[1000005],normal,ans;
vector<int> ge[1000005];
int T,n,m,l,V,cnt;
int solve(){
	int ans=0;
	for(int i=1;i<=m;i++)
		for(int j=1;j<=cnt;j++) if(choose[i]&&q[j].l<=p[i]&&q[j].r>=p[i]) valid[j]=1;
	for(int i=1;i<=cnt;i++) ans+=valid[i];	
	return ans;
}
void dfs(int x){
	if(x==m+1){
		int cnt=0;
		for(int i=1;i<=25;i++) valid[i]=0;
		int test=solve();
		if(test==normal){
			for(int i=1;i<=m;i++) if(!choose[i]) cnt++;
			ans=max(ans,cnt);
		}
		return;
	}
	choose[x]=1;
	dfs(x+1);
	choose[x]=0;
	dfs(x+1);
}
//n车辆数量、m测速仪数量、l主干道长度和V道路限速
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n>>m>>l>>V;
		cnt=0;
		ans=0;
		for(int i=1;i<=25;i++) tab[i]=0;
		for(int i=1;i<=25;i++) choose[i]=0;
		for(int i=1;i<=25;i++) valid[i]=0;
		for(int i=1;i<=n;i++){
			long double d,v,a,dis,left,right;
			bool lv,rv;
			cin>>d>>v>>a;
			if(v<=V&&a<=0) continue;
			else if(v>=V&&a>=0) left=d,right=l,lv=1,rv=1;
			else{
				dis=(V*V-v*v)/(2*a);
				if(a<0){
					left=d;
					if(d+dis>l) right=l;
					else right=d+dis-eps;
				}
				else{
					if(l<d+dis) continue;
					left=d+dis+eps;
					right=l;
				}
			}
			q[++cnt]=(info){left,right,0};
		}
		for(int i=1;i<=m;i++) cin>>p[i],choose[i]=1;
		normal=solve();
		cout<<normal<<" ";
		dfs(1);
		cout<<ans<<endl;
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
const int N=100009;
struct car{
	int d,v,a;
};
car c[N];
int T,n,m,L,V,p[N],ans1,ans2,state[N],ok1[N],ok2[N];
vector<int> to[N];
void dfs(int x,int cnt){
	if(x==m+1){
		for(int i=1;i<=n;i++) ok2[i]=ok1[i];
		for(int i=1;i<=m;i++){
			if(state[i]==0) continue; 
			for(int j=0;j<to[i].size();j++) ok2[to[i][j]]=1;
		}
		int flag=1;
		for(int i=1;i<=n;i++)
			if(ok2[i]==0){
				flag=0;
				break;
			}
		if(flag==1){
			ans2=max(ans2,cnt);
		}
		return;
	}
	state[x]=0;
	dfs(x+1,cnt+1);
	state[x]=1;
	dfs(x+1,cnt);
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	scanf("%d",&T);
	for(int k=1;k<=T;k++){
		ans1=0;
		ans2=0;
		scanf("%d %d %d %d",&n,&m,&L,&V);
		for(int i=1;i<=n;i++) scanf("%d %d %d",&c[i].d,&c[i].v,&c[i].a);
		for(int i=1;i<=m;i++) scanf("%d",&p[i]);
		sort(p+1,p+m+1);
		if(n<=20&&m<=20){
			for(int i=1;i<=n;i++) ok1[i]=0;
			for(int i=1;i<=m;i++){
				while(to[i].size()) to[i].clear();
			}
			for(int i=1;i<=n;i++){
				if(c[i].a==0){
					if(c[i].v>V&&c[i].d<=p[m]){
						ans1++;
						int l=lower_bound(p+1,p+m+1,c[i].d)-p;
						for(int j=l;j<=n;j++) to[j].push_back(i);
					}
					else ok1[i]=1;
				}
				else if(c[i].a>0){
					if(p[m]<c[i].d) continue;
					int s=p[m]-c[i].d;
					double vt=sqrt(c[i].v*c[i].v+2*c[i].a*s);
					if(vt>V){
						ans1++;
						double dd=c[i].d+(V*V-c[i].v*c[i].v)/(2*c[i].a);
						int l=upper_bound(p+1,p+m+1,dd)-p;
						for(int j=l;j<=n;j++) to[j].push_back(i);
					}
					else ok1[i]=1;
				}
				else{
					int pos=lower_bound(p+1,p+m+1,c[i].d)-p;
					int s=p[pos]-c[i].d;
					double vt=sqrt(c[i].v*c[i].v+2*c[i].a*s);
					if(vt>V){
						ans1++;
						double ss=c[i].d+(V*V-c[i].v*c[i].v)/(2.0*c[i].a);
						int pos2;
						if(ss>L) pos2=n;
						else pos2=lower_bound(p+1,p+m+1,ss)-p-1;
						for(int j=pos;j<=pos2;j++) to[j].push_back(i);
					}
					else ok1[i]=1;
				}
			}
			dfs(1,0);
			printf("%d ",ans1);
			printf("%d\n",ans2);
			continue;
		}
		int tag=0;
		for(int i=1;i<=n;i++)
			if(c[i].a!=0){
				tag=1;
				break;
			}
		if(tag==0){
			for(int i=1;i<=n;i++)
				if(c[i].v>V&&c[i].d<=p[m]) ans1++;
			if(ans1!=0) ans2=m-1;
			else ans2=m;
			printf("%d ",ans1);
			printf("%d\n",ans2);
			continue;
		}
		int tag2=0;
		for(int i=1;i<=n;i++)
			if(c[i].a<=0){
				tag2=1;
				break;
			}
		if(tag2==0){
			for(int i=1;i<=n;i++){
				if(p[m]<c[i].d) continue;
				int s=p[m]-c[i].d;
				double vt=sqrt(c[i].v*c[i].v+2*c[i].a*s);
				if(vt>V) ans1++;
			}
			if(ans1!=0) ans2=m-1;
			else ans2=m;
			printf("%d ",ans1);
			printf("%d\n",ans2);
			continue;
		}
	}
	return 0;
}

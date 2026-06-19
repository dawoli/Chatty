#include<bits/stdc++.h>
using namespace std;
int T,n,m,L,V,v[100005],a[100005],p[100005],last,ans,aans;
bool flag,flag1,l[100005],op[100005];
int d[100005];
map<int,int> mp; 
void DFS(int now){
	if(now>m){
		last=flag=0;
		for(int i=1;i<=m;i++){
			if(!op[i])continue;
			last=max(last,p[i]);
		}
		for(int i=1;i<=n;i++){
			if(!l[i])continue;
			if(a[i]>=0){
				if(last<d[i]){
					flag=1;
					break;
				}
			}
			else{
				double x=d[i]+(V*V-v[i]*v[i])*1.0/2/(a[i]*1.0);
				int P=lower_bound(p+1,p+m+1,x)-p,Q=lower_bound(p+1,p+m+1,d[i])-p;
				bool flagf=0;
				for(;Q<P;Q++){
					flagf|=op[Q];
				}
				if(!flagf){
					flag=1;
					break;
				}
			}
		}
		if(!flag){
			int cnt=0;
			for(int i=1;i<=m;i++)cnt+=(op[i]==0);
			aans=max(aans,cnt);
		}
		return;
	}
	op[now]=0;
	DFS(now+1);
	op[now]=1;
	DFS(now+1);
	return;
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>T;
	while(T--){
		flag=flag1=1;
		ans=aans=last=0;
		scanf("%d%d%d%d",&n,&m,&L,&V);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&d[i],&v[i],&a[i]);
			flag=flag&&(a[i]>=0);
		}
		for(int i=1;i<=m;i++){
			scanf("%d",&p[i]);
			last=max(last,p[i]);
		}
		if(flag){
			for(int i=1;i<=n;i++){
				if(v[i]<=V&&a[i]==0||d[i]>last)continue;
				if(a[i]>0){
					double x=d[i]+(V*V-v[i]*v[i])*1.0/2/(a[i]*1.0);
					if(x>=last*1.0)continue;
				}
				ans++;
			}
			cout<<ans<<' '<<max(m-1,m-ans)<<endl;
		}
		else{
			sort(p+1,p+m+1); 
			for(int i=1;i<=n;i++){
				if(a[i]==0){
					if(v[i]>V&&d[i]<=last){
						l[i]=1;
						ans++;
					}
				} 
				else if(a[i]>0){
					double x=d[i]+(V*V-v[i]*v[i])*1.0/2/(a[i]*1.0);
					if(x<last*1.0){
						l[i]=1;
						d[i]=x;
						ans++;
					}
				} 
				else{
					if(v[i]>V){
						double x=d[i]+(V*V-v[i]*v[i])*1.0/2/(a[i]*1.0);
						int y=lower_bound(p+1,p+m+1,x)-lower_bound(p+1,p+m+1,d[i]);
						if(y){
							l[i]=1;
							ans++;
						}
					}
				}
			}
			cout<<ans<<' ';
			DFS(1); 
			cout<<aans-1<<endl;
		}
	}
	return 0;
} 

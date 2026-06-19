#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int T,n,m,L,V,d,v,a,p[N],vis[N],ans2=99999;
double Before[N],After[N];
bool erfen_hou(int l,int r,double after){
	if(l==r){
		return true;
	}
	if(l>r)return false;
	int mid=(l+r)>>1;
	bool ans=false;
	if(p[mid]<after){
		ans=(ans||erfen_hou(mid+1,r,after));
	}
	if(p[mid]>after){
		ans=(ans||erfen_hou(l,mid,after));
	}
	return ans;
}
bool erfen_range(int l,int r,double after,double before){
	if(l==r){
		if(p[l]>after&&p[l]<before)return true;
		else return false;
	}
	if(l>r)return false;
	bool ans=false;
	int mid=(l+r)>>1;
	if(before<p[mid]){
		ans=(ans||erfen_range(l,mid,after,before));
	}
	if(after<p[mid]&&before>p[mid]){
		ans=(ans||erfen_range(l,mid,after,before));
		ans=(ans||erfen_range(mid+1,r,after,before));
	}
	if(after>p[mid]){
		ans=(ans||erfen_range(mid+1,r,after,before));
	}
	return ans;
}
vector<int>g[N];
int sum=0;
//void dfs(int x){
//	if(x==m+1){
//		ans2=min(ans2,sum);
//		return ;
//	}
//	for(int i=x;i<=m;i++){
//		bool tag=false;
//		for(int j=0;j<g[x].size();j++){
//			if(vis[g[x][j]]==1){
//				vis[g[x][j]]=-1;
//				tag=true;
//			}
//		}
//		if(tag==true){
//			sum++;
//			dfs(x+1);
//		}
//		for(int j=0;j<g[x].size();j++){
//			if(vis[g[x][j]]==-1){
//				vis[g[x][j]]=1;
//				tag=true;
//			}
//		}
//		dfs(x+1);
//	}
//}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>T;
	while(T--){
		memset(g,0,sizeof(g));
		bool A=true;
		bool B=true;
		bool C=true;
		int ans1=0;
		memset(vis,0,sizeof(vis));
		memset(p,0,sizeof(p));
		for(int i=1;i<=N;i++){
			Before[i]=-1;
			After[i]=1000005;
		}
		scanf("%d%d%d%d",&n,&m,&L,&V);
		for(int i=1;i<=n;i++){
			cin>>d>>v>>a;
			if(a!=0)A=false;
			if(a<=0)B=false;
			if(a>=0)C=false;
			if(v<=V&&a<=0){
				continue;
			}
			else {
				if(a==0){
					After[i]=(double)d-0.0001;
				}
				if(a<0){
					After[i]=(double)d-0.0001;
					Before[i]=(double)d+(double)(V*V-v*v)/(double)(2*a)-0.0001;
				}
				if(a>0){
					if(v>V){
						After[i]=(double)d-0.0001;
					}
					else After[i]=(double)d+(double)(V*V-v*v)/(double)(2*a)+0.0001;
				}
			}
		}
		for(int i=1;i<=m;i++){
			cin>>p[i];
		}
		for(int i=1;i<=n;i++){
			if(Before[i]!=-1&&After[i]!=1000005){
				if(erfen_range(1,m,After[i],Before[i])==true){
					ans1++;
					vis[i]=1;
				}
			}
			else if(After[i]!=1000005){
				if(erfen_hou(1,m,After[i])==true){
					ans1++;
					vis[i]=1;
				}
			}
		}
		ans2=0;
		if(A==true||B==true){
			ans2=m;
			for(int i=1;i<=n;i++){
				if(p[m]>After[i]){
					ans2--;
					break;
				}
			}
		}
		else {
			for(int i=1;i<=n;i++){
				if(vis[i]==1){
					for(int j=1;j<=m;j++){
						if(After[i]!=1000005&&Before[i]!=-1){
							if(p[j]>After[i]&&p[j]<Before[i]){
								g[j].push_back(i);
							}
						}
						else if(After[i]!=1000005){
							if(p[j]>After[i]){
								g[j].push_back(i);
							}
						}
					}
				}
			}
//			dfs(1);
			for(int i=1;i<m;i++){
				for(int j=i+1;j<=m;j++){
					if(g[j].size()>g[j].size()){
						swap(g[j],g[i]);
					}
				}
			}
			for(int i=1;i<=m;i++){
				bool tag=false;
				for(int j=0;j<g[i].size();j++){
					if(vis[g[i][j]]==1){
						vis[g[i][j]]=0;
						tag=true;
					}
				}
				if(tag==true)ans2++;
			}
			ans2=m-ans2;
		}
		cout<<ans1<<" "<<ans2<<"\n";
	}
	return 0;
}

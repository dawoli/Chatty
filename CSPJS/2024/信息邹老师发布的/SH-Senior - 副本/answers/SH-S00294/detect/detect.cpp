#include<bits/stdc++.h>
using namespace std;
#define N 100005
int t,n,m;
int L,V,d[N],v[N],a[N],p[N],b[N],e[N];
int vis[10*N];
bool yes[25];
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>t;
	while(t--){
		memset(b,0,sizeof(b));
		memset(e,0,sizeof(e));
		memset(vis,0,sizeof(vis));
		cin>>n>>m>>L>>V;
		for(int i=1;i<=n;i++){
			cin>>d[i]>>v[i]>>a[i];
			if(a[i]==0&&v[i]>V){
				b[i]=d[i];e[i]=L;
			}
			if(a[i]>0){
				b[i]=(V*V-v[i]*v[i])/(2*a[i])+d[i]+1;
				b[i]=max(b[i],d[i]);
				if(b[i]>L)b[i]=0;
				else e[i]=L;
			}
			if(a[i]<0&&v[i]>V){
				b[i]=d[i];
				e[i]=(V*V-v[i]*v[i])/(2*a[i])+d[i];
				if((V*V-v[i]*v[i])%(2*a[i])==0)e[i]--;
				e[i]=min(L,e[i]);
			}
		}
		for(int i=1;i<=m;i++){
			cin>>p[i];
			vis[p[i]]=i;
		}
		if(n<=20&&m<=20){
			int ct1=0,ans=0;
			vector<int> vec[25];
			for(int i=1;i<=n;i++){
				bool flag=0;
				for(int j=b[i];j<=e[i];j++){
					if(vis[j]){
						vec[vis[j]].push_back(i);
						flag=1;
					}
				}
				if(flag)ct1++;
			}
			cout<<ct1<<" ";
			for(int i=0;i<=(1<<m)-1;i++){
				int ct2=0;
				int tmp=i,num=0;
				memset(yes,0,sizeof(yes));
				for(int j=1;j<=m;j++){
					if(tmp%2==1){
						for(int k=0;k<vec[j].size();k++){
							int u=vec[j][k];
							if(!yes[u]){
								yes[u]=1;
								num++;
							}
						}
					}
					else ct2++;
					tmp>>=1;
				}
				if(num==ct1)ans=max(ans,ct2);
			}
			cout<<ans<<"\n";
		}
		else if(a[1]>=0){
			int ct=0;
			for(int i=1;i<=n;i++){
				if(b[i]&&b[i]<=p[m])ct++;
			}
			cout<<ct<<" ";
			if(ct)
			cout<<m-1;
			else cout<<m;
			cout<<"\n";
		}
		else{
			
		}
	}
	return 0;
}

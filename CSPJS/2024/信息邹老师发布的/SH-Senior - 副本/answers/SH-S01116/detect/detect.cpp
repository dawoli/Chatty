#include <bits/stdc++.h>
using namespace std;
int T;
int d[100010],v[100010],a[100010];
double l[100010],r[100010];
int mnt[100010];
int n,m,L,V;
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		bool pf=1;
		scanf("%d%d%d%d",&n,&m,&L,&V);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&d[i],&v[i],&a[i]);
			if(a[i]!=0)pf=0;
		}
		int mxmx=0;
		for(int i=1;i<=m;i++){
			scanf("%d",&mnt[i]);
			mxmx=max(mxmx,mnt[i]);
		}
		if(!pf){
			for(int i=1;i<=n;i++){
				if(a[i]==0){
					if(v[i]<=V)l[i]=L+1,r[i]=L+1;
					else l[i]=d[i],r[i]=L;
				}
				else if(a[i]<0){
					if(v[i]<=V)l[i]=L+1,r[i]=L+1;
					else l[i]=d[i],r[i]=d[i]+1.0*(1ll*V*V-1ll*v[i]*v[i])/2.0/a[i]; 
				}
				else if(a[i]>0){
					if(1ll*v[i]*v[i]+2*a[i]*(L-d[i])<=1ll*V*V)l[i]=L+1,r[i]=L+1;
					else if(v[i]>V)l[i]=d[i],r[i]=L+1;
					else l[i]=d[i]+1.0*(1ll*V*V-1ll*v[i]*v[i])/2.0/a[i],r[i]=L; 
				}
			}
		}
		int ans1=0;
		if(pf){
			for(int i=1;i<=n;i++){
				if(v[i]>V&&d[i]<=mxmx)ans1++;
			}
			cout<<ans1<<" ";
		}
		else{
			for(int i=1;i<=n;i++){
				for(int j=1;j<=m;j++){
					if(l[i]<=mnt[j]&&mnt[j]<=r[i]){
						ans1++;
	//					cout<<i<<" "<<j<<endl;
						break;
					}
				}
			}
			cout<<ans1<<" ";
		}
		if(pf)cout<<(ans1==0?m:m-1)<<"\n";
		else{
			int ans2=1000000000;
			for(int qqq=0;qqq<(1<<m);qqq++){
				int ansk=0,ansq=0;
				for(int i=1;i<=n;i++){
					for(int j=1;j<=m;j++){
						if(((qqq>>(j-1))&1)==0){
							continue;
						}
						if(l[i]<=mnt[j]&&mnt[j]<=r[i]){
							ansk++;
							break;
						}
					}
				}
				for(int i=0;i<m;i++){
					if(qqq&(1<<i))ansq++;
				}
				if(ansk==ans1){
//					cout<<qqq<<"***";
					ans2=min(ans2,ansq);
				}
			}
			cout<<m-ans2<<endl;
		}
	}
	return 0;
}

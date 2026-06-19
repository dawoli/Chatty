#include<bits/stdc++.h>
using namespace std;
const int N=1e5+1;
int T,n,m,L,V;
int d[N],v[N],a[N],p[N],ans1,ans2;
int c[N][3001];
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout); 
	int i,j;
	cin>>T;
	while(T--){
		int k=0,s,ss;
		memset(c,0,sizeof(c));
		cin>>n>>m>>L>>V;
		for(i=1;i<=n;i++){
			cin>>d[i]>>v[i]>>a[i];
		}
		for(i=1;i<=m;i++){
			cin>>p[i];
		}
		for(i=1;i<=n;i++){
			if(a[i]==0){
				if(v[i]<=V) continue;
				for(j=1;j<=m;j++){
					if(p[j]>=d[i]) c[i][++k]=p[j];
				}
				if(k>0) ans1++;
			}else{
				int usnum=(V*V-v[i]*v[i])/2/a[i];
				if(usnum<0||(usnum==0&&a[i]<0)) continue;
				if(v[i]+a[i]*V<=V) continue;
				if((V*V-v[i]*v[i])%(2*a[i])==0) s=(V*V-v[i]*v[i])/2/a[i];
				else s=(V*V-v[i]*v[i])/2/a[i]+1;
				ss=d[i]+s;
				for(j=1;j<=m;j++){
					if(p[j]>=d[i]&&p[j]<=ss) c[i][++k]=p[j];
				}
				if(k>0) ans1++;
			}
		}
		cout<<ans1<<" "<<ans1<<endl;
	}
	return 0;
}

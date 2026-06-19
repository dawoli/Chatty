#include <bits/stdc++.h>
using namespace std;
int d[100005],v[100005],a[100005],p[100005];
bool vis[100005];
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int T; cin>>T;
	while(T--){
		int n,m,L,V; cin>>n>>m>>L>>V;
		for(int i=1;i<=n;i++){
			cin>>d[i]>>v[i]>>a[i];
		}
		for(int i=1;i<=m;i++){
			cin>>p[i];
		}
		long long ans=0;
		for(int i=1;i<=n;i++){
			if(a[i]==0){
				if(v[i]>V&&d[i]<=p[m]){
					ans++;
				}
			}else{
				int k=ceil((3*3.0-v[i]*v[i])/(2.0*a[i]));
				if(k<=p[m]) ans++;
			}
		}
		cout<<ans<<' '<<m-1<<'\n';
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
int T,n,m,L,V;
int d[10001],v[10001],a[10001],b[10001];
double chaosu[10001][2];
bool f[10001];
bool isc[10001];
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>T;
	int cnt=0;
	int ans;
	while(T--){
		double c;
		cnt=0;
		
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(d,0,sizeof(d));
		memset(v,0,sizeof(v));
		memset(chaosu,0,sizeof(chaosu));
		memset(f,0,sizeof(f));
		memset(isc,0,sizeof(isc));
		
		cin>>n>>m>>L>>V;
		ans=n;
		for(int i=1;i<=n;i++){
			cin>>d[i]>>v[i]>>a[i];
			if(a[i]==0){
				if(v[i]<=V){
					chaosu[i][0]=-1;chaosu[i][1]=-1;
					
				}else if(v[i]>V){
					chaosu[i][0]=d[i];chaosu[i][1]=L;
					ans=n-1;
				}
			}else if(a[i]>0){
				c=(V*V-v[i]*v[i])*1.0/(2*a[i]);
				chaosu[i][0]=c+d[i];chaosu[i][1]=L;
			}else{
				c=(V*V-v[i]*v[i])*1.0/(2*a[i]);
				if(v[i]<=V){
					chaosu[i][0]=-1;chaosu[i][1]=-1;
				}else{
					chaosu[i][0]=d[i];chaosu[i][1]=c+d[i];
					f[i]=1;
				}
			}
		}
		for(int i=1;i<=m;i++){
			cin>>b[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(f[i]==0){
					if(b[j]>=chaosu[i][0]&&b[j]<=chaosu[i][1]){
						isc[i]=1;
					}
				}else{
					if(b[j]>=chaosu[i][0]&&b[j]<chaosu[i][1]){
						isc[i]=1;
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			if(isc[i]){
				cnt++;
			}
		}
		cout<<cnt<<' '<<ans;
		
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

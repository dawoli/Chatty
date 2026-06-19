#include<bits/stdc++.h>
using namespace std;
int t;
int flag;
long long n,m,l,vv;
struct NODE{
	int d,v,a;
}f[1000006];
long long p[1000006];
int cc[35006],ccc[35006];
int cnt,aans,ans;
bool chao[35006][35006];
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>t;
	
	while(t--){
		flag=0;
		memset(f,0,sizeof(f));
		memset(p,0,sizeof(p));
		memset(chao,0,sizeof(chao));
		cin>>n>>m>>l>>vv;
		for(int i=1;i<=n;i++){
			cin>>f[i].d>>f[i].v>>f[i].a;
			if(f[i].a<0){
				flag=1;
			}
		}
		for(int i=1;i<=m;i++){
			cin>>p[i];
		}
		for(int i=1;i<=n;i++){
			cnt=0;
			for(int j=1;j<=m;j++){
				cnt=0;
				if(f[i].d<=p[j]){
					cnt=p[j]-f[i].d;
					if((vv*vv)<(max(0,(f[i].v*f[i].v)+(2*(f[i].a)*cnt)))){
						chao[i][j]=1;
						chao[i][35004]=1;
						cc[i]++;
						ccc[m]++;
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			if(chao[i][35004]){
				aans++;
			}
		}
		if(flag==0){
			if(aans==0){
				ans=m;
			}else{
				ans=m-1;
			}
		}else{
			ans=m/2;
		}
		cout<<aans<<" "<<ans<<endl;
		
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;

const int N=1e4+7;

int d[N],vv[N],a[N],mm[N];

bool is[N][N];

int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		int n,m,l,v;
		cin>>n>>m>>l>>v;
		for(int i=1;i<=n;i++)cin>>d[i]>>vv[i]>>a[i];//v初速度a加速度 
		for(int i=1;i<=m;i++){
			cin>>mm[i];
			for(int j=1;j<=n;j++){
				if(d[i]>mm[i])continue;
				else{
					int sv=(mm[i]-d[i])*a[i]*2+vv[i]*vv[i];
					if(sv>v)is[i][j]=1;
				}
			}
		}
		int ans=0;
		for(int i=1;i<=m;i++){
			for(int j=1;j<=n;j++){
				if(is[i][j]){
					ans++;
					j=n+1;
				}
			}
		}
		cout<<ans<<' '<<m-ans<<'\n';
	}
	return 0;
}

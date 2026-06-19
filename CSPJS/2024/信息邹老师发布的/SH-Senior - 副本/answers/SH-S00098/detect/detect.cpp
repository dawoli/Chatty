#include<bits/stdc++.h>
using namespace std;
struct Car{
	int d,v,a;
}c[100005];
int vis[100005][1005],cars[10005][1005],p[100005],sum,ans;

bool no(int a){
	if(vis[a][0]==0)return 1;
	int flag=0;
	for(int x=1;x<=vis[a][0];x++){//遍历第a个仪能判的车辆 x
		if(cars[vis[a][x]][0]>1){
			flag++;
		}
	}
	if(flag==vis[a][0]){
		return 1;//如果所有车都能被别的仪判那么它没用 
		
	}
	return 0;
}

int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int t;
	cin>>t;
	for(int i=1;i<=t;i++){
		int n,m,l,v;
		cin>>n>>m>>l>>v;
		for(int j=1;j<=n;j++){
			cin>>c[j].d>>c[j].v>>c[j].a;
		}
		for(int j=1;j<=m;j++){
			cin>>p[j];
		}
		for(int j=1;j<=n;j++){
			for(int k=1;k<=m;k++){
				if(p[k]<c[j].d)continue;
				long long v0=c[j].v*c[j].v+2*c[j].a*(p[k]-c[j].d);
				if((v0>(long long)v*v&&c[j].a!=0) || (c[j].v>v&&c[j].a==0)){//如果j车在k处的速度v0超速 
					if(cars[j][0]==0)
						sum++;
					cars[j][++cars[j][0]]=k;//第j辆车被第k个仪判 
					vis[k][++vis[k][0]]=j;//第k个仪判了j 
				}
			}
		}
		cout<<sum<<' ';
		for(int j=1;j<=n;j++){
			if(no(j)){
				vis[j][0]=0;
				ans++;
			}
		}
		cout<<ans;
	}
	return 0;
}

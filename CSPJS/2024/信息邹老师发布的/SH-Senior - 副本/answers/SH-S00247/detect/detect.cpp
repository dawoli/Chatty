#include<bits/stdc++.h>
using namespace std;
int t,n,m,l,vv,dtr[100005],ansa,ansb;
bool vis[100005];
struct car{
	int d;
	int v;
	int a;
}c[100005];
bool gg[5000][5000];
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>t;
	for(int ii=0;ii<t;ii++){
	
		cin>>n>>m>>l>>vv;
		for(int i=0;i<n;i++){
		 
			cin>>c[i].d>>c[i].v>>c[i].a;
		}
		for(int i=0;i<m;i++){
			cin>>dtr[i];
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(dtr[j]<c[i].d)continue;
				if(c[i].v*c[i].v+2*c[i].a*(dtr[j]-c[i].d)<=vv*vv)continue;
				gg[i][j]=1;
			}
		}
		for(int i=0;i<n;i++){
			bool flag=0;
			for(int j=0;j<m;j++){
				if(gg[i][j]){
					flag=1;
					break;
				}
			}
			ansa+=flag;
		}
		while(true){
			int min=100005,mini=-1;
			for(int i=0;i<m;i++){
				int t=0;
				for(int j=0;j<n;j++){
					if(gg[j][i])t++;
					bool can=0;
					for(int k=0;k<m;k++){
						if(gg[j][k]&&k!=i)can=1;
					}
					if(!can||vis[i]){
						t=100006;
						break;
					}
				}
				if(t<min)min=t,mini=i;
			}
			if(mini==-1)break;
			else{
				ansb++;
				vis[mini]=1;
				for(int i=0;i<n;i++){
					gg[i][mini]=0;
				}
			}
		}
		cout<<ansa<<" "<<ansb<<endl;
	}
	return 0;
}

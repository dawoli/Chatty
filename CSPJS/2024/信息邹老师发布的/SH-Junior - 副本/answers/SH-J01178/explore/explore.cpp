#include<bits/stdc++.h>
using namespace std;
int t;
int zoux(int x,int d){
	if(d==2 || d==0){
		return x;
	}
	if(d==3){
		return x-1;
	}if(d==1){
		return x+1;
	}
}
int zouy(int y,int d){
	if(d==1 || d==3){
		return y;
	}
	if(d==2){
		return y-1;
	}if(d==0){
		return y+1;
	}
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>t;
	for(int i=1;i<=t;i++){
		int n,m,k,x,y,d,ans=1;
		char a[1003][1003];
		bool f[1003][1003];
		cin>>n>>m>>k>>x>>y>>d;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				f[i][j]=false;
			}
		}
		f[x][y]=true;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>a[i][j];
			}
		}
		for(int i=1;i<=k;i++){
			int zx=zoux(x,d),zy=zouy(y,d);
//			cout<<zx<<" "<<zy<<" "<<d<<endl;
			if(zx!=0 && zy!=0 && zx<=n &&zy<=m&&a[zx][zy]!='x'){
				if(f[zx][zy]==false)ans++;f[zx][zy]=true;
				x=zx;y=zy;
			}else{
				d++;
				d%=4;
			}
//			cout<<ans<<"\n";
		}
		cout<<ans<<"\n";
	}
	return 0;
}

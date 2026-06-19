#include<bits/stdc++.h>
using namespace std;
bool q(int e,int f,int g,int h[1009][1009]){
	if(g==0){
		if(h[e][f+1]=='.') return true;
		else return false;
	}else if(g==1){
		if(h[e+1][f]=='.') return true;
		else return false;
	}else if(g==2){
		if(h[e][f-1]=='.') return true;
		else return false;
	}else if(g==3){
		if(h[e-1][f]=='.') return true;
		else return false;
	}
}
int t,ans[9];
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		int n,m,k,x,y,d;
		int z[1009][1009];
		bool b[1009][1009];
		cin>>n>>m>>k;
		cin>>x>>y>>d;
		b[x][y]=1;
		for(int j=1;j<=n;j++)
			for(int l=1;l<=m;l++)
				cin>>z[j][l];
		for(int j=1;j<=k;){
			if(q(x,y,d,z)){
				if(d==0){b[x][y+1]=1; y+=1; j++;}
				else if(d==1){b[x+1][y]=1; x+=1; j++;}
				else if(d==2){b[x][y-1]=1; y-=1; j++;}
				else if(d==3){b[x-1][y]=1; x-=1; j++;}
			}else d=(d+1)%4;
		}
		for(int j=1;j<=n;j++)
			for(int l=1;l<=m;l++)
				if(b[j][l]==1) ans[i]++;
	}
	for(int i=1;i<=t;i++) cout<<ans[i]<<endl;
	return 0;
}

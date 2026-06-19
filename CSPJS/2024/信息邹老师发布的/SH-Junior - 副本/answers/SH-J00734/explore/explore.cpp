#include<bits/stdc++.h>
using namespace std;
long long t,n,m,k;
long long xs,ys,ds;
long long a[2000][2000]={};
long long flag[2000][2000]={};
long long ans=0;
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n>>m>>k;
		cin>>xs>>ys>>ds;
		ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				flag[i][j]=0;
			}	
		}
		for(int i=1;i<=n;i++){
			char str[2000]={};
			cin>>str;
			for(int j=0;j<m;j++){
				if(str[j]=='x'){
					a[i][j+1]=0;
				}else{
					a[i][j+1]=1;
				}
			}
		}
		long long x,y,d;
		long long xdis,ydis;
		x=xs;y=ys;d=ds;
		k=k+1;
		while(k--){
			flag[x][y]++;
			if(d==0){
				xdis=0;
				ydis=1;
			}else if(d==1){
				xdis=1;
				ydis=0;
			}else if(d==2){
				xdis=0;
				ydis=-1;
			}else if(d==3){
				xdis=-1;
				ydis=0;
			}
			if(a[x+xdis][y+ydis]==0){
				d=(d+1)%4;
			}else if(a[x+xdis][y+ydis]==1){
				x=x+xdis;
				y=y+ydis;
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(flag[i][j]>0){
					ans++;
				}
			}	
		}
		cout<<ans<<endl;
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
int T,n,m,k,x,y,d;
char ch[1009][1009];
bool vst[1009][1009];
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>T;
	for(int a=1;a<=T;a++){
		int ans=1;
		cin>>n>>m>>k; 
		cin>>x>>y>>d;
		vst[x][y]=1;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				cin>>ch[i][j];
				
		while(k--){
			
			if(d==0)
				if(d==0&&ch[x][y+1]=='.'){
					if(!vst[x][y+1]) ans++;
					y++,vst[x][y]=1;
				}
				else d=(d+1)%4;
				
			else if(d==1)
				if(d==1&&ch[x+1][y]=='.'){
					
					if(!vst[x+1][y]) ans++;
					x++,vst[x][y]=1;
				}
				else d=(d+1)%4;
				
			else if(d==2)
				if(d==2&&ch[x][y-1]=='.'){
					
					if(!vst[x][y-1]) ans++;
					y--,vst[x][y]=1;
				}
				else d=(d+1)%4;
				
			else
				if(d==3&&ch[x-1][y]=='.'){
					
					if(!vst[x-1][y]) ans++;
					x--,vst[x][y]=1;
				}
				else d=(d+1)%4;
		}
		
		cout<<ans<<endl;
		for(int i=0;i<=n;i++)
			for(int j=0;j<=m;j++)
				vst[i][j]=0;
	}
	return 0;
}

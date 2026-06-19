#include<bits/stdc++.h>
using namespace std;
char ex[1005][1005];
string s[1005];
int n,m,k;
int x,y,d;
int pasx,pasy;
int nextposx(int d,int x){
	if(d==1) return x+1;
	if(d==3) return x-1;
	return x;
}
int nextposy(int d,int y){
	if(d==0) return y+1;
	if(d==2) return y-1;
	return y;
}
int main(){
	//freopen("explore.in","r",stdin);
	//freopen("explore.out","w",stdout);
	int T;
	scanf("%d",&T);
	int ans=1; 
	while(T--){
		ans=1;
		scanf("%d%d%d",&n,&m,&k);
		scanf("%d%d%d",&x,&y,&d);
		for(int i=1;i<=n;i++){
			cin>>s[i];
			for(int j=1;j<=m;j++){
				ex[i][j]=s[i][j];
			}
		}
		
		ex[x][y]='0';
		pasx=x;
		pasy=y; 
		for(int i=1;i<=k;i++){
			pasx=x;
			pasy=y;
			x=nextposx(d,pasx);
			y=nextposy(d,pasy);
			if(x>=1&&x<=n&&y>=1&&y<=m&&ex[x][y]!='x'){
				if(ex[x][y]!='0'){
					ex[x][y]='0';
					ans++;
				}
			}else{
				x=pasx;
				y=pasy;
				d=(d+1)%4;
				
			}
		
			
		}
		cout<<ans<<endl;
	}
	
	return 0;
}

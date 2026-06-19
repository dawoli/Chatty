#include<bits/stdc++.h>
using namespace std;

int T;
int n,m,k;
int sx,sy,d;
bool mp[1009][1009];
bool vis[1009][1009];

signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>T;
	while(T--){
		//cout<<"T="<<T<"\n";
		int ans=0;
		//PART1 输入并转换为01布尔数组 
		cin>>n>>m>>k;
		cin>>sx>>sy>>d;
		for(int i=0;i<=n+1;i++)for(int j=0;j<=m+1;j++){
			mp[i][j]=1;
			vis[i][j]=0;
		}
		
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				char c;
				cin>>c;
				if(c=='x')mp[i][j]=1;
				else mp[i][j]=0;
			}
		}
		int x=sx,y=sy;
		//cerr<<"k="<<k<<"\n";
		for(int jsq=1;jsq<=k;jsq++){
			 
			if(not vis[x][y])ans++;
			vis[x][y]=true;
			
			int xp,yp;
			if(d==0)xp=x,yp=y+1;
			if(d==1)xp=x+1,yp=y;
			if(d==2)xp=x,yp=y-1;
			if(d==3)xp=x-1,yp=y;
			//cerr<<"第"<<jsq<<"次: ("<<x<<","<<y<<") 当前朝向:"<<d<<" 目标位置("<<xp<<","<<yp<<")\n";
			if(mp[xp][yp]){
				d=(d+1)%4;
			}else{
				x=xp;
				y=yp;
			}
		}
		if(not vis[x][y])ans++;
		cout<<ans<<"\n";
	}
}
/*
82
242578
1684
20226
164


*/

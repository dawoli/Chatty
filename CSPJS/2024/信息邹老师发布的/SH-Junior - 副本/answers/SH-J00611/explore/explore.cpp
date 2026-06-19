#include<bits/stdc++.h>
using namespace std;
bool mp[1010][1010],an[1010][1010];
long long ans=0,x,y,n,m,k,t,d;
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>t;
	while(t--){
		ans=1;
		cin>>n>>m>>k;
		cin>>x>>y>>d;
		for(int i=1;i<=n;i++){
			string a;
			cin>>a;
			for(int j=0;j<m;j++){
				if(a[j]=='.')mp[i][j+1]=true;
				if(a[j]=='x')mp[i][j+1]=false;
				an[i][j+1]=false;
			}
		}
//for(int i=1;i<=1010;i++){
//	for(int j=1;j<=1010;j++){
//		an[i][j]=false;
//	}
//}
		//mp[x][y]=false;
		an[x][y]=true;
		for(int i=1;i<=k;i++){
			if(d==0){
				if(y+1<=m&&mp[x][y+1]){
					y++;
					if(!an[x][y]){
						ans++;
						an[x][y]=true;
					} 
				}
				else d=(d+1)%4;
			}
			else if(d==1){
				if(x+1<=n&&mp[x+1][y]){
					x++;
					if(!an[x][y]){
						ans++;
						an[x][y]=true;
					} 
				}
				else d=(d+1)%4;
			}
			else if(d==2){
				if(y-1>=1&&mp[x][y-1]){
					y--;
					if(!an[x][y]){
						ans++;
						an[x][y]=true;
					} 
				}
				else d=(d+1)%4;
			}
			else if(d==3){
				if(x-1>=1&&mp[x-1][y]){
					x--;
					if(!an[x][y]){
						ans++;
						an[x][y]=true;
					} 
				}
				else d=(d+1)%4;
			}
			//mp[x][y]=false;
			//cout<<x<<" "<<y<<" "<<d<<endl;
			//cout<<ans<<endl;
		}
		cout<<ans<<endl;
	}
	return 0;
}
/*
2
1 5 4
1 1 2
....x
5 5 20
1 1 0
.....
.xxx.
.x.x.
..xx.
x....
*/

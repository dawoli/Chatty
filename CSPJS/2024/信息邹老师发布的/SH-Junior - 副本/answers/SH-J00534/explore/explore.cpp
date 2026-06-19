#include<bits/stdc++.h>
using namespace std;
int n,m,k,t,d,x,y,a[1009][1009],b[1000001],jishu=0,close,open;
string dian;
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>t;
	for(int i=0;i<t;i++){
		cin>>n>>m>>k;
		cin>>x>>y>>d;
		for(int j=1;j<=n;j++){
			cin>>dian;
			for(int z=0;z<m;z++){
				if(dian[z]=='.') a[j][z+1]=1;
				else a[j][z+1]=0;
			}
		}
		for(int j=0;j<k;j++){
			close=1;
			if(d==0){
				if(a[x][y+1]){
					y++;
					for(int z=0;z<jishu;z++){
					if(x*10000+y==b[z]){
						close=0;
						break;
						}
					}
					if(close) b[jishu++]=x*10000+y;
				}
				else d=(d+1)%4;
			}else if(d==1){
				if(a[x+1][y]){
					x++;
					for(int z=0;z<jishu;z++){
					if(x*10000+y==b[z]){
						close=0;
						break;
						}
					}
					if(close) b[jishu++]=x*10000+y;
				}
				else d=(d+1)%4;
			}else if(d==2){
				if(a[x][y-1]){
					y--;
					for(int z=0;z<jishu;z++){
					if(x*10000+y==b[z]){
						close=0;
						break;
						}
					}
					if(close) b[jishu++]=x*10000+y;
				}
				else d=(d+1)%4;
			}else{
				if(a[x-1][y]){
					x--;
					for(int z=0;z<jishu;z++){
					if(x*10000+y==b[z]){
						close=0;
						break;
						}
					}
					if(close) b[jishu++]=x*10000+y;
				}
				else d=(d+1)%4;
			}
		}
		cout<<jishu+1<<endl;
		jishu=0;
	}
	return 0;
}

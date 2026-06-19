#include<bits/stdc++.h>
using namespace std;
int tt,nn,mm,kk,xx,yy,dd;
char mapa[1100][1100];
bool vis[1100][1100];
long long anss;
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>tt;
	for(int ii=1;ii<=tt;ii++){
		anss=1;
		cin>>nn>>mm>>kk;
		cin>>xx>>yy>>dd;
		dd=dd%4;
		for(int i=1;i<=nn;i++){
			for(int j=1;j<=mm;j++){
				cin>>mapa[i][j];
				vis[i][j]=false;
			}
		}
		vis[xx][yy]=true;
		for(int i=1;i<=kk;i++){
			if(dd==0){
				if(xx>=1&&xx<=nn&&(yy+1)>=1&&(yy+1)<=mm&&mapa[xx][yy+1]!='x'){
					anss++;
					yy++;
					if(vis[xx][yy]==true){
						anss--;
					}
					vis[xx][yy]=true;
				}
				else{
					dd=(dd+1)%4;
					continue;
				}
			}
			else if(dd==1){
				if((xx+1)>=1&&(xx+1)<=nn&&yy>=1&&yy<=mm&&mapa[xx+1][yy]!='x'){
					anss++;
					xx++;
					if(vis[xx][yy]==true){
						anss--;
					}
					vis[xx][yy]=true;
				}
				else{
					dd=(dd+1)%4;
					continue;
				}
			}
			else if(dd==2){
				if(xx>=1&&xx<=nn&&(yy-1)>=1&&(yy-1)<=mm&&mapa[xx][yy-1]!='x'){
					anss++;
					yy--;
					if(vis[xx][yy]==true){
						anss--;
					}
					vis[xx][yy]=true;
				}
				else{
					dd=(dd+1)%4;
					continue;
				}
			}
			else if(dd==3){
				if((xx-1)>=1&&(xx-1)<=nn&&yy>=1&&yy<=mm&&mapa[xx-1][yy]!='x'){
					anss++;
					xx--;
					if(vis[xx][yy]==true){
						anss--;
					}
					vis[xx][yy]=true;
				}
				else{
					dd=(dd+1)%4;
					continue;
				}
			}
		}
		cout<<anss<<endl;
	}
	return 0;
}
